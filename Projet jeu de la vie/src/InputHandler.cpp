#include "InputHandler.h"
#include <iostream>

char InputHandler::getInput() const
{
    std::cout << "\nCommands: (n)ext | (r)andom | (c)lear | (q)uit\n> ";
    char c;
    std::cin >> c;
    return c;
}
