#ifndef __VECTOR_HPP
#define __VECTOR_HPP
#include <iostream>

template <class T>
class Vector
{
private:
    T *data;
    unsigned int size;
    unsigned int capacity;

public:
    Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
    friend std::istream& operator>>(std::istream& in, Vector& vector);
    ~Vector();
    void resize();
    void pushBack(T newValue);
    void popBack();
};

#endif