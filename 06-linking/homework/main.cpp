#include <ctime>
#include <iostream>
#include <string>

struct input_args
{
  unsigned int max_number_value;
  int level;
  bool table;  
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

int
main(int argc, char **argv) {
  input_args in_args {.max_number_value = 100, .level = 0, .table = false};
  parse_args(argc, argv, in_args);

  return 0;
}