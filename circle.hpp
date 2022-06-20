#pragma once
#include "shape.hpp"

class Circle : public Shape
{
private:
    unsigned int radius;

public:
    /// Constructor with parameters
    Circle(unsigned int x, unsigned int y, String colour, unsigned int radius): Shape(x, y, colour), radius(radius){}
    /// Getter for the radius of the circle
    unsigned int getRadius() const {return radius;}
    /// Redefinition of the reading operator
    friend std::istream& operator>>(std::istream &in, Circle& circle);
    /// Redefinition of the printing operator
    friend std::ostream& operator<<(std::ostream &out, const Circle& circle);
    /// Overriding of the withinRectangle method for a circle
    virtual bool withinRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const override;
    /// Overriding of the withinCircle method for a circle
    virtual bool withinCircle(unsigned int cx, unsigned int cy, unsigned int r) const override;
    /// Overriding of the printing method
    virtual void print()const override;
    /// Virtual destructor
    virtual ~Circle() = default;
};