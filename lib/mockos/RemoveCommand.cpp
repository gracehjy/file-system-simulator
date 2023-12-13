#include "mockos/RemoveCommand.h"

#include <iostream>
using namespace std;

// constructor using member initialization list
RemoveCommand::RemoveCommand(AbstractFileSystem *fileSystem):
fileSystem(fileSystem){}

//destructor
RemoveCommand::~RemoveCommand(){}

// tells the user how to invoke the rm command and describes the command
void RemoveCommand::displayInfo() {
    cout << "rm removes a file from the file system, rm can be invoked with the command: rm <filename>" << endl;
}

// executes the remove command
int RemoveCommand::execute(std::string file) {
    set<string> fileNames = fileSystem->getFileNames();
    // if the file exists in the system, remove it
    if(fileNames.find(file) != fileNames.end()){
        int returnVal = fileSystem->deleteFile(file);
        return returnVal;
    }
    return rm_command_failed;
}