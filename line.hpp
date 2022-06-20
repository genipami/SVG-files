#pragma once
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
    bool pointIsWithinRectangle(int x, int y, unsigned int rectX, unsigned int rectY, unsigned int width, unsigned int height) const; 
    /// Helper method that returns a bool value of 1 if the point is within the circle and 0 otherwise
    bool pointIsWithinCircle(int x, int y, unsigned int cx, unsigned int cy, unsigned int r) const;
    /// Overriding of the withinRectanle method for a line
    virtual bool withinRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const override;
    /// Overriding of the withinCircle method for ae line
    virtual bool withinCircle(unsigned int cx, unsigned int cy, unsigned int r) const override;
    /// Overiding of the printing method for a line
    virtual void print()const override;
    /// Overriding of the translate method for a line
    virtual void translate(int vertical, int horizontal) override;
    /// Virtual destructor
    virtual ~Line() = default;
};
