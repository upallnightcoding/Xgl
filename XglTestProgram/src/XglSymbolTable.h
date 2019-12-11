#pragma once

#include "Xgl.h"
#include "XglNode.h"
#include "XglToken.h"
#include "XglValue.h"
#include "XglSymbolTableRec.h"

class XglVarScope;

class XglSymbolTable
{
public:
	XglSymbolTable();
	virtual ~XglSymbolTable();

public:
	void addConst(XglToken *type, XglToken *variable, XglNode *expression);
	XglSymbolTableRec *find(XglValue *variable);

private:
	XglVarScope *variables;

	int varScopePtr = 0;
};

#include "XglVarScope.h"