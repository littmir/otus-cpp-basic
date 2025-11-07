#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

struct input_args
{
  unsigned int max_number_value;
  int level;
  bool table;  
};

struct game_preferences
{
  std::string player_name;
  std::string high_scores_filename;
  unsigned int target_value;
  unsigned int max_value; 
  unsigned int nof_attempts;
};

void
parse_args(int argc, char **argv, input_args &in_args) {
  
  const int first_arg_pos = 1;
  if (argc <= first_arg_pos) {
    return;
  }

  enum arg {
    IS_MAX,
    IS_LEVEL,
    IS_TABLE,
    NOT_ARG
  } is_arg {NOT_ARG};
  
  for (int i = first_arg_pos; i < argc; ++i) {
    
    std::string argv_value = argv[i];
    bool is_value_fo_max = true;
    
    if (argv_value == "-max" && is_arg == NOT_ARG) {
      is_arg = IS_MAX;
      if (i + 1 == argc) {
        is_value_fo_max = false;
      } else {
        continue;
      }
    }
    if (argv_value == "-level" && is_arg == NOT_ARG) {
      is_arg = IS_LEVEL;
    }
    if (argv_value == "-table" && is_arg == NOT_ARG) {
      is_arg = IS_TABLE;
    }

    switch (is_arg)
    {
      case IS_MAX: {
        if (is_value_fo_max) {
          unsigned int value = std::atoi(argv[i]);
          if (value > 0) {
            in_args.max_number_value = value;
            std::cout << "Using " << value << " as max value...\n";
            is_arg = NOT_ARG;
            break;
          }
        }
        std::cout << "Wrong value! Argument \"-max\" must have a positive digit value!\n";
        std::cout << "Used default settings for max value!\n";
        break;
      }

      case IS_LEVEL:
        is_arg = NOT_ARG;
        break;
    
      case IS_TABLE:
        is_arg = NOT_ARG;
        break;
      
        default:
          std::cout << "Wrong input value: " << argv_value << "!\n";
        break;
    }
  }
}

std::string
get_player_name() {
  std::cout << "Enter your name: ";
  std::string player_name {};
  std::cin >> player_name;
  std::cin.ignore();
  return player_name;
}

unsigned int
get_target_value(unsigned int max_value) {
  std::srand(std::time(nullptr));
  return static_cast<unsigned int>(std::rand() % max_value);
}

bool
get_and_check_value(unsigned int target_value) {
  int guess_value {};
  std::cin >> guess_value;
  
  if (std::cin.fail()) {
    std::cout << "Wrong value! Try again... \n";
    std::cin.clear();
  } else if (guess_value < 0) {
    std::cout << "Please, enter a positive value...\n";
  } else if (guess_value > target_value) {
    std::cout << "Less than " << guess_value << ", try again: ";
  } else if (guess_value < target_value) {
      std::cout << "Greater than " << guess_value << ", try again: ";
  } else {
    return true;
  }
  
  std::cin.ignore();
  return false;
}

void process_high_score(game_preferences &game_prefs) {
  std::ofstream output_file{game_prefs.high_scores_filename, std::ios_base::app};
  if (!output_file.is_open()) {
    std::cout << "Failed to open file for write: " << game_prefs.high_scores_filename << "!\n";
      return;
  }

  output_file << game_prefs.player_name << ' ';
  output_file << game_prefs.nof_attempts;
  output_file << "\n";
  output_file.close();

  std::ifstream input_file{game_prefs.high_scores_filename, std::ios_base::in};
  if (!input_file.is_open()) {
   std::cout << "Failed to open file for read: " << game_prefs.high_scores_filename << "!\n";
   return;
  }

  std::cout << "High scores table: \n";
  std::cout << "Player_name "<< '\t' << "High_score";
  std::string player_name;
  int high_score = 0;
  while (true) {
   input_file >> player_name;
   input_file >> high_score;
   input_file.ignore();
   if (input_file.fail()) {
    break;
   }

   std::cout << "\n" << player_name << '\t' << high_score;
  }
  std::cout << " <-- is you :)\n";
  input_file.close();
}

int
main(int argc, char **argv) {
  input_args in_args {.max_number_value = 100, .level = 0, .table = false};
  parse_args(argc, argv, in_args);
  
  std::cout << "The game begins...\n\n";
  game_preferences game_prefs; 
  game_prefs.high_scores_filename = "high_scores.txt";
  game_prefs.player_name = get_player_name();
  game_prefs.target_value = get_target_value(in_args.max_number_value);
  game_prefs.max_value = in_args.max_number_value;
  game_prefs.nof_attempts = 0;

  std::cout << "Hello, " << game_prefs.player_name << "!\n";
  std::cout << "You should guess the number in [0, ..., " << game_prefs.max_value << "]\n";
  std::cout << "Please, enter your guess: ";

	while (true) {
	  bool is_win = get_and_check_value(game_prefs.target_value);
    game_prefs.nof_attempts += 1;
    if (is_win) {
      std::cout << "You won! " << "Attempts = " << game_prefs.nof_attempts << "\n";
      break;
    }
  }

  process_high_score(game_prefs);

  return 0;
}