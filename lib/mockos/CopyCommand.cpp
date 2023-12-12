#include "mockos/CopyCommand.h"

#include <sstream>
#include <iostream>

using namespace std;

// construct using member initialization
CopyCommand::CopyCommand(AbstractFileSystem *fileSystem, AbstractFileFactory *fileFactory):
fileSystem(fileSystem), fileFactory(fileFactory){}

// destructor
CopyCommand::~CopyCommand(){};

// tells the user how to invoke the copy command and describes the command
void CopyCommand::displayInfo() {
    cout << "cp will copy a file that exists in the file system and add the copy to the file system with a different name." << endl;
    cout << "cp can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension" << endl;
}

// executes the copy command
int CopyCommand::execute(std::string file) {
    // get the names of the files to copy and the new file to make
    istringstream iss(file);
    string fileToCopy;
    iss >> fileToCopy;

    string newFileName;
    iss >> newFileName;

    // find what the ext is
    int dotIndex = fileToCopy.find_last_of('.');
    string ext = fileToCopy.substr(dotIndex+1);

    // add ext to inputted newFileName and check to see if the file names are unique
    newFileName += ("." + ext);
    if(newFileName == fileToCopy){
        cout << "Error: must use a unique name" << endl;
        return need_a_unique_name;
    }

    // open the original file
    AbstractFile* originalFile = fileSystem->openFile(fileToCopy);
    if(originalFile == nullptr){
        cout << "Error: the original file to be copied does not exist" << endl;
        return file_does_not_exist;
    }

    // create the new file using the copy methods we implemented for each type of ext
    AbstractFile* copyFile = originalFile->copy(newFileName);
    fileSystem->closeFile(originalFile);

    // add the new file to the file system
    int returnVal = fileSystem->addFile(newFileName, copyFile);
    if(returnVal != success){
        cout << "Error: failed to add the new file to the file system" << endl;
        return failed_to_add_file;
    }

    return success;
}