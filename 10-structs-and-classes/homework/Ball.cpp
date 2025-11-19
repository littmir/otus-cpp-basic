#include "Ball.hpp"
#include <cmath>

Ball::Ball(Point center, double radius, Velocity velocity, Color color, bool isCollidable) 
    : center(center), radius(radius), velocity(velocity), color(color), isCollidable(isCollidable) {

}

std::istream& operator>>(std::istream& is, Ball &ball) {
  Point center;
  double radius;
  Point velocity;
  Color color;
  bool isCollidable;

  if (is >> center >> velocity >> color >> radius
        >> std::boolalpha >> isCollidable) {
    ball.center = center;
    ball.radius = radius;
    ball.velocity = velocity;
    ball.color = color;
    ball.isCollidable = isCollidable;
  }

  return is;
};

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    this->velocity = velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    return velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    painter.draw(center, radius, color);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    this->center = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    return center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    return radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
    return M_PI * (pow(radius, 3)) * 4. /  3.;
}

bool Ball::getCollidability() const {
    return isCollidable;
}
