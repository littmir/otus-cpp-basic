#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

#include <istream>

class Ball
{
public:
    Ball() = default;
    Ball(Point center, double radius, Velocity velocity, Color color, bool isCollidable);
    
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool getCollidability() const;

    friend std::istream& operator>>(std::istream& is, Ball &ball);

private:
    Point center{0, 0};
    double radius{0};
    Velocity velocity{Point(0, 0)};
    Color color{0, 0, 0};
    bool isCollidable{false};
    double mass{0};

    void calcMass();
};
