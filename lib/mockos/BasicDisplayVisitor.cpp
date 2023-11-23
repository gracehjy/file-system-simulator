#include "mockos/BasicDisplayVisitor.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include <iostream>

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile *file) {
    for(int row = file->imageSize - 1; row >= 0; row--){
        for(int col = 0; col < file->imageSize; col++){
            unsigned int index = file->imageSize*row + col;
            cout << file->read()[index];
        }
        cout << endl;
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_TextFile(TextFile *file) {
    for(char c : file->read()){
        cout << c;
    }
    cout << endl;
}