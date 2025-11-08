#include "game_preferences.h"
#include "high_scores.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

struct input_args
{
  unsigned int max_number_value;
  bool table;  
};

/*
Добавить обработку параметра командной строки “-max” с одним числовым аргументом, с
помощью которого можно задать максимальное значения для загаданного числа.

Добавить обработку параметра командной строки “-table” без аргументов, с помощью которого
можно вывести таблицу рекордов сразу, без необходимости игры.

Добавить обработку параметра командной строки ”-level” с одним аргументом численного типа,
через который можно задать уровень сложности
*/
void
parse_args(int argc, char **argv, input_args &in_args) {
  
  const int first_arg_pos = 1;
  if (argc <= first_arg_pos) {
    std::cout << "Used default settings!\n";
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
    bool is_next_value = true;

    if (is_arg == NOT_ARG) {
      // Детектирование -max и -level
      if (argv_value == "-max" || argv_value == "-level") {
        if (i + 1 == argc) {
          is_next_value = false;
        }
        if (argv_value == "-max") {
          is_arg = IS_MAX;
          continue;
        } else if (argv_value == "-level") {
          is_arg = IS_LEVEL;
          continue;
        }
      }
      // Детектирование -table
      if (argv_value == "-table" && is_arg == NOT_ARG) {
        in_args.table = true;
        return;
      }
    }

    switch (is_arg)
    {
      case IS_MAX: {
        if (is_next_value) {
          unsigned int value = std::atoi(argv[i]);
          if (value > 0) {
            in_args.max_number_value = value;
            std::cout << "Using " << value << " as max value...\n";
            is_arg = NOT_ARG;
            break;
          }
        }
        std::cout << "Wrong value! Argument \"-max\" must have a positive digit value!\n";
        std::cout << "Used default settings for \"max\" value!\n";
        is_arg = NOT_ARG;
        break;
      }

      case IS_LEVEL: {
        if (is_next_value) {
          unsigned int value = std::atoi(argv[i]);
          bool is_new_max_value = true;
          if (value > 0) {
            switch (value) {
              case 1:
                in_args.max_number_value = 10;
                break;
              
              case 2:
                in_args.max_number_value = 50;
                break;

              case 3:
                in_args.max_number_value = 100;
                break;
                
              default:
                is_new_max_value = false;
                break;
            }
            if (is_new_max_value) {
              std::cout << "Using " << in_args.max_number_value << " as max value...\n";
              is_arg = NOT_ARG;
              break;
            }
          }
        }
        std::cout << "Wrong value! Argument \"-level\" must be in [1, ..., 3]!\n";
        std::cout << "Used default settings for \"-level\" value!\n";
        is_arg = NOT_ARG;
        break;
      }
      
      default:
        std::cout << "Wrong input value: " << argv_value << "!\n";
        break;
    }
  }
}

/*
Для реализации таблицы рекордов пользователю при старте приложения выводится предложение
представиться. 
*/
std::string
get_player_name() {
  std::cout << "Enter your name: ";
  std::string player_name {};
  std::cin >> player_name;
  std::cin.ignore();
  return player_name;
}

/*
Для того, чтобы игра была более интересной, в приложении стоит использовать генератор
случайных чисел вместо «угадывания» константы.
*/
unsigned int
get_target_value(unsigned int max_value) {
  std::srand(std::time(nullptr));
  return static_cast<unsigned int>(std::rand() % max_value);
}

/*
Приложение «загадывает» некоторое число и ждёт в цикле ввода от пользователя. В
случае, если пользователь ввёл число, меньшее загаданного, выводится подсказка «less than». В
случае, если пользователь ввёл число, большее заданного, выводится подсказка «greater than». В
случае, когда пользователь, наконец, угадывает число, выводится сообщение «you win!», и цикл
ввода завершается
*/
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

/*
Игра «угадай число» - компьютер загадывает число, пользователь пытается угадать. При этом
подсчитывается количество попыток и формируется таблица рекордов.
*/
int
main(int argc, char **argv) {
  input_args in_args {.max_number_value = 100, .table = false};
  parse_args(argc, argv, in_args);

  // Настройки по умолчанию
  game_preferences game_prefs {
    .player_name = {},
    .high_scores_filename = "high_scores.txt", 
    .target_value = get_target_value(in_args.max_number_value),
    .max_value = in_args.max_number_value,
    .nof_attempts = 0
  }; 

  // Если был передан аргумент table, выводится таблица рекордов и программа завершается
  // Таблица рекордов выводится двумя способами: полная, и отфильтрованная по минимальным результатам игроков
  if (in_args.table) {
    high_scores_output(game_prefs);
    high_scores_output_filtered_min(game_prefs);
    return 0;
  }
  
  std::cout << "The game begins...\n\n";

  game_prefs.player_name = get_player_name();
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