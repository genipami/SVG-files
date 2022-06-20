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
    return out;
}

bool Rectangle::withinRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
{
    if (this->getX() <= x && this->getY() <= y && this->getX() + this->width >= x + width && this->getY() + this->height >= y + height)
        return true;

    return false;
}
bool Rectangle::withinCircle(unsigned int cx, unsigned int cy, unsigned int r) const
{
    if (distance(this->getX(), this->getY(), cx, cy) < r &&
        distance(this->getX() + this->width, this->getY(), cx, cy) < r &&
        distance(this->getX(), this->getY() + this->height, cx, cy) < r &&
        distance(this->getX() + this->width, this->getY() + this->height, cx, cy) < r)
        return true;

    return false;
}
void Rectangle::print() const
{
    std::cout << "rectangle " << this->getX() << " " << this->getY()<< " " << this->width << " " << this->height << " " << this->getColour() << std::endl;
}