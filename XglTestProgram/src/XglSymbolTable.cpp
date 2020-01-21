#include "pch.h"
#include "XglSymbolTable.h"

#include "XglNodeValue.h"

// Global Constants
//-----------------
const double PI = 3.14159265359;


XglSymbolTable::XglSymbolTable()
{
	variables = new XglVarScope[10];

	declareSystemConstant("TRUE", true);
	declareSystemConstant("FALSE", false);
	declareSystemConstant("PI", PI);

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
add() - Defines a constant of type real.
*****************************************************************************/
void XglSymbolTable::declareSystemConstant(string variable, double value)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(XglValueType::REAL, variable, new XglValue(value));

	variables[varScopePtr].add(record);
}

/*****************************************************************************
add() - Defines a constant of type boolean.
*****************************************************************************/
void XglSymbolTable::declareSystemConstant(string variable, bool value)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(XglValueType::BOOLEAN, variable, new XglValue(value));

	variables[varScopePtr].add(record);
}

void XglSymbolTable::declareConstant(XglToken *type, XglToken *variable, XglValue *initialize)
{
	XglSymbolTableRecDesType designation = XglSymbolTableRecDesType::CONSTANT;

	XglSymbolTableRec *record = new XglSymbolTableRec(designation, type, variable, initialize);

	variables[varScopePtr].add(record);
}

void XglSymbolTable::declareScalar(XglToken *type, XglToken *variable, XglValue *initialize)
{
	XglSymbolTableRecDesType designation = XglSymbolTableRecDesType::SCALER;

	XglSymbolTableRec *record = new XglSymbolTableRec(designation, type, variable, initialize);

	variables[varScopePtr].add(record);
}

/*****************************************************************************
add() -
*****************************************************************************/
/*void XglSymbolTable::add(XglToken *type, XglToken *variable, XglValue *initialize)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, initialize);

	variables[varScopePtr].add(record);
}*/

/*****************************************************************************
add() -
*****************************************************************************/
void XglSymbolTable::declareArray(XglToken *type, XglToken *variable, vector<int> &dimensions, XglValue *initialize)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, dimensions, initialize);

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

/*****************************************************************************
assign() -
*****************************************************************************/
void XglSymbolTable::assign(string variable, vector<int> elements, XglValue *value)
{
	XglSymbolTableRec *record = find(variable);

	if (record != NULL) {
		record->assign(elements, value);
	}
}

/*****************************************************************************
access() -
*****************************************************************************/
XglValue *XglSymbolTable::access(XglValue *variable, vector<int> elements)
{
	XglValue *value = NULL;

	XglSymbolTableRec *record = find(variable);

	if (record != NULL) {
		value = record->access(elements);
	}

	return(value);
}