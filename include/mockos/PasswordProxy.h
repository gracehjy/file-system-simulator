#pragma once
#include "AbstractFile.h"
#include <string>

class PasswordProxy: public AbstractFile{
private:
    AbstractFile* file;
    std::string password;
public:
    PasswordProxy(AbstractFile* file, std::string password);
    ~PasswordProxy();

    // functions inherited
    virtual std::vector<char> read() override;
    virtual int write(std::vector<char> content) override;
    virtual int append(std::vector<char> additionalContent) override;
    virtual unsigned int getSize() override;
    virtual std::string getName() override;
    virtual void accept(AbstractFileVisitor* visitor) override;
    AbstractFile* copy(std::string newFileName) override;
protected:
    std::string passwordPrompt();
    bool passwordMatch(std::string enteredPassword);
};