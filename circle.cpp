#include <iostream>
#include "circle.hpp"

std::istream &operator>>(std::istream &in, Circle &circle);
std::ostream &operator<<(std::ostream &out, const Circle &circle)
{
    out << "<circle cx=\"" << circle.getX() << "\" cy=\"" << circle.getY() << "\" r=\"" << circle.getRadius() << "\" fill=\"" << circle.getColour() << "\" />" << std::endl;
}

bool Circle::withinRectangle(const Rectangle &rectangle) const
{
    if (this->getX() + this->radius > rectangle.getX() + rectangle.getWidth() ||
        this->getX() - this->radius < rectangle.getX() ||
        this->getY() + this->radius > rectangle.getY() + rectangle.getHeight() ||
        this->getY() - this->radius < rectangle.getY())
    {
        return false;
    }
    return true;
}

bool Circle::withinCircle(const Circle &circle) const
{
    double distanceBetweenCenters = distance(this->getX(), this->getY(), circle.getX(), circle.getY());
    if (distanceBetweenCenters + circle.radius == this->radius ||
        distanceBetweenCenters + circle.radius < this->radius)
        return true;
    return false;
}

void Circle::print() const
{
    std::cout << "circle " << this->getX() << " " << this->getY() << " " << this->radius << " " << this->getColour() << std::endl;
}