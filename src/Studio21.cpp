#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"

#include <iostream>
using namespace std;

int main(){
    // dynamically allocate a SimpleFileSystem, a SimpleFileFactory, and a TouchCommand object
    SimpleFileSystem* fileSystem = new SimpleFileSystem();
    SimpleFileFactory* fileFactory = new SimpleFileFactory();
    TouchCommand* touchCommand = new TouchCommand(fileSystem, fileFactory);

    // create a variable of type CommandPrompt and configure it with the above created objects
    CommandPrompt* commandPrompt = new CommandPrompt();
    commandPrompt->setFileFactory(fileFactory);
    commandPrompt->setFileSystem(fileSystem);
    commandPrompt->addCommand("touch", touchCommand);

    // call run() on the commandPrompt object
    commandPrompt->run();

    // verify “touch” worked correctly by trying to open the file it created.
    cout << "Attempting to open the file created by touch..." << endl;
    AbstractFile* openedFile = fileSystem->openFile("file.txt");

    if (openedFile) {
        cout << "File opened successfully!" << endl;
        //You can perform further actions with the opened file if needed
    } else {
        cout << "Error opening the file." << endl;
    }

    // Clean up dynamically allocated objects
    delete touchCommand;
    delete fileFactory;
    delete fileSystem;
    delete commandPrompt;

    return success;
}