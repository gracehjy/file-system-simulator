#include "mockos/CatCommand.h"
#include "mockos/BasicDisplayVisitor.h"

#include <sstream>
#include <iostream>
using namespace std;

// constructor using member initialization
CatCommand::CatCommand(AbstractFileSystem *fileSystem, AbstractFileFactory *fileFactory): fileSystem(fileSystem), fileFactory(fileFactory) {}

// destructor
CatCommand::~CatCommand(){}

// tells the user how to invoke the cat command and describes the command
void CatCommand::displayInfo() {
    cout << "cat is a utility that is useful for concatenating files; it can also be used to write to a file." << endl;
    cout << "cat can be invoked with the command: cat <filename> [-a]" << endl;
    cout << "-a will display the current contents of the file and append new content to it." << endl;
}

// executes the cat command
int CatCommand::execute(std::string file) {
    // check if -a was used after a fileName
    istringstream iss(file);
    string fileName;
    iss >> fileName;

    string a;
    iss >> a;

    AbstractFile* theFile = fileSystem->openFile(fileName);

    // make sure file exists
    if(theFile){
        if(a == "-a"){
            // print out the current contents of the file
            BasicDisplayVisitor basicDisplayVisitor;
            theFile->accept(&basicDisplayVisitor);
        }
        // prompt user to enter new data
        cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving" << endl;

        // input includes all user inputs including :wq and :q
        // newData will just include everything else
        string input;
        vector<char> newData;

        // read each input line
        while(getline(cin, input)){
            // if :wq is entered with -a as the option, save the data by appending it to the file and return success
            if (input == ":wq") {
                if (a != "-a") {
                    theFile->write(newData);
                } else {
                    theFile->append(newData);
                }
                fileSystem->closeFile(theFile);
                return success;
            }
            // if :q is entered, don't save and just return
            if(input == ":q"){
                fileSystem->closeFile(theFile);
                return success;
            }
            // if neither are entered, temporarily save the data
            newData.insert(newData.end(), input.begin(), input.end());
        }
        newData.push_back('\n');
        fileSystem->closeFile(theFile);
        return success;
    }
    // if the file does not exist, return error
    return file_does_not_exist;
}

