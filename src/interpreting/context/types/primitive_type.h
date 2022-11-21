#pragma once

#include "type_base.h"

class PrimitiveType : public TypeBase
{
private:
    std::string type_name;
    size_t type_id;

public:
    PrimitiveType(std::string, size_t);
    virtual std::string name() override;
    virtual std::string stringify() override;
    virtual size_t id() override;
};
