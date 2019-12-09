#pragma once

#include "Xgl.h"
#include "XglVarScope.h"

class XglSymbolTable
{
public:
	XglSymbolTable();
	virtual ~XglSymbolTable();

public:
	void addConst(XglToken *type, XglToken *variable, XglNode *expression);

private:
	//stack<XglVarScope*> variables;
	map<string, XglSymbolTableRec*> variables;
};

