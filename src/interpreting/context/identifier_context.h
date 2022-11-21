#pragma once

#include <any>
#include <string>
#include "types/type_base.h"

class IdentifierContext
{
	std::string name;
	TypeBase *type;
	std::string value;
	size_t refCount;

public:
	IdentifierContext(std::string name, TypeBase *type);
	~IdentifierContext();
	template <typename T>
	void assign(T value, TypeBase *type)
	{
		this->type = type;
		this->value = std::string(value);
	}
	virtual void inc_ref();
	virtual void dec_ref();
	virtual bool should_murder();
	virtual const std::string &get_name();
	virtual TypeBase *get_type();
	template <typename T>
	T get_value()
	{
		return T(value);
	}
};