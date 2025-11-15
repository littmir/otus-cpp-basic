#include "02_methods.hpp"
#include <iostream>
#include <string>

namespace motivation {

    std::string toString(const Point& point) {
        return "{" + std::to_string(point.x) + ", " + std::to_string(point.y) + "}";
    }

    void example() {
        Point point;

        point.x = 3;
        point.y = 5;

        std::cout << toString(point) << std::endl;
    }
} // namespace motivation

namespace methods {
    // Say: "::"
    // Определение
    std::string Point::toString() { return "{" + std::to_string(x) + ", " + std::to_string(y) + "}"; }

    void example() {
        std::cout << "*** methods::example ***" << std::endl;

        // Say: const Point (toString)
        Point point;
        point.x = 3;
        point.y = 5;

        std::cout << point.toString() << std::endl;
    }
} // namespace methods

int main() {
    motivation::example();
    methods::example();
}
