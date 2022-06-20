#include "container.hpp"

void Container::resize()
{
    Shape **newShapes = new Shape *[this->capacity * Container::INCREASE_STEP];
    for (std::size_t i = 0; i < this->size; ++i)
    {
        newShapes[i] = this->shapes[i];
    }

    delete[] this->shapes;
    this->shapes = newShapes;
    this->capacity *= Container::INCREASE_STEP;
}

void Container::add(Shape *shape)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->shapes[this->size++] = shape;
}

void Container::copy(const Container &other)
{
    this->shapes = new Shape *[other.capacity];

    for (std::size_t i = 0; i < other.size; ++i)
    {

        Rectangle *rectanglePtr = dynamic_cast<Rectangle *>(other.shapes[i]);
        Circle *circlePtr = dynamic_cast<Circle *>(other.shapes[i]);
        Line *linePtr = dynamic_cast<Line *>(other.shapes[i]);

        if (rectanglePtr)
        {
            this->shapes[i] = new Rectangle(*rectanglePtr);
        }
        else if (circlePtr)
        {
            this->shapes[i] = new Circle(*circlePtr);
        }
        else if (linePtr)
        {
            this->shapes[i] = new Line(*linePtr);
        }
    }

    this->capacity = other.capacity;
    this->size = other.size;
}

void Container::deallocate()
{
    for (std::size_t i = 0; i < this->size; ++i)
    {
        delete this->shapes[i];
    }
    delete[] this->shapes;
}

Container& Container::operator=(const Container &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

void Container::addRectangle(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height, String colour)
{
    this->add(new Rectangle(x, y, colour, width, height));
}

void Container::addCircle(const unsigned int x, const unsigned int y, const unsigned int radius, String colour)
{
    this->add(new Circle(x, y, colour, radius));
}

void Container::addLine(const unsigned int x, const unsigned int y, const unsigned int endX, const unsigned int endY, String colour)
{
    this->add(new Line(x, y, colour, endX, endY));
}

void Container::remove(std::size_t index)
{
    if (index >= 0 && index < this->size)
    {
        if (index != this->size - 1)
        {
            this->shapes[index] = this->shapes[size - 1];
        }
        this->size--;
    }
}

void Container::printShapes() const
{
    std::size_t j = 0;
    for (std::size_t i = 0; i < this->size; ++i)
    {
        std::cout << ++j << ".";
        this->shapes[i]->print();
    }
}

std::ostream &operator<<(std::ostream &out, const Container &container)
{
    out << OPENING_TAG;
    for (std::size_t i = 1; i <= container.size; i++)
    {
        out << &container.getShapes()[i];
    }
    out << CLOSING_TAG;
    return out;
}

std::istream &operator>>(std::istream &in, Container &container)
{
    String one;
    in >> one;
    in >> one;
    in >> one;
    String data;
    while (!(data.checkSubString(CLOSING_TAG)))
    {
        in >> data;
        std::cout << data << std::endl;
        if (data.checkSubString("rect"))
        {
            unsigned int x = data.findIntValue("x=\"");
            unsigned int y = data.findIntValue("y=\"");
            unsigned int width = data.findIntValue("width=\"");
            unsigned int height = data.findIntValue("height=\"");
            String colour = data.findValue("fill=\"");
            container.addRectangle(x, y, width, height, colour);
        }

        if (data.checkSubString("circle"))
        {
            unsigned int x = data.findIntValue("cx=\"");
            unsigned int y = data.findIntValue("cy=\"");
            unsigned int radius = data.findIntValue("r=\"");
            String colour = data.findValue("fill=\"");
            container.addCircle(x, y, radius, colour);
        }

        if (data.checkSubString("line"))
        {
            unsigned int x = data.findIntValue("x1=\"");
            unsigned int y = data.findIntValue("y2=\"");
            unsigned int endX = data.findIntValue("x2=\"");
            unsigned int endY = data.findIntValue("y2=\"");
            String colour = data.findValue("style=\"stroke:");
            container.addLine(x, y, endX, endY, colour);
        }
    }
    return in;
}