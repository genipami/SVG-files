#ifndef __SHAPE_HPP
#define __SHAPE_HPP
#include <iostream>
#include "string.hpp"


class Shape
{
protected:
    int x;
    int y;
    String colour;

public:
    Shape(int x, int y, String colour): x(x), y(y), colour(colour){}
    friend std::istream& operator>>(std::istream &in, Shape &shape);
    friend std::ostream& operator<<(std::ostream &out, const Shape &shape);
    virtual void translate(int vertical, int horizontal) = 0;
    virtual bool withinRectangle(Rectangle &rectangle) const = 0;
    virtual bool withinCircle(Circle &circle) const = 0;
    virtual ~Shape() = default;

};

#endif