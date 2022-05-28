#ifndef __RECTANGLE_HPP
#define __RECTANGLE_HPP
#include "shape.hpp"
#include "circle.hpp"

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(int x, int y, String colour, int width, int height): Shape(x, y, colour), width(width), height(height){}
    friend std::istream& operator>>(std::istream &in, Rectangle& rectangle);
    friend std::ostream& operator<<(std::ostream &out, const Rectangle& rectangle);
    virtual void translate(int vertical, int horizontal) override;
    virtual bool withinRectangle(Rectangle &rectangle) const override;
    virtual bool withinCircle(Circle &circle) const override;
    virtual ~Rectangle() = default;
};

#endif