#include "../../include/mockos/ImageFile.h"
#include <string>
#include <iostream>
using namespace std;

ImageFile::ImageFile(string file): fileName(file), imageSize(0) {}

unsigned int ImageFile::getSize() {
    return fileContents.size();
}

string ImageFile::getName() {
    return fileName;
}

int ImageFile::write(vector<char> contents) {
    imageSize = contents.back() - '0';

    if(imageSize * imageSize != contents.size() - 1){
        return size_mismatch;
    }

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

int ImageFile::append(vector<char> additionalContent) {
    return file_type_not_supported;
}

std::vector<char> ImageFile::read() {
    return fileContents;
}

void ImageFile::accept(AbstractFileVisitor *visitor) {
    visitor->visit_ImageFile(this);
}
