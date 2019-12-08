#pragma once

#include "Xgl.h"
#include "XglVarScope.h"

class XglSymbolTable
{
public:
	XglSymbolTable();
	virtual ~XglSymbolTable();

private:
	stack<XglVarScope*> variables;
};

