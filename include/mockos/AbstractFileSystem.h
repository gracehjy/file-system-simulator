#pragma once
#include "AbstractFile.h"
#include <string>

class AbstractFileSystem{
public:
    virtual int addFile(std::string fileName, AbstractFile* file) = 0;
    virtual int deleteFile(std::string fileName) = 0;
    virtual AbstractFile* openFile(std::string fileName) = 0;
    virtual int closeFile(AbstractFile* file) = 0;
};