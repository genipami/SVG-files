#ifndef __STRING_HPP
#define __STRING_HPP
#include <iostream>

/// Realization of the standard string class
class String
{
private:
    /// The main representation of the string
    char *word;
    /// The number of characters in the string

    unsigned int length;

public:
    /// Getters for the member variables
    /// Return the string as a char*
    char *getWord() const;
    /// Return the number of characters in the string
    unsigned int getLength() const;

    /// Setters for the member variables
    /// Set the string as a char*
    void setWord(const char *word);
    /// Set the number of characters in the string
    void setLength(const unsigned int length);

    /// Constructors
    /// The default constructor
    String();
    /// The constructor with parameters
    String(const char *word);
    /// The copy constructor
    String(const String &other);

    /// Overloading operators
    /// Assignment operator that takes care of the dynamic memory
    String operator=(const String &other);
    /// Addition operator that concatinates two strings
    String operator+(const String &other) const;
    /// Addition assignment operator that modifies the first value to be the concatination of the two
    String &operator+=(const String &other);
    /// Is equal to operator that returns a bool value
    bool operator==(const String &other) const;
    /// Is less than operator that returns a bool value
    bool operator<(const String &other) const;
    /// Is greater than operator that returns a bool value
    bool operator>(const String &other) const;
    /// Array index operator (can be used for assigning values) that returns the value of the element of the array with the given index
    char &operator[](const unsigned int index);
    /// Array index operator (only for getting values) that returns the value of the element of the array with the given index
    const char &operator[](const unsigned int index) const;
    /// Printing operator that supports string
    friend std::ostream &operator<<(std::ostream &out, const String &str);
    /// Reading operator that supports string
    friend std::istream &operator>>(std::istream &in, String &str);
    /// Helper function
    /// Checks if a string is a substring of another string. Returns true or false accordingly.
    bool checkSubString(const String &small) const;

    /// Destructor
    ~String();
};

#endif