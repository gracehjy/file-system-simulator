#include "mockos/LSCommand.h"
#include "mockos/MetadataDisplayVisitor.h"

#include <iostream>
#include <iomanip>
using namespace std;

// constructor using member initialization
LSCommand::LSCommand(AbstractFileSystem *fileSystem): fileSystem(fileSystem){}

// destructor
LSCommand::~LSCommand(){}

// tells the user how to invoke the ls command and describes the command
void LSCommand::displayInfo() {
    cout << "ls displays the names of all files currently in the file system." << endl;
    cout << "ls -m displays each file name along with the metadata associated with each file." << endl;
}

// displays the names of all files currently in the file system
int LSCommand::execute(std::string file) {
    // if the additional input is -m, we want to display metadata for each file
    // we will make use of the MetadataDisplayVisitor for each file in the file system
    if(file == "-m"){
        MetadataDisplayVisitor metadataDisplayVisitor;
        set<string> fileNames = fileSystem->getFileNames();
        for(auto fileName : fileNames){
            AbstractFile* file = fileSystem->openFile(fileName);
            file->accept(&metadataDisplayVisitor);
            fileSystem->closeFile(file);
        }
    }
    // for the normal command, we want to display two file names per line so we will keep track of this using a count variable
    else if(file == ""){
        set<string> fileNames = fileSystem->getFileNames();
        int count = 0;
        for(auto fileName: fileNames){
            // align each column using setw and left for left-alignment
            cout << left << setw(20) << fileName << " ";
            count++;
            if(count == 2){
                cout<<endl;
                count = 0;
            }
        }
        cout << endl;
    }
    else{
        return ls_command_failed;
    }
    return success;
}

