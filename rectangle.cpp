#include <iostream>
#include "rectangle.hpp"

std::istream &operator>>(std::istream &in, Rectangle &rectangle);
std::ostream &operator<<(std::ostream &out, const Rectangle &rectangle)
{
}

bool Rectangle::withinRectangle(const Rectangle &rectangle) const
{
    if (this->getX() <= rectangle.getX() && this->getY() <= rectangle.getY() && this->getX() + this->width >= rectangle.getX() + rectangle.width && this->getY() + this->height >= rectangle.getY() + rectangle.height)
        return true;

    return false;
}
bool Rectangle::withinCircle(const Circle &circle) const
{
    if (distance(this->getX(), this->getY(), circle.getX(), circle.getY()) < circle.getRadius() &&
        distance(this->getX() + this->width, this->getY(), circle.getX(), circle.getY()) < circle.getRadius() &&
        distance(this->getX(), this->getY() + this->height, circle.getX(), circle.getY()) < circle.getRadius() &&
        distance(this->getX() + this->width, this->getY() + this->height, circle.getX(), circle.getY()) < circle.getRadius())
        return true;

    return false;
}
void Rectangle::print() const
{
    std::cout << "rectangle " << this->getX() << " " << this->getY() << this->width << " " << this->height << " " << this->getColour() << std::endl;
}