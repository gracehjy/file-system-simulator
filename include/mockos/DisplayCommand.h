#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"

class DisplayCommand: public AbstractCommand{
private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    DisplayCommand(AbstractFileSystem* fileSystem, AbstractFileFactory* fileFactory);
    ~DisplayCommand();
    virtual void displayInfo() override;
    virtual int execute(std::string file) override;
};