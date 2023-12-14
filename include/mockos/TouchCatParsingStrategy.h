#ifndef MOCKOS_TOUCHCATPARSINGSTRATEGY_H
#define MOCKOS_TOUCHCATPARSINGSTRATEGY_H
#include "AbstractParsingStrategy.h"
#include <vector>
#include <string>

class TouchCatParsingStrategy : public AbstractParsingStrategy {
public:
    virtual std::vector<std::string> parse(std::string input) override;
};

#endif //MOCKOS_TOUCHCATPARSINGSTRATEGY_H
