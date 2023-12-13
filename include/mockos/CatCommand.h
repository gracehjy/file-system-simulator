#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"

class CatCommand: public AbstractCommand{
private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    CatCommand(AbstractFileSystem* fileSystem);
    virtual ~CatCommand();
    virtual void displayInfo() override;
    virtual int execute(std::string file) override;
};