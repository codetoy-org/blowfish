#pragma once

#include "identifier_context.h"
#include "types/type_base.h"
#include "types/type_mgr.h"

#include <deque>

class ContextBase
{
	std::deque<IdentifierContext *> identifiers;
	TypeMgr *type_mgr;

public:
	ContextBase();
	~ContextBase();

	virtual IdentifierContext *create_identifier(std::string name, TypeBase *type);
	virtual IdentifierContext *acquire_identifier(std::string name);
	virtual void return_identifier(IdentifierContext *identifier);
	virtual TypeMgr *get_type_mgr();
};