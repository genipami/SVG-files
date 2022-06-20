#pragma once
#include "shape.hpp"
#include "circle.hpp"

class Rectangle : public Shape
{
private:
    unsigned int width;
    unsigned int height;

public:
    /// Constructor with parameters
    Rectangle(unsigned int x, unsigned int y, String colour, unsigned int width, unsigned int height): Shape(x, y, colour), width(width), height(height){}
    /// Getter for the width of the rectangle
    unsigned int getWidth() const { return width; }
    /// Getter for the height of the rectangle
    unsigned int getHeight() const { return height; }
    /// Redefinition of the reading operator 
    friend std::istream& operator>>(std::istream &in, Rectangle& rectangle);
    /// Redefinition for the printing operator
    friend std::ostream& operator<<(std::ostream &out, const Rectangle& rectangle);
    /// Overriging of the withinRectangle method for a rectangle
    virtual bool withinRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const override;
    /// Overriging of the withinCircle method for a rectangle
    virtual bool withinCircle(unsigned int cx, unsigned int cy, unsigned int r) const override;
    /// Overriging of the printing method for a rectangle
    virtual void print() const override;
    /// Virtual destructor
    virtual ~Rectangle() = default;
};

