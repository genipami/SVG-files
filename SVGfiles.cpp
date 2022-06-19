#include <fstream>
#include "container.hpp"
#include "messages.cpp"
#include "vector.hpp"
using namespace Messages;

namespace SVG
{
    void start()
    {
        Container container;
        help();
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

                    filename = input.findSubString("open ");
                    readFile(container, filename);
                    opened = true;
                    openedSuccessfully();
                    std::cout << filename << std::endl;
                }

                if (input.checkSubString("exit"))
                {
                    exiting();
                    exit = true;
                }
            }

            else
            {
                if (input.checkSubString("close"))
                {
                    Container empty;
                    container = empty;
                    close();
                }

                if (input.checkSubString("saveas"))
                {
                    filename = input.findSubString("saveas ");
                    writeFile(container, filename);
                    saved = true;
                    save();
                    std::cout << filename << std::endl;
                }

                if (input.checkSubString("save"))
                {
                    writeFile(container, filename);
                    saved = true;
                    save();
                }

                if (input.checkSubString("help"))
                {
                    help();
                }

                if (input.checkSubString("exit"))
                {
                    if (!saved)
                    {
                        unsavedChanges();
                    }
                    else
                    {
                        exiting();
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
                        noFigureNumber();
                        std::cout << index << std::endl;
                    }
                }

                if (input.checkSubString("translate"))
                {
                    String data = input.findSubString("translate ");
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

    void writeFile(const Container &container, const String &filename)
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

    void readFile(Container &container, const String &filename)
    {
        std::ifstream data(filename.getWord());
        if (!(data.is_open()))
        {
            problem();
            return;
        }
        data >> container;
        data.close();
    }

    void printAll(const Container &container)
    {
        for (int i = 0; i < container.getSize(); i++)
        {
            container.getShapes()[i]->print();
        }
    }

    void translateAll(const Container &container, int vertical, int horizontal)
    {
        for (int i = 0; i < container.getSize(); i++)
        {
            container.getShapes()[i]->translate(vertical, horizontal);
        }
    }

    void translateOne(const Container &container, int vertical, int horizontal, unsigned int index)
    {
        container.getShapes()[index]->translate(vertical, horizontal);
    }

    Vector<String> GetCommand(String &command_line)
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

    void create(Container &container, String &input)
    {
        Vector<String> data = GetCommand(input);
        if (data[1] == "rectangle")
        {
            container.addRectangle(String::stringToInt(data[2]), String::stringToInt(data[3]), String::stringToInt(data[4]), String::stringToInt(data[5]), data[6]);
        }
        else if (data[1] == "circle")
        {
            container.addCircle(String::stringToInt(data[2]), String::stringToInt(data[3]), String::stringToInt(data[4]), data[5]);
        }
        else if (data[1] == "line")
        {
            container.addLine(String::stringToInt(data[2]), String::stringToInt(data[3]), String::stringToInt(data[4]), String::stringToInt(data[5]), data[6]);
        }
    }

    void within(const Container &container, String &input)
    {
        Vector<String> data = GetCommand(input);
        if (data[1] == "rectangle")
        {
            Rectangle rectangle(String::stringToInt(data[2]), String::stringToInt(data[3]), data[6], String::stringToInt(data[4]), String::stringToInt(data[5]));
            unsigned int counter = 0;
            for (int i = 0; i < container.getSize(); ++i)
            {
                if (container.getShapes()[i]->withinRectangle(rectangle))
                {
                    counter++;
                    std::cout << counter << ". ";
                    container.getShapes()[i]->print();
                }
            }
            if (counter == 0)
            {
                noFigures();
                rectangle.print();
            }
        }
        else if (data[1] == "circle")
        {
            Circle circle(String::stringToInt(data[2]), String::stringToInt(data[3]), data[5], String::stringToInt(data[4]));
            unsigned int counter = 0;
            for (int i = 0; i < container.getSize(); ++i)
            {
                if (container.getShapes()[i]->withinCircle(circle))
                {
                    counter++;
                    std::cout << counter << ". ";
                    container.getShapes()[i]->print();
                }
            }
            if (counter == 0)
            {
                noFigures();
                circle.print();
            }
        }
    }
}