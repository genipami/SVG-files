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
    unsigned int getRadius() const {return radius;}
    friend std::istream& operator>>(std::istream &in, Circle& circle);
    friend std::ostream& operator<<(std::ostream &out, const Circle& circle);
    virtual bool withinRectangle(const Rectangle &rectangle) const override;
    virtual bool withinCircle(const Circle &circle) const override;
    virtual void print()const override;
    virtual ~Circle() = default;
};

#endif