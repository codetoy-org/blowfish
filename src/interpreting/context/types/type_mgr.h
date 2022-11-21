#pragma once

#include "type_base.h"
#include <vector>

class TypeMgr
{
private:
    std::vector<TypeBase *> types;

public:
    TypeMgr();
    TypeBase *find_type(std::string);
    void register_type(TypeBase *);
    size_t next_id();
};
