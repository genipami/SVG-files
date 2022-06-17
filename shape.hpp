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
    /// Constructor with parameters
    Shape(int x, int y, String colour) : x(x), y(y), colour(colour) {}
    /// Getter for the x value of the shape
    int getX() const { return x; }
    /// Getter for the y value of the shape
    int getY() const { return y; }
    /// Getter for the color value of the shape
    String getColour() const { return colour; }
    /// Setter for the x value of the shape
    void setX(int x) { this->x = x; }
    /// Setter for the y value of the shape
    void setY(int y) { this->y = y; }
    /// Setter for the colour value of the shape
    void setColour(const String &colour) { this->colour = colour; }
    /// Virtual void method that translates the shape vertically and horizontally. Can be overriden for future shapes.
    virtual void translate(int vertical, int horizontal)
    {
        this->setX(this->getX() + horizontal);
        this->setY(this->getY() + vertical);
    }
    /// Pure virtual method that retuns a bool value of 1 if the shape is withing the specified rectangle and 0 otherwise
    virtual bool withinRectangle(const Rectangle &rectangle) const = 0;
    /// Pure virtual method that retuns a bool value of 1 if the shape is withing the specified circle and 0 otherwise
    virtual bool withinCircle(const Circle &circle) const = 0;
    /// Pure virtual method that prints the information about the shape
    virtual void print() const = 0;
    /// Virtual destructor 
    virtual ~Shape() = default;
    /// Helper method that calulates the distance between two points and returns it as a double
    double distance(int x1, int y1, int x2, int y2) const
    {
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
};

#endif