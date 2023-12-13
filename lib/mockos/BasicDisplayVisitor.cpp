#include "mockos/BasicDisplayVisitor.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include <iostream>
#include <cmath>

using namespace std;

// visit the image file and read/output each index
void BasicDisplayVisitor::visit_ImageFile(ImageFile *file) {
    vector<char> content = file->read();
    int area = file->getSize();

    // when we need to input a newline
    int size = sqrt(area);

    // output each index
    for(int index = start; index < area; index++){
        cout << content[index];
        int nextIndex = index + addOne;
        if(nextIndex % size == noRemainders){
            cout << endl;
        }
    }
}

// visit the text file and read/output each character
void BasicDisplayVisitor::visit_TextFile(TextFile *file) {
    for(char c : file->read()){
        cout << c;
    }
    cout << endl;
}