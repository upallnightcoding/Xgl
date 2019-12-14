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
	void add(string variable, bool value);
	void add(string variable, double value);
	void add(XglToken *type, XglToken *variable, int size, XglNode *expression);
	void add(XglToken *type, XglToken *variable, XglNode *expression);

	XglSymbolTableRec *find(XglValue *variable);

	void createScope();
	void deleteScope();

private:
	XglVarScope *variables;

	int varScopePtr = 0;
};

#include "XglVarScope.h"