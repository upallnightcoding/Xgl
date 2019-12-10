#include "pch.h"
#include "XglSymbolTable.h"


XglSymbolTable::XglSymbolTable()
{
}


XglSymbolTable::~XglSymbolTable()
{
}

/*****************************************************************************
addConst() -
*****************************************************************************/
void XglSymbolTable::addConst(XglToken *type, XglToken *variable, XglNode *expression)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, expression);

	variables[variable->getString()] = record;
}

/*****************************************************************************
find() -
*****************************************************************************/
XglSymbolTableRec *XglSymbolTable::find(XglValue *variable)
{
	string variableName = variable->getVariableName();
	XglSymbolTableRec *record = variables[variableName];

	return(record);
}