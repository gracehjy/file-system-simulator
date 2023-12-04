#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <string>

using namespace std;

// create a file of the given name by finding what type of file it is and then using the new keyword to create an object of the given type
AbstractFile* SimpleFileFactory::createFile(std::string fileName) {
    int dotIndex = fileName.find_last_of('.');
    string ext = fileName.substr(dotIndex+1);

    AbstractFile* newFile = nullptr;

    if(ext == "txt"){
        newFile = new TextFile(fileName);
    }
    else if(ext == "img"){
        newFile = new ImageFile(fileName);
    }

    return newFile;
}