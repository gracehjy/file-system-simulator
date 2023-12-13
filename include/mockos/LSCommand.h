#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"

class LSCommand: public AbstractCommand{
private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    LSCommand(AbstractFileSystem* fileSystem);
    virtual ~LSCommand();
    virtual void displayInfo() override;
    virtual int execute(std::string file) override;
};