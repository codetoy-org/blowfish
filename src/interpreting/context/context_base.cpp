#include "context_base.h"

#include "../../exception/interpret_exception.h"

ContextBase::ContextBase()
{
	this->identifiers = std::deque<IdentifierContext *>();
	this->type_mgr = new TypeMgr();
}

ContextBase::~ContextBase()
{
	delete this->type_mgr;
}

TypeMgr *ContextBase::get_type_mgr()
{
	return this->type_mgr;
}

IdentifierContext *ContextBase::create_identifier(std::string name, TypeBase *type)
{
	if (type == nullptr)
	{
		throw interpret_exception("Unknown type for name '" + name + "'");
	}

	for (size_t i = 0; i < this->identifiers.size(); i++)
	{
		if (this->identifiers[i]->get_name() == name)
		{
			throw interpret_exception("Redeclaration of an existing identifier '" + name + "'");
		}
	}
	IdentifierContext *ic = new IdentifierContext(name, type);
	this->identifiers.push_back(ic);
	return ic;
}

IdentifierContext *ContextBase::acquire_identifier(std::string name)
{
	for (IdentifierContext *identifier : this->identifiers)
	{
		if (identifier->get_name() == name)
		{
			identifier->inc_ref();
			return identifier;
		}
	}
	return nullptr;
}

void ContextBase::return_identifier(IdentifierContext *identifier)
{
	identifier->dec_ref();
	if (identifier->should_murder())
	{
		for (size_t i = 0; i < this->identifiers.size(); i++)
		{
			if (this->identifiers[i] == identifier)
			{
				this->identifiers.erase(this->identifiers.begin() + i);
			}
		}
		delete identifier;
	}
}
