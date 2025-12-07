#include <iostream>
#include <string>

void
print_half_whitespaces(int count) {
  const std::string whitespace_char{"."};
  
  for (int i = 0; i < count; ++i)
  {
    std::cout << whitespace_char;
  }
}

int
main () {
  const std::string star_char{"*"};

  int height;
  std::cin >> height;

  for (int i = 0; i < height; ++i)
  {
    print_half_whitespaces(height - i);

    for (int k = 0; k <= i * 2; ++k) {
      std::cout << star_char;
    }
    
    print_half_whitespaces(height - i);

    std::cout << std::endl;
  }
}