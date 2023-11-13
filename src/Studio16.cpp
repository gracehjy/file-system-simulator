#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFile.h"

using namespace std;

int main(){
    AbstractFile* file = new TextFile("FirstTest");
    vector<char> v = { 'h', 'i' , '!'};
    file->write(v);
    file->read();
    return 0;
}