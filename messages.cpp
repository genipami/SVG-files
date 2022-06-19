#include <iostream>

namespace Messages
{
    void const problem()
    {
        std::cout << "There has been a problem!" << std::endl;
    }

    void const success()
    {
        std::cout << "The operation was successful." << std::endl;
    }

    void const help()
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

    void const unsavedChanges()
    {
        std::cout << "You have an open file with unsaved changes, plese select close or save first." << std::endl;
    }

    void const close()
    {
        std::cout << "Succesfully closed ";
    }

    void const save()
    {
        std::cout << "Succesfully saved ";
    }

    void const createdRectangle()
    {
        std::cout << "Succesfully created rectangle ";
    }

    void const createdCircle()
    {
        std::cout << "Succesfully created circle ";
    }

    void const createdLine()
    {
        std::cout << "Succesfully created line ";
    }

    void const noFigures()
    {
        std::cout << "No figures are located within ";
    }

    void const noFigureNumber()
    {
        std::cout << "There is no figure number ";
    }

    void const translatedAll()
    {
        std::cout << "Translated all figures" << std::endl;
    }

    void const exiting()
    {
        std::cout << "Exiting program..." << std::endl;
    }

    void const openedSuccessfully()
    {
        std::cout<< "Succesfully opened ";
    }

}