#include "AbstractFileSystem.h"
#include <string>
#include <map>
#include <set>

class SimpleFileSystem: public AbstractFileSystem {
protected:
    std::map<std::string , AbstractFile*> files;
    std::set<AbstractFile*> openFiles;
public:
    int addFile(std::string fileName, AbstractFile *file) override;
    int createFile(std::string fileName) override;
    AbstractFile * openFile(std::string fileName) override;
    int closeFile(AbstractFile *file) override;
    int deleteFile(std::string fileName) override;
};