#include "primitive_type.h"

PrimitiveType::PrimitiveType(std::string type_name, size_t type_id) : TypeBase::TypeBase()
{
    this->type_name = type_name;
    this->type_id = type_id;
}

size_t PrimitiveType::id()
{
    return this->type_id;
}

std::string PrimitiveType::stringify()
{
    return this->type_name + ":" + std::to_string(this->type_id);
}

std::string PrimitiveType::name()
{
    return this->type_name;
}
