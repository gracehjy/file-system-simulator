#include "mockos/CommandPrompt.h"

#include <iostream>
#include <sstream>
using namespace std;

// constructor: member initialization list
CommandPrompt::CommandPrompt(): fileFactory(nullptr), fileSystem(nullptr)
{}

// compiler defined destructor
CommandPrompt::~CommandPrompt(){}

// sets the AbstractFileSystem pointer member variable equal to the parameter passed
void CommandPrompt::setFileSystem(AbstractFileSystem *fileSystem) {
    this->fileSystem = fileSystem;
}

// sets the AbstractFileFactory pointer member variable equal to the parameter passed
void CommandPrompt::setFileFactory(AbstractFileFactory *fileFactory) {
    this->fileFactory = fileFactory;
}

// inserts the parameters passed to this function as a pair into the map of commands
// returns success if the insertion was successful, returns a non-zero value otherwise
int CommandPrompt::addCommand(std::string name , AbstractCommand *command) {
    auto result = commandMap.insert(make_pair(name, command));
    if(result.second){
        return success;
    }
    return failed_to_add_command;
}

// iterates over each command in the map and prints the command’s name
void CommandPrompt::listCommands() {
    cout << "Commands: " << endl;
    for(auto command : commandMap){
        cout << command.first << endl;
    }
}

// prompts the user to input a valid command, "q" to quit, "help" for a list of commands, "help <command name>" for details about a specific command
string CommandPrompt::prompt() {
    cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
    cout << "$  ";

    string userInput;
    getline(cin, userInput);
    return userInput;
}

// repeatedly call prompt and store the result into a string
int CommandPrompt::run() {
    while(true){
        string userInput = prompt();
        // if user quits, return
        if(userInput == "q"){
            cout << "User has quit" << endl;
            return user_quit;
        }
        // if user needs help, list the commands
        else if(userInput == "help"){
            listCommands();
        }
        else{
            // check to see input is 1 word long
            bool isOneWordLong = true;
            for(char c : userInput){
                if(c == ' '){
                    isOneWordLong = false;
                    break;
                }
            }

            // if input is only one word long, search the map for the command that matches the input
            if(isOneWordLong){
                bool commandExists = false;
                for(auto command : commandMap){
                    if(command.first == userInput){
                        commandExists = true;
                        int returnVal = command.second->execute("");
                        if(returnVal != success){
                            cout << "Command failed." << endl;
                        }
                        break;
                    }
                }
                // if the command does not exist, print a valid error message
                if(!commandExists){
                    cout << "Invalid command." << endl;
                }
            }
            else {
                // if input is longer than one word, wrap the input in an istringstream and extract the first word into a string
                istringstream iss(userInput);
                string firstWord, secondWord;

                // ws gets rid of whitespace
                iss >> firstWord >> ws;
                getline(iss, secondWord);

                // if first word is "help", extract a second string and see if that command exists
                if (firstWord == "help") {
                    bool commandExists = false;
                    for (auto command: commandMap) {
                        if (command.first == secondWord) {
                            commandExists = true;
                            command.second->displayInfo();
                            break;
                        }
                    }
                    // if the command does not exist, print a valid error message
                    if(!commandExists){
                        cout << "Invalid command." << endl;
                    }
                }
                else{
                    // first word is the command name
                    bool commandExists = false;
                    for(auto command : commandMap){
                        if(command.first == firstWord){
                            commandExists = true;
                            int returnVal = command.second->execute(secondWord);
                            if(returnVal != success){
                                cout << "Command failed." << endl;
                            }
                            break;
                        }
                    }
                    // if the command does not exist, print a valid error message
                    if(!commandExists){
                        cout << "Invalid command." << endl;
                    }
                }
            }
        }
    }
}



