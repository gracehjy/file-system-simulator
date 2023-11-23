#pragma once
#include "AbstractFile.h"
#include <string>

class AbstractFileFactory{
public:
    virtual AbstractFile* createFile(std::string fileName) = 0;
    virtual ~AbstractFileFactory() = default;
};