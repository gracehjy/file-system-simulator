#include "mockos/TouchCommand.h"
#include "mockos/PasswordProxy.h"

#include <iostream>
#include <sstream>
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
    cout << "to create password protected files, touch can be invoked with the command: touch <filename> -p" << endl;
}

// asks the file factory to create a file with the provided filename
int TouchCommand::execute(string file) {
    // check if -p was used after a fileName
    istringstream iss(file);
    string fileName;
    iss >> fileName;

    string p;
    iss >> p;

    AbstractFile* newFile;

    // if -p, create a PasswordProxy object, otherwise create a file as normally
    if(p == "-p"){
        string password;
        cout << "What is the password?" << endl;
        cin >> password;
        newFile = new PasswordProxy(fileFactory->createFile(fileName), password);

        // clear the input buffer to discard remaining characters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else{
        newFile = fileFactory->createFile(fileName);
    }

    // if the file was created, add if to the filesystem. if we fail to add it, delete the file and return an error
    if(newFile){
        int returnVal = fileSystem->addFile(fileName, newFile);
        if(returnVal != success){
            delete newFile;
            cout << "failed to add file" << endl;
            return failed_to_add_file;
        }
        return success;
    }

    // if the file was not created, return an error
    cout << "failed to create file" << endl;
    return failed_to_create_file;
}
