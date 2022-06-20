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
    return out;
}
bool Line::pointIsWithinRectangle(int x, int y, unsigned int rectX, unsigned int rectY, unsigned int width, unsigned int height) const
{
    if (x >= rectX &&
        x <= rectX + width &&
        y >= rectY &&
        y <= rectY + height)
        return true;
    return false;
}

bool Line::pointIsWithinCircle(int x, int y, unsigned int cx, unsigned int cy, unsigned int r) const
{
    if (distance(x, y, cx, cy) <= r)
        return true;
    return false;
}
bool Line::withinRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
{

    if (pointIsWithinRectangle(this->getX(), this->getY(), x, y, width, height) &&
        pointIsWithinRectangle(this->endX, this->endY, x, y, width, height))
        return true;
    return false;
}
bool Line::withinCircle(unsigned int cx, unsigned int cy, unsigned int r) const
{
    if (pointIsWithinCircle(this->getX(), this->getY(), cx, cy, r) &&
        pointIsWithinCircle(this->endX, this->endY, cx, cy, r))
        return true;
    return false;
}
void Line::print() const
{
    std::cout << "line " << this->getX() << " " << this->getY() << " " << this->endX << " " << this->endY << " " << getColour() << std::endl;
}

void Line::translate(int vertical, int horizontal)
{
    if ((horizontal < 0 && std::abs(horizontal) > this->getX()) || (vertical < 0 && std::abs(vertical) > this->getY()) || (horizontal < 0 && std::abs(horizontal) > this->endX) || (vertical < 0 && std::abs(vertical) > this->endY))
        std::cout << "Translation is impossible.";
    this->setX(this->getX() + horizontal);
    this->setY(this->getY() + vertical);
    this->endX += horizontal;
    this->endY += vertical;
}