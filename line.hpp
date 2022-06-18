#ifndef __LINE_HPP
#define __LINE_HPP
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

class Line : public Shape
{
private:
    unsigned int endX;
    unsigned int endY;

public:
    /// Constructor with parameters
    Line(unsigned int x, unsigned int y, String colour, unsigned int endX, unsigned int endY): Shape(x, y, colour), endX(x), endY(y){}
    /// Redefinition of the reading operator
    friend std::istream& operator>>(std::istream &in, Line& line);
    /// Redefinition of the printing operator
    friend std::ostream& operator<<(std::ostream &out, const Line& line);
    /// Helper method that returns a bool value of 1 if the point is within the rectangle and 0 otherwise
    bool pointIsWithinRectangle(int x, int y, const Rectangle &rectangle) const; 
    /// Helper method that returns a bool value of 1 if the point is within the circle and 0 otherwise
    bool pointIsWithinCircle(int x, int y, const Circle &circle) const;
    /// Overriding of the withinRectanle method for a line
    virtual bool withinRectangle(const Rectangle &rectangle) const override;
    /// Overriding of the withinCircle method for a line
    virtual bool withinCircle(const Circle &circle) const override;
    /// Overiding of the printing method for a line
    virtual void print()const override;
    /// Overriding of the translate method for a line
    virtual void translate(int vertical, int horizontal) override;
    /// Virtual destructor
    virtual ~Line() = default;
};
#endif