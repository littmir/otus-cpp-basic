#pragma once
#include "Point.hpp"

#include <istream>

class Velocity {
  public:
    Velocity() = default;

    Velocity(const Point& vector) {
        setVector(vector);
    }

    friend std::istream& operator>>(std::istream& is, Velocity &vector) {
      is >> vector.vec;
      return is;
    }

    void setVector(const Point& vector) {
        vec = vector;
    }

    Point vector() const {
        return vec;
    }

  private:
    Point vec;
};
