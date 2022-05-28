#ifndef __LINE_HPP
#define __LINE_HPP
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

class Line : public Shape
{
private:
    int endX;
    int endY;

public:
    Line(int x, int y, String colour, int endX, int endY): Shape(x, y, colour), endX(x), endY(y){}
    friend std::istream& operator>>(std::istream &in, Line& line);
    friend std::ostream& operator<<(std::ostream &out, const Line& line);
    virtual void translate(int vertical, int horizontal) override;
    virtual bool withinRectangle(Rectangle &rectangle) const override;
    virtual bool withinCircle(Circle &circle) const override;
    virtual ~Line() = default;
};
#endif