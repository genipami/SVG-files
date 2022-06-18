#include <iostream>
#include "line.hpp"

std::istream &operator>>(std::istream &in, Line &line)
{
    String data;
    in >> data;
    unsigned int x = data.findIntValue("x1=\"");
    unsigned int y = data.findIntValue("y2=\"");
    unsigned int endX = data.findIntValue("x2=\"");
    unsigned int endY = data.findIntValue("y2=\"");
    String colour = data.findValue("style=\"stroke:");
    line = Line(x, y, colour, endX, endY);
    return in;
}
std::ostream &operator<<(std::ostream &out, const Line &line)
{
    out << "<line x1=\"" << line.getX() << "\" y1=\"" << line.getY() << "\" x2=\"" << line.endX << "\" y2=\"" << line.endY << "\" style=\"stroke:" << line.getColour() << "\" />" << std::endl;
}
bool Line::pointIsWithinRectangle(int x, int y, const Rectangle &rectangle) const
{
    if (x >= rectangle.getX() &&
        x <= rectangle.getX() + rectangle.getWidth() &&
        y >= rectangle.getY() &&
        y <= rectangle.getY() + rectangle.getHeight())
        return true;
    return false;
}

bool Line::pointIsWithinCircle(int x, int y, const Circle &circle) const
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

void Line::translate(int vertical, int horizontal)
{
    if((horizontal < 0 && std::abs(horizontal)>this->getX())
     ||(vertical < 0 && std::abs(vertical)>this->getY())
     ||(horizontal < 0 && std::abs(horizontal)>this->endX)
     ||(vertical < 0 && std::abs(vertical)>this->endY)) std::cout<< "Translation is impossible.";
    this->setX(this->getX() + horizontal);
    this->setY(this->getY() + vertical);
    this->endX+=horizontal;
    this->endY+=vertical;
}