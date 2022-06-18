#include <iostream>
#include "circle.hpp"

std::istream &operator>>(std::istream &in, Circle &circle)
{
    String data;
    in >> data;
    unsigned int x = data.findIntValue("cx=\"");
    unsigned int y = data.findIntValue("cy=\"");
    unsigned int radius = data.findIntValue("r=\"");
    String colour = data.findValue("fill=\"");
    circle = Circle(x, y, colour, radius);
    return in;
}

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