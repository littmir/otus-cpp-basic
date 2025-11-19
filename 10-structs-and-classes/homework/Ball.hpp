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
    Point center;
    double radius;
    Velocity velocity;
    Color color;
    bool isCollidable;

};
