#pragma once
#include "AbstractFile.h"
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"

class MacroCommand: public AbstractCommand{
private:
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* parsePtr;
    AbstractFileSystem* fileSystem;
public:
    MacroCommand(AbstractFileSystem* fileSystem);
    virtual ~MacroCommand();
    virtual int execute(std::string file) override;
    virtual void displayInfo() override;

    void addCommand(AbstractCommand* command);
    void setParseStrategy(AbstractParsingStrategy* ptr);
};