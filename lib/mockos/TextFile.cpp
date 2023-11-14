#include "../../include/mockos/TextFile.h"
#include <string>
#include <iostream>
using namespace std;

TextFile::TextFile(string file): fileName(file)
{}

unsigned int TextFile::getSize(){
    return fileContents.size();
}

string TextFile::getName() {
    return fileName;
}

int TextFile::write(vector<char> contents) {
    fileContents = contents;
    return success;
}

int TextFile::append(vector<char> additionalContent) {
    fileContents.insert(fileContents.end(),additionalContent.begin(),additionalContent.end());
    return success;
}

void TextFile::read() {
    for(char c : fileContents){
        cout << c;
    }
}

