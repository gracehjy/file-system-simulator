#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/AbstractFile.h"
#include "mockos/SimpleFileSystem.h"

#include <iostream>
using namespace std;

int main(){
    AbstractFileSystem* fileSystem = new SimpleFileSystem();
    AbstractFileFactory* fileFactory = new SimpleFileFactory();

    AbstractFile* file1 = fileFactory->createFile("file1.txt");
    AbstractFile* file2 = fileFactory->createFile("file2.txt");

    fileSystem->addFile("file1.txt", file1);
    fileSystem->addFile("file2.txt",file2);

    // Try opening, writing, and reading the files
    if (fileSystem->openFile("file1.txt")) {
        file1->write({'h', 'i', '!'});
        file1->read();
        fileSystem->closeFile(file1);
    } else {
        cout << "Failed to open file1.txt" << endl;
    }

    if (fileSystem->openFile("file2.txt")) {
        file2->write({'b', 'y', 'e', '!'});
        file2->read();
        fileSystem->closeFile(file2);
    } else {
        cout << "Failed to open file2.txt" << endl;
    }

    fileSystem->deleteFile("file1.txt");
    fileSystem->deleteFile("file2.txt");

    return 0;
}