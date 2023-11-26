#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>

class CommandPrompt{
private:
    std::map<std::string, AbstractCommand*> commandMap;
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    CommandPrompt();
    ~CommandPrompt();
    void setFileSystem(AbstractFileSystem* fileSystem);
    void setFileFactory(AbstractFileFactory* fileFactory);
    int addCommand(std::string name, AbstractCommand* command);
    int run();
protected:
    void listCommands();
    std::string prompt();
};