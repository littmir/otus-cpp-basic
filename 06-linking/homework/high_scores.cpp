#include "game_preferences.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

void
high_scores_output(game_preferences &game_prefs) {
  std::ifstream input_file{game_prefs.high_scores_filename, std::ios_base::in};
  if (!input_file.is_open()) {
   std::cout << "Failed to open file for read: " << game_prefs.high_scores_filename << "!\n";
   return;
  }

  std::cout << "High scores table: \n";
  std::cout << "Player_name "<< '\t' << "High_score";
  std::string player_name {};
  int high_score = 0;
  while (true) {
   input_file >> player_name;
   input_file >> high_score;
   input_file.ignore();
   if (input_file.fail()) {
    break;
   }

   std::cout << "\n" << player_name << '\t' << high_score;
   if (player_name == game_prefs.player_name) {
      std::cout << " <-- is you :)";
   }
  }
  std::cout << "\n";
  input_file.close();
}

/*
При чтении таблицы рекордов для каждого пользователя определять минимальное значение числа
попыток и выводить только их.
*/
void
high_scores_output_filtered_min(game_preferences &game_prefs) {
  std::ifstream input_file{game_prefs.high_scores_filename, std::ios_base::in};
  if (!input_file.is_open()) {
   std::cout << "Failed to open file for read: " << game_prefs.high_scores_filename << "!\n";
   return;
  }

  std::vector<std::string> players_names {};
  std::vector<unsigned int> scores {};
  
  std::string player_name {};
  unsigned int score = 0;

  std::cout << "High scores table: \n";
  std::cout << "Player_name "<< '\t' << "High_score";
  while (true) {
    input_file >> player_name;
    players_names.push_back(player_name);
    input_file >> score;
    input_file.ignore();
    scores.push_back(score);
    if (input_file.fail()) {
      break;
    }
  }

  std::vector<unsigned int> idx_to_erase {};
  for (int i = 0; i < players_names.size() - 1; ++i) {
    for (int j = i + 1; j < players_names.size(); ++j) {
      if (players_names.at(i) == players_names.at(j)) {
        scores.at(i) = std::min(scores.at(i), scores.at(j));
        idx_to_erase.push_back(j);
      }
    }
    for (int k = idx_to_erase.size() - 1; k >= 0; --k) {
      players_names.erase(players_names.begin() + idx_to_erase.at(k));
      scores.erase(scores.begin() + idx_to_erase.at(k)); 
      idx_to_erase.erase(idx_to_erase.begin() + k);
    }

    std::cout << "\n" << players_names.at(i) << '\t' << scores.at(i);
    if (players_names.at(i) == game_prefs.player_name) {
      std::cout << " <-- is you :)";
    }
  }
  std::cout << "\n";
  input_file.close();
}

void
process_high_score(game_preferences &game_prefs) {
  std::ofstream output_file{game_prefs.high_scores_filename, std::ios_base::app};
  if (!output_file.is_open()) {
    std::cout << "Failed to open file for write: " << game_prefs.high_scores_filename << "!\n";
      return;
  }

  output_file << game_prefs.player_name << ' ';
  output_file << game_prefs.nof_attempts;
  output_file << "\n";
  output_file.close();

  high_scores_output(game_prefs);
  high_scores_output_filtered_min(game_prefs);
}