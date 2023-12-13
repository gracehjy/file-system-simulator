#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include <iostream>
using namespace std;

int main(){
    // dynamically allocate a SimpleFileSystem, a SimpleFileFactory, and a TouchCommand object
    SimpleFileSystem* fileSystem = new SimpleFileSystem();
    SimpleFileFactory* fileFactory = new SimpleFileFactory();
    TouchCommand* touchCommand = new TouchCommand(fileSystem, fileFactory);
    LSCommand* lsCommand = new LSCommand(fileSystem);
    RemoveCommand* rmCommand = new RemoveCommand(fileSystem);
    CatCommand* catCommand = new CatCommand(fileSystem);
    DisplayCommand* dsCommand = new DisplayCommand(fileSystem);
    CopyCommand* cpCommand = new CopyCommand(fileSystem);

    // update main to create a MacroCommand object configured with a RenameParsingStrategy object as its AbstractParsingStrategy and a
    // CopyCommand as well as a RemoveCommand object as its command objects
    RenameParsingStrategy* renameParsingStrategy;
    MacroCommand* macroCommand = new MacroCommand(fileSystem);
    macroCommand->setParseStrategy(renameParsingStrategy);
    macroCommand->addCommand(cpCommand);
    macroCommand->addCommand(rmCommand);

    // create a variable of type CommandPrompt and configure it with the above created objects
    CommandPrompt* commandPrompt = new CommandPrompt();
    commandPrompt->setFileFactory(fileFactory);
    commandPrompt->setFileSystem(fileSystem);
    commandPrompt->addCommand("touch", touchCommand);
    commandPrompt->addCommand("ls", lsCommand);
    commandPrompt->addCommand("rm", rmCommand);
    commandPrompt->addCommand("cat", catCommand);
    commandPrompt->addCommand("ds", dsCommand);
    commandPrompt->addCommand("cp", cpCommand);

    // add macroCommand to the commandPrompt so it will be invoked when the user provides "rn" as input
    commandPrompt->addCommand("rn", macroCommand);


    // call run() on the commandPrompt object
    commandPrompt->run();

    // Clean up dynamically allocated objects
    delete touchCommand;
    delete lsCommand;
    delete rmCommand;
    delete catCommand;
    delete dsCommand;
    delete cpCommand;
    delete macroCommand;
    delete fileFactory;
    delete fileSystem;
    delete commandPrompt;

    return success;
}