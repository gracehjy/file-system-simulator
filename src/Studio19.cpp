#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/BasicDisplayVisitor.h"

#include <iostream>

using namespace std;

int main(){
    AbstractFileSystem* fileSystem = new SimpleFileSystem();
    AbstractFileFactory* fileFactory = new SimpleFileFactory();

    AbstractFile* file1 = fileFactory->createFile("example1.txt");
    AbstractFile* file2 = fileFactory->createFile("example2.img");

    fileSystem->addFile("example1.txt", file1);
    fileSystem->addFile("example2.img", file2);

    BasicDisplayVisitor displayVisitor;
    // Try opening, writing, and reading the files
    if (fileSystem->openFile("example1.txt")) {
        file1->write({'h', 'i', '!', '!'});
        vector<char> contents = file1->read();
        contents.push_back('*');
        file1->write(contents);
        // display file content
        file1->accept(&displayVisitor);
        fileSystem->closeFile(file1);
    } else {
        cout << "Failed to open example1.txt" << endl;
    }

    if (fileSystem->openFile("example2.img")) {
        file2->write({ 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' });
        file2->read();
        // display file content
        file2->accept(&displayVisitor);
        fileSystem->closeFile(file2);
    } else {
        cout << "Failed to open example1.txt" << endl;
    }

    return 0;
}