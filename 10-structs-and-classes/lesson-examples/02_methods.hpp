#pragma once
#include <string>

namespace motivation {
    // declaration
    struct Point;

    // Say: uncompleted
    std::string toString(const Point& point);

    struct Point {
        int x;
        int y;
    };
    // Say: completed
} // namespace motivation

namespace methods {
    struct Point {
        int x;
        int y;

        // Объявление
        std::string toString();
        // std::string toString() const;
    };
} // namespace methods
