#pragma once
#include <iostream>
#include <cmath>
#include "string.hpp"

class Shape
{
private:
    unsigned int x;
    unsigned int y;
    String colour;

public:
    /// Constructor with parameters
    Shape(int x, int y, String colour) : x(x), y(y), colour(colour) {}

    /// Getter for the x value of the shape
    unsigned int getX() const { return x; }
    /// Getter for the y value of the shape
    unsigned int getY() const { return y; }
    /// Getter for the color value of the shape
    String getColour() const { return colour; }

    /// Setter for the x value of the shape
    void setX(unsigned int x) { this->x = x; }
    /// Setter for the y value of the shape
    void setY(unsigned int y) { this->y = y; }
    /// Setter for the colour value of the shape
    void setColour(const String &colour) { this->colour = colour; }

    /// Virtual void method that translates the shape vertically and horizontally. Can be overriden for future shapes.
    virtual void translate(int vertical, int horizontal)
    {
        if((horizontal < 0 && std::abs(horizontal)>this->getX())||(vertical < 0 && std::abs(vertical)>this->getY())) std::cout<< "Translation is impossible.";
        this->setX(this->getX() + horizontal);
        this->setY(this->getY() + vertical);
    }

    /// Pure virtual method that retuns a bool value of 1 if the shape is withing the specified rectangle and 0 otherwise
    virtual bool withinRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const = 0;
    /// Pure virtual method that retuns a bool value of 1 if the shape is withing the specified circle and 0 otherwise
    virtual bool withinCircle(unsigned int cx, unsigned int cy, unsigned int r) const = 0;
    /// Pure virtual method that prints the information about the shape
    virtual void print() const = 0;

    /// Virtual destructor 
    virtual ~Shape() = default;
    
    /// Helper method that calulates the distance between two points and returns it as a double
    double distance(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) const
    {
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
};
