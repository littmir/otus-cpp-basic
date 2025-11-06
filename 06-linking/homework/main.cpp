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
    
    if (argv_value == "-max") {
      is_arg = IS_MAX;
      continue;
    } else if (argv_value == "-level") {
      is_arg = IS_LEVEL;
    } else if (argv_value == "-table") {
      is_arg = IS_TABLE;
    }

    switch (is_arg)
    {
      case IS_MAX: {
        auto value = std::stoi(argv[i]);
        if (value > 0) {
          in_args.max_number_value = value;
        }
        is_arg = NOT_ARG;
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