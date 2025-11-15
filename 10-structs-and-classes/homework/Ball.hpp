#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball
{
public:
    Ball(Point center, double radius, Velocity velocity, Color color, bool isCollidable);
    
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;

private:
    Point center;
    double radius;
    Velocity velocity;
    Color color;
    bool isCollidable;

};
