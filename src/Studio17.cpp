#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFile.h"
#include "mockos/SimpleFileSystem.h"

using namespace std;

int main(){
//    AbstractFile* file = new ImageFile("Image File");
//    vector<char> v =  {'X', ' ', 'X', 'P', 'X', ' ', 'X',' ', 'X', '3' };
//    int writeResult = file->write(v);
//    if(writeResult != success){
//        return writeResult;
//    }
//    file->read();

    SimpleFileSystem fileSystem;
    AbstractFile* textFile = new TextFile("test.txt");
    AbstractFile* imageFile = new ImageFile("test.img");

    fileSystem.addFile("test.txt", textFile);
    fileSystem.addFile("test.img", imageFile);

    // Create files
    fileSystem.createFile("newTextFile.txt");
    fileSystem.createFile("newImageFile.img");

    // Open, write, read, and delete files
    AbstractFile* openedFile = fileSystem.openFile("test.txt");
    if (openedFile) {
        openedFile->write({'h', 'i', '!'});
        openedFile->read();
        fileSystem.closeFile(openedFile);
    }

    openedFile = fileSystem.openFile("newTextFile.txt");
    if (openedFile) {
        openedFile->write({'n', 'e', 'w'});
        openedFile->read();
        fileSystem.closeFile(openedFile);
    }

    openedFile = fileSystem.openFile("test.img");
    if (openedFile) {
        openedFile->write({ 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' });
        openedFile->read();
        fileSystem.closeFile(openedFile);
    }

    fileSystem.deleteFile("test.txt");
    fileSystem.deleteFile("newTextFile.txt");
    fileSystem.deleteFile("test.img");
    fileSystem.deleteFile("newImageFile.img");
    return 0;
}