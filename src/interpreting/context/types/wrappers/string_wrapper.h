#pragma once

#include <string>
#include "../type_base.h"

class StringWrapper : public TypeBase
{
private:
    size_t type_id;

public:
    StringWrapper(size_t);
    ~StringWrapper();
    virtual std::string name() override;
    virtual std::string stringify() override;
    virtual size_t id() override;
};
