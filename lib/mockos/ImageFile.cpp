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
    // get the size of the vector
    int t = contents[contents.size() - 1] - '0';

    // check for size mismatch
    if(t * t != contents.size() - 1){
        fileContents.clear();
        imageSize = '0';
        cout << "Error: image size mismatch. Provided size: " << t*t << ". Actual size: " << contents.size() - 1 << endl;
        return size_mismatch;
    }

    // we want to overwrite current content so we have to clear the current content
    fileContents.clear();

    // push each valid char in the vector into fileContents
    for(int i = 0; i < contents.size() - 1; i++){
        if(contents[i] != 'X' && contents[i] != ' '){
            fileContents.clear();
            imageSize = '0';
            cout << "Error: invalid characters" << endl;
            return invalid_chars;
        }
        fileContents.push_back(contents[i]);
    }
    return success;
}

// if a user tries to append, return an error
int ImageFile::append(vector<char> additionalContent) {
    cout << "Error: cannot append to image files" << endl;
    return file_type_not_supported;
}

// read the image file
vector<char> ImageFile::read() {
    return fileContents;
}

// call visit_ImageFile on the parameter
void ImageFile::accept(AbstractFileVisitor *visitor) {
    visitor->visit_ImageFile(this);
}

// copy image file contents into a new image file
AbstractFile *ImageFile::copy(std::string newFileName) {
    ImageFile* newFile = new ImageFile(newFileName);
    newFile->fileContents = this->read();
    newFile->imageSize = this->getSize();
    return newFile;
}
