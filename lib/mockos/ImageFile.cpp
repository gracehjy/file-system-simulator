#include "../../include/mockos/ImageFile.h"
#include <string>
#include <iostream>
using namespace std;

// constructor with member initialization
ImageFile::ImageFile(string file): fileName(file), imageSize(0) {}

// return size
unsigned int ImageFile::getSize() {
    return fileContents.size();
}

// return file name
string ImageFile::getName() {
    return fileName;
}

// write a vector of characters to the image file
int ImageFile::write(vector<char> contents) {
    imageSize = contents.back() - '0';

    // check for size mismatch
    if(imageSize * imageSize != contents.size() - 1){
        return size_mismatch;
    }

    // push each valid char in the vector into fileContents
    for(int i = 0; i < contents.size() - 1; i++){
        fileContents.push_back(contents[i]);
        if(fileContents[i] != 'X' && fileContents[i] != ' '){
            fileContents.clear();
            imageSize = 0;
            return invalid_chars;
        }
    }
    return success;
}

// if a user tries to append, return an error
int ImageFile::append(vector<char> additionalContent) {
    return file_type_not_supported;
}

// read the image file
std::vector<char> ImageFile::read() {
    return fileContents;
}

// call visit_ImageFile on the parameter
void ImageFile::accept(AbstractFileVisitor *visitor) {
    visitor->visit_ImageFile(this);
}
