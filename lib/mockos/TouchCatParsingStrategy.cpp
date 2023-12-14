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
    std::string touchCommand = "touch " + fileName;
    std::string catCommand = "cat " + fileName;

    while (iss >> option) {
        if (option == "-p") {  // Option for touch command
            touchCommand += " -p";
        }
        else if (option == "-a") {  // Option for cat command
            catCommand += " -a";
        }
    }

    commands.push_back(touchCommand);
    commands.push_back(catCommand);

    return commands;
}
