#include <iostream>
#include "rectangle.hpp"


std::istream &operator>>(std::istream &in, Rectangle &rectangle)
{
    String data;
    in >> data;
    unsigned int x = data.findIntValue("x=\"");
    unsigned int y = data.findIntValue("y=\"");
    unsigned int width = data.findIntValue("width=\"");
    unsigned int height = data.findIntValue("height=\"");
    String colour = data.findValue("fill=\"");
    rectangle = Rectangle(x, y, colour, width, height);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &rectangle)
{
    out<<"<rect x=\""<<rectangle.getX()<<"\" y=\""<<rectangle.getY()<<"\" width=\""<<rectangle.getWidth()<<"\" height=\""<<rectangle.getHeight()<<"\" fill=\""<<rectangle.getColour()<<"\" />"<< std::endl;
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