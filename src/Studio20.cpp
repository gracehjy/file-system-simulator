#include "mockos/PasswordProxy.h"
#include "mockos/TextFile.h"
#include "mockos/BasicDisplayVisitor.h"

#include <iostream>

using namespace std;

int main(){
    AbstractFile* file = new TextFile("test.txt");

    PasswordProxy* passwordProxy = new PasswordProxy(file, "supershy");

    BasicDisplayVisitor displayVisitor;

    //write to the file
    int returnVal = passwordProxy->write({'h', 'i', '!', '!'});
    if(returnVal != success){
        return returnVal;
    }

    // read the file
    vector<char> content = passwordProxy->read();

    // display the contents of the file
    passwordProxy->accept(&displayVisitor);

    delete passwordProxy;
    return success;
}