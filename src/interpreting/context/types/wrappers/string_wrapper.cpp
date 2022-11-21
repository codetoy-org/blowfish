#include "string_wrapper.h"

StringWrapper::StringWrapper(size_t type_id) : TypeBase::TypeBase()
{
    this->type_id = type_id;
}

std::string StringWrapper::name()
{
    return "string";
}

std::string StringWrapper::stringify()
{
    return "string:" + std::to_string(this->type_id);
}

size_t StringWrapper::id()
{
    return this->type_id;
}