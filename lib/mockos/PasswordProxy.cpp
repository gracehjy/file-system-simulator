#include "mockos/PasswordProxy.h"
#include <iostream>

using namespace std;

// constructor: member initialization list
PasswordProxy::PasswordProxy(AbstractFile *file, std::string password): file(file), password(password)
{}

// destructor: delete pointer to the real file
PasswordProxy::~PasswordProxy(){
    delete file;
}

// prompt user to enter a password
string PasswordProxy::passwordPrompt() {
    string pw;
    cout << "Input a password: ";
    cin >> pw;
    // clear the input buffer to discard remaining characters ('/n') after entering a password
    // source: https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return pw;
}

// check to see if the entered password matches
bool PasswordProxy::passwordMatch(std::string enteredPassword) {
    return enteredPassword == this->password;
}

// returns the contents of the file if the password the user entered is correct
vector<char> PasswordProxy::read() {
    string pw = passwordPrompt();
    bool isCorrect = passwordMatch(pw);

    vector<char> fileContent;
    if(isCorrect){
        fileContent = file->read();
        return fileContent;
    }

    cout << "Incorrect Password" << endl;
    return fileContent;
}

// writes to the file if the password the user entered is correct
int PasswordProxy::write(std::vector<char> content) {
    string pw = passwordPrompt();
    bool isCorrect = passwordMatch(pw);

    if(isCorrect){
        file->write(content);
        return success;
    }
    cout << "Incorrect Password" << endl;
    return incorrect_password;
}

// appends to the file if the password the user entered is correct
int PasswordProxy::append(std::vector<char> additionalContent) {
    string pw = passwordPrompt();
    bool isCorrect = passwordMatch(pw);

    if(isCorrect){
        file->append(additionalContent);
        return success;
    }
    cout << "Incorrect Password" << endl;
    return incorrect_password;
}

// return the size of the file
unsigned int PasswordProxy::getSize() {
    return file->getSize();
}

// return the name of the file
string PasswordProxy::getName() {
    return file->getName();
}

// calls accept on the file if the password entered by the user is correct
void PasswordProxy::accept(AbstractFileVisitor *visitor) {
    string pw = passwordPrompt();
    bool isCorrect = passwordMatch(pw);
    if(isCorrect){
        file->accept(visitor);
    }
}

AbstractFile *PasswordProxy::copy(std::string newFileName) {
    AbstractFile* name = file->copy(newFileName);
    PasswordProxy* newFile = new PasswordProxy(name, this->password);
    return newFile;
}
