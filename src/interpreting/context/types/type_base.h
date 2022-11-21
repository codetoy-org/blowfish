#pragma once

#include <string>

class TypeBase
{
private:
    /* data */
public:
    TypeBase(){};
    virtual std::string name() { return ""; };
    virtual std::string stringify() { return ""; };
    virtual size_t id() { return 0; };
};
