#include "pch.h"
#include "XglSymbolTable.h"

// Global Constants
//-----------------
const double PI = 3.14159265359;


XglSymbolTable::XglSymbolTable()
{
	variables = new XglVarScope[10];

	add("TRUE", true);
	add("FALSE", false);
	add("PI", PI);

	createScope();
}


XglSymbolTable::~XglSymbolTable()
{
	delete variables;
}

void XglSymbolTable::createScope()
{
	varScopePtr++;
}

void XglSymbolTable::deleteScope()
{
	varScopePtr--;
}

void XglSymbolTable::add(string variable, double value)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(variable, value);

	variables[varScopePtr].add(record);
}

void XglSymbolTable::add(string variable, bool value)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(variable, value);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
addConst() -
*****************************************************************************/
void XglSymbolTable::add(XglToken *type, XglToken *variable, XglNode *expression)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, expression);

	variables[varScopePtr].add(record);
}

void XglSymbolTable::add(XglToken *type, XglToken *variable)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, 1, NULL);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
find() -
*****************************************************************************/
XglSymbolTableRec *XglSymbolTable::find(XglValue *variable)
{
	string variableName = variable->getVariableName();
	XglSymbolTableRec *record = NULL;

	int search = varScopePtr;

	while ((search >= 0) && (record == NULL)) {
		record = variables[search--].get(variableName);
	}

	return(record);
}