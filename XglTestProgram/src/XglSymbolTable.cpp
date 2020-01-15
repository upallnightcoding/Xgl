#include "pch.h"
#include "XglSymbolTable.h"

#include "XglNodeValue.h"

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
	XglSymbolTableRec *record = new XglSymbolTableRec(XglValueType::REAL, variable, new XglValue(value));

	variables[varScopePtr].add(record);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglSymbolTable::add(string variable, bool value)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(XglValueType::BOOLEAN, variable, new XglValue(value));

	variables[varScopePtr].add(record);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglSymbolTable::add(XglToken *type, XglToken *variable, XglValue *initialize)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, initialize);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglSymbolTable::add(XglSymbolTableRecDesType designation, XglToken *type, XglToken *variable, int size, XglValue *initialize)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(designation, type, variable, size, initialize);

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