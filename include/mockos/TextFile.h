#pragma once

#include "AbstractFile.h"
#include <vector>
#include <string>

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
    std::vector<char> read() override;
    void accept(AbstractFileVisitor* visitor) override;
};