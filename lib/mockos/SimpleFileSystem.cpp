#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <string>
#include <iostream>
using namespace std;

// add a given file into the map of files if it doesn't already exist
int SimpleFileSystem::addFile(std::string fileName, AbstractFile *file) {
    if(files.find(fileName) != files.end()){
        return file_already_exists;
    }
    if(file == nullptr){
        return pointer_is_null;
    }
    files.insert({fileName, file});
    return success;
}

// open a given filename if it exists in the map of files by adding it into the openFiles set
AbstractFile *SimpleFileSystem::openFile(std::string fileName) {
    if(files.find(fileName) != files.end()){
        if(openFiles.find(files.find(fileName)->second) == openFiles.end()){
            openFiles.insert(files.find(fileName)->second);
            return files.find(fileName)->second;
        }
    }
    return nullptr;
}

// close a file by erasing it from the openFiles set if it exists
int SimpleFileSystem::closeFile(AbstractFile *file) {
    if(openFiles.find(file) != openFiles.end()){
        openFiles.erase(file);
        return success;
    }
    return file_not_open;
}

// delete a file if it exists in the map of files
int SimpleFileSystem::deleteFile(std::string fileName) {
    auto f = files.find(fileName);
    if(f != files.end()){
        if(openFiles.find(f->second) == openFiles.end()){
            files.erase(f);
            delete f->second;
            return success;
        }
        else{
            return cant_delete_open_file;
        }
    }
    return file_does_not_exist;
}

// return a set<string> containing the names of all the files
set<string> SimpleFileSystem::getFileNames() {
    set<string> fileNames;
    for(auto file : files){
        fileNames.insert(file.first);
    }
    return fileNames;
}