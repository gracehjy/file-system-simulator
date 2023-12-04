#include "AbstractFileSystem.h"
#include <map>

class SimpleFileSystem: public AbstractFileSystem {
protected:
    std::map<std::string , AbstractFile*> files;
    std::set<AbstractFile*> openFiles;
public:
    virtual int addFile(std::string fileName, AbstractFile *file) override;
    virtual AbstractFile * openFile(std::string fileName) override;
    virtual int closeFile(AbstractFile *file) override;
    virtual int deleteFile(std::string fileName) override;
    virtual std::set<std::string> getFileNames() override;
};