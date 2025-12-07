#include <iostream>
#include <string>

void
print_half_whitespaces(int count) {
  const std::string whitespace_char{"."};
  
  for (int i = 0; i < count; ++i) {
    std::cout << whitespace_char;
  }
}

void
print_stars(int count) {
  const std::string star_char{"*"};
  
  for (int i = 0; i < count; ++i) {
    std::cout << star_char;
  }
}

int
main() {
  int height;
  std::cin >> height;

  for (int i = 1; i <= height; ++i) {
    print_half_whitespaces(height - i);
    print_stars(i);
    std::cout << std::endl;
  }

  for (int i = height - 1; i >= 1; --i) {
    print_half_whitespaces(height - i);
    print_stars(i);
    std::cout << std::endl;
  }
}