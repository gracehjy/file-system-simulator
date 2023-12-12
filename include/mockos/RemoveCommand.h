#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"

class RemoveCommand: public AbstractCommand{
private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    RemoveCommand(AbstractFileSystem* fileSystem);
    ~RemoveCommand();
    virtual void displayInfo() override;
    virtual int execute(std::string file) override;
};