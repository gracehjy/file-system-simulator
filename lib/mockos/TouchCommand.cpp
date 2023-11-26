#include "mockos/TouchCommand.h"

#include <iostream>
using namespace std;

// constructor: member initialization list
TouchCommand::TouchCommand(AbstractFileSystem *fileSystem, AbstractFileFactory *fileFactory):
fileSystem(fileSystem), fileFactory(fileFactory)
{}

// compiler defined destructor
TouchCommand::~TouchCommand() {}

// tells the user how to invoke the touch command and describes the command
void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

// asks the file factory to create a file with the provided filename
int TouchCommand::execute(string file) {
    AbstractFile* newFile = fileFactory->createFile(file);
    if(newFile){
        int returnVal = fileSystem->addFile(file, newFile);
        if(returnVal != success){
            delete newFile;
            cout << "failed to add file" << endl;
            return failed_to_add_file;
        }
        return success;
    }
    cout << "failed to create file" << endl;
    return failed_to_create_file;
}
