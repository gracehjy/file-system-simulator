#pragma once

#include <vector>
#include <string>

enum returnVals{success, size_mismatch, invalid_chars, file_type_not_supported, file_already_exists,
        pointer_is_null, invalid_file_extension, file_not_open, cant_delete_open_file, file_does_not_exist};

class AbstractFile{
public:
    virtual void read() = 0;
    virtual int write(std::vector<char>) = 0;
    virtual int append(std::vector<char>) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
};