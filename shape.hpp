#ifndef __SHAPE_HPP
#define __SHAPE_HPP
#include <iostream>
#include <cmath>
#include "string.hpp"
#include "rectangle.hpp"

class Shape
{
private:
    int x;
    int y;
    String colour;

public:
    Shape(int x, int y, String colour) : x(x), y(y), colour(colour) {}
    int getX() const { return x; }
    int getY() const { return y; }
    String getColour() const { return colour; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    virtual void translate(int vertical, int horizontal)
    {
        this->setX(this->getX() + horizontal);
        this->setY(this->getY() + vertical);
    }
    virtual bool withinRectangle(const Rectangle &rectangle) const = 0;
    virtual bool withinCircle(const Circle &circle) const = 0;
    virtual void print() const = 0;
    virtual ~Shape() = default;
    double distance(int x1, int y1, int x2, int y2) const
    {
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
};

#endif