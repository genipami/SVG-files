#include <iostream>
#include "line.hpp"
#include "shape.hpp"

std::istream &operator>>(std::istream &in, Line &line);
std::ostream &operator<<(std::ostream &out, const Line &line);
bool pointIsWithinRectangle(int x, int y, const Rectangle &rectangle)
{
    if (x >= rectangle.getX() &&
        x <= rectangle.getX() + rectangle.getWidth() &&
        y >= rectangle.getY() &&
        y <= rectangle.getY() + rectangle.getHeight())
        return true;
    return false;
}

bool pointIsWithinCircle(int x, int y, const Circle &circle)
{
    if (distance(x, y, circle.getX(), circle.getY()) <= circle.getRadius())
        return true;
    return false;
}
bool Line::withinRectangle(const Rectangle &rectangle) const
{
    if (pointIsWithinRectangle(this->getX(), this->getY(), rectangle) &&
        pointIsWithinRectangle(this->endX, this->endY, rectangle))
        return true;
    return false;
}
bool Line::withinCircle(const Circle &circle) const
{
    if (pointIsWithinCircle(this->getX(), this->getY(), circle) &&
        pointIsWithinCircle(this->endX, this->endY, circle))
        return true;
    return false;
}
void Line::print() const
{
    std::cout << "line " << this->getX() << " " << this->getY() << " " << this->endX << " " << this->endY << " " << getColour() << std::endl;
}