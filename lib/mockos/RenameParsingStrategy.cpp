#include "mockos/RenameParsingStrategy.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// parses the input and returns a vector where index 0 is <existing_file> <new_name> and index 1 is <existing_file>
vector<string> RenameParsingStrategy::parse(std::string input) {
    vector<string> parsedInputs;
    istringstream iss(input);
    string existingFile;
    string newName;

    // extract the existing file name and the new name from the input
    iss >> existingFile;
    iss >> newName;

    // index 0 should contain <existing_file> <new_name>
    parsedInputs.push_back(existingFile + " " + newName);
    // index 1 should contain <existing_file>
    parsedInputs.push_back(existingFile);

    return parsedInputs;
}