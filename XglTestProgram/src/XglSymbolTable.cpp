#include "pch.h"
#include "XglSymbolTable.h"


XglSymbolTable::XglSymbolTable()
{
	variables = new XglVarScope[10];
}


XglSymbolTable::~XglSymbolTable()
{
	delete variables;
}

/*****************************************************************************
addConst() -
*****************************************************************************/
void XglSymbolTable::addConst(XglToken *type, XglToken *variable, XglNode *expression)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, expression);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
find() -
*****************************************************************************/
XglSymbolTableRec *XglSymbolTable::find(XglValue *variable)
{
	string variableName = variable->getVariableName();

	XglSymbolTableRec *record = variables[varScopePtr].get(variableName);

	return(record);
}