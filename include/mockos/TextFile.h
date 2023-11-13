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
    int write(std::vector<char>) override;
    int append(std::vector<char>) override;
    void read() override;
};