#include "identifier_context.h"

#include "../../exception/interpret_exception.h"

IdentifierContext::IdentifierContext(std::string name, TypeBase *type)
{
	this->name = name;
}

IdentifierContext::~IdentifierContext()
{
	if (!this->should_murder())
	{
		// throw interpret_exception("A value tried to be deleted, but it is still referenced!");
	}
}

void IdentifierContext::inc_ref()
{
	this->refCount++;
}

void IdentifierContext::dec_ref()
{
	this->refCount--;
}

bool IdentifierContext::should_murder()
{
	return this->refCount <= 0;
}

const std::string &IdentifierContext::get_name()
{
	return this->name;
}

TypeBase *IdentifierContext::get_type()
{
	return this->type;
}
