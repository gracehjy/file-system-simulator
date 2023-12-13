#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class TouchCommand: public AbstractCommand{
private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    TouchCommand(AbstractFileSystem* fileSystem, AbstractFileFactory* fileFactory);
    virtual ~TouchCommand();
    virtual void displayInfo() override;
    virtual int execute(std::string file) override;
};