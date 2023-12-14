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
#include "mockos/TouchCatParsingStrategy.h"
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
    RenameParsingStrategy* renameParsingStrategy = new RenameParsingStrategy();
    MacroCommand* rmMacroCommand = new MacroCommand(fileSystem);
    rmMacroCommand->setParseStrategy(renameParsingStrategy);
    rmMacroCommand->addCommand(cpCommand);
    rmMacroCommand->addCommand(rmCommand);

    // Creating the MacroCommand for 'Touch + cat'
    TouchCatParsingStrategy* touchCatParsing = new TouchCatParsingStrategy;
    MacroCommand* touchCatMacro = new MacroCommand(fileSystem);
    touchCatMacro->setParseStrategy(touchCatParsing);
    touchCatMacro->addCommand(touchCommand);
    touchCatMacro->addCommand(catCommand);

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
    commandPrompt->addCommand("rn", rmMacroCommand);

    // Adding a new MacroCommand to the CommandPrompt
    commandPrompt->addCommand("touchcat", touchCatMacro); // Add the new macro command to the command prompt

    // call run() on the commandPrompt object
    int returnVal = commandPrompt->run();

    // Clean up dynamically allocated objects
    delete touchCommand;
    delete lsCommand;
    delete rmCommand;
    delete catCommand;
    delete dsCommand;
    delete cpCommand;
    delete rmMacroCommand;
    delete renameParsingStrategy;
    delete touchCatMacro;
    delete touchCatParsing;
    delete fileFactory;
    delete fileSystem;
    delete commandPrompt;

    return returnVal;
}