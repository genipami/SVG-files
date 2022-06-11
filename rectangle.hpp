#ifndef __RECTANGLE_HPP
#define __RECTANGLE_HPP
#include "shape.hpp"
#include "circle.hpp"

class Rectangle : public Shape
{
private:
    unsigned int width;
    unsigned int height;

public:
    Rectangle(int x, int y, String colour, int width, int height): Shape(x, y, colour), width(width), height(height){}
    unsigned int getWidth() const { return width; }
    unsigned int getHeight() const { return height; }
    friend std::istream& operator>>(std::istream &in, Rectangle& rectangle);
    friend std::ostream& operator<<(std::ostream &out, const Rectangle& rectangle);
    virtual bool withinRectangle(const Rectangle &rectangle) const override;
    virtual bool withinCircle(const Circle &circle) const override;
    virtual void print() const override;
    virtual ~Rectangle() = default;
};

#endif