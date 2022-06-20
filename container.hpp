#pragma once
#include "rectangle.hpp"
#include "circle.hpp"
#include "line.cpp"


static const String OPENING_TAG = "<?xml version=\"1.0\" standalone=\"no\"?>\n< !DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n< svg >\n";
static const String CLOSING_TAG = "</svg>";

class Container
{
private:
    static const std::size_t INITIAL_CAPACITY = 8;
    static const std::size_t INCREASE_STEP = 2;
    Shape **shapes;
    std::size_t size;
    std::size_t capacity;

    /// Private resizing method
    void resize();

    /// Private method that adds a pointer to a shape to the end of the array
    void add(Shape *shape);

    /// Private copy method
    void copy(const Container &other);

    /// Private dellocation method
    void deallocate();

public:
    std::size_t getSize() const
    {
        return this->size;
    }
    Shape **getShapes() const
    {
        return this->shapes;
    }
    /// Default constructor
    Container() : shapes(new Shape *[Container::INITIAL_CAPACITY]), size(0), capacity(Container::INITIAL_CAPACITY) {}
    /// Copy constructor
    Container(const Container &other)
    {
        this->copy(other);
    }
    /// Assignment operator
    Container &operator=(const Container &other);
    /// Destructor
    ~Container()
    {
        this->deallocate();
    }

    /// Adding method for a rectangle
    void addRectangle(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height, String colour);
    /// Adding method for a circle
    void addCircle(const unsigned int x, const unsigned int y, const unsigned int radius, String colour);
    /// Adding method for a line
    void addLine(const unsigned int x, const unsigned int y, const unsigned int endX, const unsigned int endY, String colour);

    /// Method that remoes a shape at a given index
    void remove(std::size_t index);

    /// Method that prints all the shapes
    void printShapes() const;

    /// Redefinition of the printing operator for a shape container
    friend std::ostream &operator<<(std::ostream &out, const Container &container);
    /// Redefinition of the reading operator for a shape container
    friend std::istream &operator>>(std::istream &in, Container &container);
};

