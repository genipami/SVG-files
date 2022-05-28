#ifndef __CIRCLE_HPP
#define __CIRCLE_HPP
#include "shape.hpp"
#include "rectangle.hpp"

class Circle : public Shape
{
private:
    unsigned int radius;

public:
    Circle(int x, int y, String colour, unsigned int radius): Shape(x, y, colour), radius(radius){}
    friend std::istream& operator>>(std::istream &in, Circle& circle);
    friend std::ostream& operator<<(std::ostream &out, const Circle& circle);
    virtual void translate(int vertical, int horizontal) override;
    virtual bool withinRectangle(Rectangle &rectangle) const override;
    virtual bool withinCircle(Circle &circle) const override;
    virtual ~Circle() = default;
};

#endif