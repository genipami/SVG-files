#include "rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"
class Database
{
private:
    static const std::size_t INITIAL_CAPACITY = 8;
    static const std::size_t INCREASE_STEP = 2;
    Shape** database;
    std::size_t size;
    std::size_t capacity;

    void resize()
    {
        Shape** newDatabase = new Shape*[this->capacity * Database::INCREASE_STEP];
        for (std::size_t i = 0; i < this->size; ++i)
        {
            newDatabase[i] = this->database[i];
        }

        delete[] this->database;
        this->database = newDatabase;
        this->capacity *= Database::INCREASE_STEP;
    }

    void add(Shape* shape)
    {
        if (this->size == this->capacity)
        {
            this->resize();
        }

        this->database[this->size++] = shape;
    }

    void copy(const Database& other)
    {
        this->database = new Shape*[other.capacity];
        
        for (std::size_t i = 0; i < other.size; ++i)
        {

            Rectangle* rectanglePtr = dynamic_cast<Rectangle*>(other.database[i]);
            Circle* circlePtr = dynamic_cast<Circle*>(other.database[i]);
            Line* linePtr = dynamic_cast<Line*>(other.database[i]);

            if (rectanglePtr)
            {
                this->database[i] = new Rectangle(*rectanglePtr);
            }
            else if (circlePtr)
            {
                this->database[i] = new Circle(*circlePtr);
            }
            else if (linePtr)
            {
                this->database[i] = new Line(*linePtr);
            }
            
        }

        this->capacity = other.capacity;
        this->size = other.size;
    }

    void deallocate()
    {
        for (std::size_t i = 0; i < this->size; ++i)
        {
            delete this->database[i];
        }
        delete[] this->database;
    }

public:
    Database() : database(new Shape*[Database::INITIAL_CAPACITY]), size(0), capacity(Database::INITIAL_CAPACITY) {}
    Database(const Database& other)
    {
        this->copy(other);
    }
    Database& operator = (const Database& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    ~Database()
    {
        this->deallocate();
    }

    void addRectangle(const int x, const int y, const int width, const int height, String colour)
    {
        this->add(new Rectangle(x, y, colour, width, height));
    }

    void addCircle(const int x, const int y, const int radius, String colour)
    {
        this->add(new Circle(x, y, colour, radius));
    }

    void addLine(const int x, const int y, const int endX, const int endY, String colour)
    {
        this->add(new Line(x, y, colour, endX, endY));
    }

    void printDatabase() const
    {
        std::size_t j = 0;
        for (std::size_t i = 0; i < this->size; ++i)
        {
            std::cout << ++j << ".";
            this->database[i]->print();
        }
    }
};