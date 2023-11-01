#include "../../include/mockos/TextFile.h"
#include <string>
using namespace std;

TextFile::TextFile(string f): fileName(f)
{}

unsigned int TextFile::getSize(){
    return fileContents.size();
}

string TextFile::getName() {
    return fileName;
}

