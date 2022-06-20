#pragma once
#include <fstream>
#include "container.hpp"
#include "vector.hpp"
#include "messages.hpp"



class SVG
{
public:
    static Vector<String> GetCommand(String& command_line)
    {
        unsigned int i = 0, j;
        unsigned int size = command_line.getLength();
        Vector<String> command;
        while (i < size)
        {
            while ((command_line[i] == '\t' || command_line[i] == ' ') && i < size)
            {
                i++;
            }
            j = i;
            while (command_line[i] != '\t' && command_line[i] != ' ' && i < size)
            {
                i++;
            }
            command.Add(command_line.GetSubString(j, i));
        }

        return command;
    }
    static void writeFile(const Container &container, const String &filename)
    {
        std::ofstream output(filename.getWord(), std::ios::trunc);

        if (!output.is_open())
        {
            std::cout << "Problem with file!" << std::endl;
            return;
        }
        output << container;
        output.close();
    }

    static void readFile(Container &container, const String &filename)
    {
        std::fstream data;
        data.open(filename.getWord(), std::fstream::in | std::fstream::app);
        std::cout << data.tellp() << std::endl;
        data >> container;
        data.close();
    }

    static void printAll(const Container &container)
    {
        for (int i = 0; i < container.getSize(); i++)
        {
            container.getShapes()[i]->print();
        }
    }

    static void translateAll(const Container &container, int vertical, int horizontal)
    {
        for (int i = 0; i < container.getSize(); i++)
        {
            container.getShapes()[i]->translate(vertical, horizontal);
        }
    }

    static void translateOne(const Container &container, int vertical, int horizontal, unsigned int index)
    {
        container.getShapes()[index]->translate(vertical, horizontal);
    }

    

    static void create(Container &container, String &input)
    {
        Vector<String> data = SVG::GetCommand(input);
        if (data[1] == "rectangle")
        {
            container.addRectangle(String::stringToInt(data[2]), String::stringToInt(data[3]), String::stringToInt(data[4]), String::stringToInt(data[5]), data[6]);
            Messages::createdRectangle();
        }
        else if (data[1] == "circle")
        {
            container.addCircle(String::stringToInt(data[2]), String::stringToInt(data[3]), String::stringToInt(data[4]), data[5]);
            Messages::createdCircle();
        }
        else if (data[1] == "line")
        {
            container.addLine(String::stringToInt(data[2]), String::stringToInt(data[3]), String::stringToInt(data[4]), String::stringToInt(data[5]), data[6]);
            Messages::createdLine();
        }
    }

    static void within(const Container &container, String &input)
    {
        Vector<String> data = GetCommand(input);
        if (data[1] == "rectangle")
        {
            Rectangle rectangle(String::stringToInt(data[2]), String::stringToInt(data[3]), data[6], String::stringToInt(data[4]), String::stringToInt(data[5]));
            unsigned int counter = 0;
            for (int i = 0; i < container.getSize(); ++i)
            {
                if (container.getShapes()[i]->withinRectangle(rectangle.getX(), rectangle.getY(), rectangle.getWidth(), rectangle.getHeight()))
                {
                    counter++;
                    std::cout << counter << ". ";
                    container.getShapes()[i]->print();
                }
            }
            if (counter == 0)
            {
                Messages::noFigures();
                rectangle.print();
            }
        }
        else if (data[1] == "circle")
        {
            Circle circle(String::stringToInt(data[2]), String::stringToInt(data[3]), data[5], String::stringToInt(data[4]));
            unsigned int counter = 0;
            for (int i = 0; i < container.getSize(); ++i)
            {
                if (container.getShapes()[i]->withinCircle(circle.getX(), circle.getY(), circle.getRadius()))
                {
                    counter++;
                    std::cout << counter << ". ";
                    container.getShapes()[i]->print();
                }
            }
            if (counter == 0)
            {
                Messages::noFigures();
                circle.print();
            }
        }
    }
    
    static void start()
    {
        Container container;
        Messages::helpM();
        String input;
        String filename;
        bool exit = false;
        bool opened = false;
        bool saved = true;
        while (!exit)
        {
            std::cin >> input;
            if (!opened)
            {
                if (input.checkSubString("open"))
                {

                    filename = input.findSecondPart("open ");
                    std::cout << filename << std::endl;
                    SVG::readFile(container, filename);
                    opened = true;
                    Messages::openedSuccessfully();
                    std::cout << filename << std::endl;
                }

                if (input.checkSubString("exit"))
                {
                    Messages::exitingM();
                    exit = true;
                }
            }

            else
            {
                if (input.checkSubString("close"))
                {
                    Container empty;
                    container = empty;
                    opened = false;
                    Messages::closeM();
                }

                if (input.checkSubString("saveas"))
                {
                    filename = input.findSecondPart("saveas ");
                    writeFile(container, filename);
                    saved = true;
                    Messages::saveM();
                    std::cout << filename << std::endl;
                }

                if (input.checkSubString("save"))
                {
                    writeFile(container, filename);
                    saved = true;
                    Messages::saveM();
                }

                if (input.checkSubString("help"))
                {
                    Messages::helpM();
                }

                if (input.checkSubString("exit"))
                {
                    if (!saved)
                    {
                        Messages::unsavedChanges();
                    }
                    else
                    {
                        Messages::exitingM();
                        exit = true;
                    }
                }

                if (input.checkSubString("print"))
                {
                    printAll(container);
                }

                if (input.checkSubString("create"))
                {
                    create(container, input);
                    saved = false;
                }

                if (input.checkSubString("erase"))
                {
                    unsigned int index = input.findIntValue("erase ");
                    if (index < container.getSize())
                    {
                        container.remove(index - 1);
                        std::cout << "Erased figure (" << index << ") " << std::endl;
                        saved = false;
                    }
                    else
                    {
                        Messages::noFigureNumber();
                        std::cout << index << std::endl;
                    }
                }

                if (input.checkSubString("translate"))
                {
                    String data = input.findSecondPart("translate ");
                    int vertical = input.findIntValue("vertical=");
                    int horizontal = input.findIntValue("horizontal=");
                    if (data.getWord()[0] >= '0' && data.getWord()[0] <= '9')
                    {
                        unsigned int index = input.findIntValue("translate ");
                        translateOne(container, vertical, horizontal, index);
                    }
                    else
                    {
                        translateAll(container, vertical, horizontal);
                    }
                    saved = false;
                }

                if (input.checkSubString("within"))
                {
                    within(container, input);
                }
            }
        }
    }

    
};