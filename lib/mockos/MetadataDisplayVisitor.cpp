#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <iomanip>

using namespace std;

// for both functions below, we will output the file name, file size, and file type
// we will use left and setw to help with alignment

void MetadataDisplayVisitor::visit_TextFile(TextFile *file) {
    cout << left << setw(20) << file->getName()  << setw(10) << "text" << setw(10) << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile *file) {
    cout << left << setw(20) << file->getName()  << setw(10) << "image" << setw(10) << file->getSize() << endl;
}