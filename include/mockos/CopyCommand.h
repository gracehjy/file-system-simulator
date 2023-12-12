#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"

class CopyCommand: public AbstractCommand{
private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    CopyCommand(AbstractFileSystem* fileSystem);
    ~CopyCommand();
    virtual void displayInfo() override;
    virtual int execute(std::string file) override;
};