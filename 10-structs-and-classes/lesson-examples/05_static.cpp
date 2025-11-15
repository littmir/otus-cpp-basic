#include "05_static.h"
#include <iostream>

int Counter::count = 0;

Counter::Counter() { ++count; }

Counter::~Counter() { --count; }

void example() {
    {
        std::cout << Counter::count << std::endl;
        Counter a;
        std::cout << Counter::count << std::endl;
        Counter b;
        std::cout << Counter::count << std::endl;
    }
    std::cout << Counter::count << std::endl;
}

int main() { example(); }