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
    return out;
}

bool Circle::withinRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
{
    if (this->getX() + this->radius > x + width ||
        this->getX() - this->radius < x ||
        this->getY() + this->radius > y + height ||
        this->getY() - this->radius < y)
    {
        return false;
    }
    return true;
}

bool Circle::withinCircle(unsigned int cx, unsigned int cy, unsigned int r) const
{
    double distanceBetweenCenters = distance(this->getX(), this->getY(), cx, cy);
    if (distanceBetweenCenters + r == this->radius ||
        distanceBetweenCenters + r < this->radius)
        return true;
    return false;
}

void Circle::print() const
{
    std::cout << "circle " << this->getX() << " " << this->getY() << " " << this->radius << " " << this->getColour() << std::endl;
}