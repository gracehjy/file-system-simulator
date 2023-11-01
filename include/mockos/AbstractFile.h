#pragma once

#include <vector>
#include <string>

class AbstractFile{
public:
    virtual void read() = 0;
    virtual int write(std::vector<char>) = 0;
    virtual int append(std::vector<char>) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
};