#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile *file) {
    cout << "File Name: " << file->getName() << endl;
    cout << "Size: " << file->getSize() << " bytes" << endl;
    cout << "Type: text" << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile *file) {
    cout << "File Name: " << file->getName() << endl;
    cout << "Size: " << file->getSize() << " bytes" << endl;
    cout << "Type: image" << endl;
}