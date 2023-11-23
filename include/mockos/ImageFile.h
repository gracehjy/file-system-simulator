#pragma once

#include "AbstractFile.h"

class ImageFile: public AbstractFile{
protected:
    std::vector<char> fileContents;
    std::string fileName;
public:
    char imageSize;
    ImageFile(std::string file);
    unsigned int getSize() override;
    std::string getName() override;
    int write(std::vector<char> contents) override;
    int append(std::vector<char> additionalContent) override;
    std::vector<char> read() override;
    void accept(AbstractFileVisitor* visitor) override;
};