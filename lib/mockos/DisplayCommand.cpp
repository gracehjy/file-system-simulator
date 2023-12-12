#include "mockos/DisplayCommand.h"
#include "mockos/BasicDisplayVisitor.h"

#include <sstream>
#include <iostream>
using namespace std;

// constructor using member initialization
DisplayCommand::DisplayCommand(AbstractFileSystem *fileSystem): fileSystem(fileSystem) {}

// destructor
DisplayCommand::~DisplayCommand(){}

// tells the user how to invoke the display command and describes the command
void DisplayCommand::displayInfo() {
    cout << "Display opens a file and displays its contents." << endl;
    cout << "Display can be invoked by the command: ds <filename> [-d]" << endl;
    cout << "-d will display an unformatted version of the file's contents." << endl;
}

int DisplayCommand::execute(std::string file) {
    // check if -d was used after a fileName
    istringstream iss(file);
    string fileName;
    iss >> fileName;

    string d;
    iss >> d;

    AbstractFile* theFile = fileSystem->openFile(fileName);

    if(theFile){
        // if d option was used, display an unformatted version; else, use formatted version
        if(d == "-d"){
            vector<char> content;
            content = theFile->read();
            for(char c: content){
                cout << c;
            }
            cout << endl;
        }
        else{
            BasicDisplayVisitor basicDisplayVisitor;
            theFile->accept(&basicDisplayVisitor);
        }
        fileSystem->closeFile(theFile);
        return success;
    }
    return file_does_not_exist;
}
