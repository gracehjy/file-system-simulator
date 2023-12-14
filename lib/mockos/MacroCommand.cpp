#include "mockos/MacroCommand.h"

#include <sstream>
#include <iostream>

using namespace std;

// constructor using member initialization
MacroCommand::MacroCommand(AbstractFileSystem* fileSystem): fileSystem(fileSystem), parsePtr(nullptr) {}

// destructor: delete all the commands and clear the vector of commands
MacroCommand::~MacroCommand() {}

void MacroCommand::displayInfo() {
    cout << "Macro Commands:"
            "\nrn changes the name of an existing file, rn can be invoked with the command: rn <existing_file> <new_name_with_no_extension>"
            "\ntouchcat creates a file and allows for an immediate edit, touchcat can be invoked with the command: touchcat <filename>" << endl;
}
// executes the macro command
int MacroCommand::execute(std::string file) {
    // ask the ParsingStrategy object to parse the input provided
    vector<string> parsedInputs = parsePtr->parse(file);

    // for each individual command, call the command's execute function with the corresponding input from parsedInputs
    for(int i = 0; i < commands.size(); i++){
        int result = commands[i]->execute(parsedInputs[i]);
        if(result != success){
            return result;
        }
    }
    return success;
}

// takes a pointer to an AbstractCommand and pushes it to the end of its vector of commands
void MacroCommand::addCommand(AbstractCommand *command) {
    this->commands.push_back(command);
}

// sets parsePtr to the parameter given
void MacroCommand::setParseStrategy(AbstractParsingStrategy* ptr){
    this->parsePtr = ptr;
}
