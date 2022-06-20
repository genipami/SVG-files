#pragma once
#include <iostream>

class Messages
{
public:
    static void const problemM()
    {
        std::cout << "There has been a problem!" << std::endl;
    }

    static void const successM()
    {
        std::cout << "The operation was successful." << std::endl;
    }

    static void const helpM()
    {
        std::cout << "The following commands are supported:" << std::endl;
        std::cout << "open <file>       opens <file>" << std::endl;
        std::cout << "close             closes currently opened file" << std::endl;
        std::cout << "save              saves the currently open file" << std::endl;
        std::cout << "saveas <file>     saves the currently open file in <file>" << std::endl;
        std::cout << "help              prints this information" << std::endl;
        std::cout << "exit              exits the program" << std::endl;
        std::cout << "print             prints all shapes on the screen" << std::endl;
        std::cout << "create            creates a new shape" << std::endl;
        std::cout << "erase <n>         erases the shape on the n-th place" << std::endl;
        std::cout << "translate [<n>]   translates the n-th shape or all shapes if n is not specified" << std::endl;
        std::cout << "within <option>   prints out all the shapes that are contained in the <option>" << std::endl;
    }

    static void const unsavedChanges()
    {
        std::cout << "You have an open file with unsaved changes, plese select close or save first." << std::endl;
    }

    static void const closeM()
    {
        std::cout << "Succesfully closed ";
    }

    static void const saveM()
    {
        std::cout << "Succesfully saved ";
    }

    static void const createdRectangle()
    {
        std::cout << "Succesfully created rectangle ";
    }

    static void const createdCircle()
    {
        std::cout << "Succesfully created circle ";
    }

    static void const createdLine()
    {
        std::cout << "Succesfully created line ";
    }

    static void const noFigures()
    {
        std::cout << "No figures are located within ";
    }

    static void const noFigureNumber()
    {
        std::cout << "There is no figure number ";
    }

    static void const translatedAll()
    {
        std::cout << "Translated all figures" << std::endl;
    }

    static void const exitingM()
    {
        std::cout << "Exiting program..." << std::endl;
    }

    static void const openedSuccessfully()
    {
        std::cout << "Succesfully opened ";
    }

};