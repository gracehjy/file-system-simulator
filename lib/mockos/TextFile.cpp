#include "../../include/mockos/TextFile.h"
#include <string>
#include <iostream>
using namespace std;

// constructor using member initialization
TextFile::TextFile(string file): fileName(file)
{}

// return text file size
unsigned int TextFile::getSize(){
    return fileContents.size();
}

// return file name
string TextFile::getName() {
    return fileName;
}

// write a vector of characters to the text file
int TextFile::write(vector<char> contents) {
    fileContents = contents;
    return success;
}

// append a vector of characters to the current file content
int TextFile::append(vector<char> additionalContent) {
    fileContents.insert(fileContents.end(),additionalContent.begin(),additionalContent.end());
    return success;
}

// read the file content
std::vector<char> TextFile::read() {
    return fileContents;
}

// call visit_TextFile() on the given parameter
void TextFile::accept(AbstractFileVisitor *visitor) {
    visitor->visit_TextFile(this);
}

