#include <cassert>
#include <cstring>
#include "string.hpp"

char *String::getWord() const
{
    return this->word;
}
unsigned int String::getLength() const
{
    return this->length;
}
void String::setWord(const char *word)
{
    delete[] this->word;
    this->length = strlen(word);
    this->word = new char[this->length + 1];
    strcpy(this->word, word);
}
void String::setLength(const unsigned int length)
{
    this->length = length;
}
String::String()
{
    this->setLength(0);
    this->word = new char[this->getLength() + 1];
    this->setWord("");
}
String::String(const char *word) : word(nullptr)
{
    this->setLength(strlen(word));
    this->setWord(word);
}

String::String(const String &other)
{
    this->word = new char[other.getLength() + 1];
    this->setWord(other.getWord());
    this->setLength(other.getLength());
}

String String::operator=(const String &other)
{
    if (this != &other)
    {
        this->setWord(other.getWord());
        this->setLength(other.getLength());
    }
    return *this;
}

String String::operator+(const String &other) const
{
    String result;
    result.setLength(this->getLength() + other.getLength());
    result.word = new char[result.getLength() + 1];
    result.setWord(this->getWord());
    strcat(result.word, other.getWord());
    return result;
}

String String::operator+(const char letter) const
{
    String result;
    result.setLength(this->getLength() + 1);
    result.word = new char[result.getLength() + 1];
    result.setWord(this->getWord());
    result.word[result.getLength()] = letter;
    return result;
}

String &String::operator+=(const String &other)
{
    *this = *this + other;
    return *this;
}

bool String::operator==(const String &other) const
{
    if (this->getLength() != other.getLength())
        return false;
    for (int i = 0; i < this->getLength(); i++)
    {
        if (this->getWord()[i] != other.getWord()[i])
            return false;
    }
    return true;
}

bool String::operator<(const String &other) const
{
    if (*this == other)
        return false;
    int min = this->getLength() < other.getLength() ? this->getLength() : other.getLength();
    for (int i = 0; i < min; i++)
    {
        if (this->getWord()[i] < other.getWord()[i])
        {
            return true;
        }
        else if (this->getWord()[i] > other.getWord()[i])
        {
            return false;
        }
    }
    return this->getLength() < other.getLength();
}
bool String::operator>(const String &other) const
{
    if (*this == other)
        return false;
    else
        return !(*this < other);
}

char &String::operator[](unsigned int index)
{
    return this->getWord()[index];
}
const char &String::operator[](unsigned int index) const
{
    return this->getWord()[index];
}
std::ostream &operator<<(std::ostream &out, const String &string)
{
    out << string.getWord();
    return out;
}
std::istream &operator>>(std::istream &in, String &str)
{
    const unsigned int MAX = 2048; /// The maximun number of characters in a string
    char buffer[MAX];
    in.getline(buffer, MAX - 1);
    str.setWord(buffer);
    return in;
}

bool String::checkSubString(const String &small) const
{
    if (strstr(this->word, small.word))
        return true;
    return false;
}

String String::findSubString(String substring) const
{
    return strstr(this->word, substring.getWord());
}

String String::findValue(const String& key) const
{
    String substring = this->findSubString(key);
    int i=0;
    String result;
    while(substring[i] != '\"' || substring[i] != ' ')
    {
        result = result + substring[i++];
    }
    return result;
}

unsigned int String::findIntValue(const String& key) const
{
    String string = this->findValue(key);
    return stringToInt(string);
}

unsigned int String::stringToInt(const String& string)
{
    int i = 0;
    unsigned int result = 0;
    while(i<string.getLength())
    {
        result = result*10 + (int)(string[i] - '0');
    }
    return result;
}

String String::GetSubString(const unsigned int i, const unsigned int j)
{
	if (i > this->length || j > this->length)
	{
		std::cout << "Something went wrong!" << std::endl;
		return "";
	}

	char delim = this->word[j];
	this->word[j] = '\0';
	String copy(this->word + i);
	this->word[j] = delim;
	return copy;
}


String::~String()
{
    delete[] this->word;
}