#pragma once

#include "AbstractFileVisitor.h"

// enums for visitors
enum {start = 0, addOne = 1, noRemainders = 0};

class BasicDisplayVisitor: public AbstractFileVisitor{
public:
    void visit_TextFile(TextFile* file) override;
    void visit_ImageFile(ImageFile* file) override;
};