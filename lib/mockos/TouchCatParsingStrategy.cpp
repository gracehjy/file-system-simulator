#include "mockos/TouchCatParsingStrategy.h"
#include <iostream>
#include <sstream>
using namespace std;

std::vector<std::string> TouchCatParsingStrategy::parse(const std::string input) {
    std::istringstream iss(input);
    std::string fileName;
    std::string option;
    iss >> fileName;

    std::vector<std::string> commands;
    std::string touchCommand = fileName;
    std::string catCommand = fileName;

    while (iss >> option) {
        if (option == "-p") {  // Option for touch command password proxy
            touchCommand += " -p";
        }
    }

    commands.push_back(touchCommand);
    commands.push_back(catCommand);

    return commands;
}
