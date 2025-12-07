#include <iostream>
#include <string>

struct Point {
    // Say: below
    int x;
    int y;
    // Point() {}
    //  Say: syntax, this
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    std::string toString() const { return "{" + std::to_string(x) + ", " + std::to_string(y) + "}"; }
};

namespace two_args_constructor {
    void example() {
        Point point(3, 3);
        Point point1 = {3, 5};
        Point point2 = Point{3, 5};
        std::cout << point.toString() << std::endl;

        // Point p; // what?
    }
} // namespace two_args_constructor

namespace default_constructor {
    struct Point {
        int x;
        int y;

        Point() = default;
        Point(int x, int y) : x(x), y(x) {}

        std::string toString() const { return "{" + std::to_string(x) + ", " + std::to_string(y) + "}"; }
    };

    void example() {
        Point p;
        std::cout << p.toString() << "\t" << Point(3, 5).toString() << std::endl;
    }
} // namespace default_constructor

int main() {
    two_args_constructor::example();
    default_constructor::example();
}