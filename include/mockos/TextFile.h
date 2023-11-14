#pragma once

#include "AbstractFile.h"

class TextFile: public AbstractFile{
protected:
    std::vector<char> fileContents;
    std::string fileName;
public:
    TextFile(std::string file);
    unsigned int getSize() override;
    std::string getName() override;
    int write(std::vector<char> contents) override;
    int append(std::vector<char> additionalContent) override;
    void read() override;
};