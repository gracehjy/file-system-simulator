#pragma once
#include "AbstractFileVisitor.h"
#include <vector>
#include <string>

enum returnVals{success, size_mismatch, invalid_chars, file_type_not_supported, file_already_exists,
        pointer_is_null, invalid_file_extension, file_not_open, cant_delete_open_file, file_does_not_exist, incorrect_password,
        failed_to_add_command, user_quit, failed_to_add_file, failed_to_create_file, ls_command_failed};

class AbstractFile{
public:
    virtual ~AbstractFile() = default;

    virtual std::vector<char> read() = 0;
    virtual int write(std::vector<char> content) = 0;
    virtual int append(std::vector<char> additionalContent) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
    virtual void accept(AbstractFileVisitor* visitor) = 0;
};