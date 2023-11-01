#pragma once

#include "AbstractFile.h"

class TextFile: public AbstractFile{
protected:
    std::vector<char> fileContents;
    std::string fileName;
public:
    TextFile(std::string f);
    unsigned int getSize() override;
    std::string getName() override;
};