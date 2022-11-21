#include "type_mgr.h"
#include "type_id.h"
#include "primitive_type.h"

TypeMgr::TypeMgr()
{
    this->types = {
        // Signed ints
        new PrimitiveType("i8", (size_t)TypeId::I8),
        new PrimitiveType("i16", (size_t)TypeId::I16),
        new PrimitiveType("i32", (size_t)TypeId::I32),
        new PrimitiveType("i64", (size_t)TypeId::I64),
        // Unsigned ints
        new PrimitiveType("u8", (size_t)TypeId::U8),
        new PrimitiveType("u16", (size_t)TypeId::U16),
        new PrimitiveType("u32", (size_t)TypeId::U32),
        new PrimitiveType("u64", (size_t)TypeId::U64),
        // Floats
        new PrimitiveType("f32", (size_t)TypeId::F32),
        new PrimitiveType("f64", (size_t)TypeId::F64),
        // Pointer
        new PrimitiveType("ptr->", (size_t)TypeId::PTR),
        // Class
        new PrimitiveType("class", (size_t)TypeId::CLASS),
    };
}

TypeBase *TypeMgr::find_type(std::string type_name)
{
    for (TypeBase *type : this->types)
    {
        if (type->name() == type_name)
        {
            return type;
        }
    }

    return nullptr;
}

void TypeMgr::register_type(TypeBase *type)
{
    this->types.push_back(type);
}

size_t TypeMgr::next_id()
{
    return this->types.size();
}