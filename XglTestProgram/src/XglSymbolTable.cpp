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

/*****************************************************************************
createScope() -
*****************************************************************************/
void XglSymbolTable::createScope()
{
	varScopePtr++;
}

/*****************************************************************************
deleteScope() -
*****************************************************************************/
void XglSymbolTable::deleteScope()
{
	varScopePtr--;
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglSymbolTable::add(string variable, double value)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(variable, value);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglSymbolTable::add(string variable, bool value)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(variable, value);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglSymbolTable::add(XglToken *type, XglToken *variable, XglNode *expression)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, expression);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglSymbolTable::add(XglSymbolTableRecDesType designation, XglToken *type, XglToken *variable, int size, XglNode *expression)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(designation, type, variable, size, expression);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
find() -
*****************************************************************************/
XglSymbolTableRec *XglSymbolTable::find(XglValue *variable)
{
	return(find(variable->getVariableName()));
}

/*****************************************************************************
find() -
*****************************************************************************/
XglSymbolTableRec *XglSymbolTable::find(string variableName)
{
	XglSymbolTableRec *record = NULL;

	int search = varScopePtr;

	while ((search >= 0) && (record == NULL)) {
		record = variables[search--].get(variableName);
	}

	return(record);
}