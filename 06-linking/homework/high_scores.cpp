#include "game_preferences.h"

#include <fstream>
#include <iostream>

void
high_scores_ouput(game_preferences &game_prefs) {
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

  high_scores_ouput(game_prefs);
}