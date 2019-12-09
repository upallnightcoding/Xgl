#include "pch.h"
#include "XglSymbolTable.h"


XglSymbolTable::XglSymbolTable()
{
}


XglSymbolTable::~XglSymbolTable()
{
}

void XglSymbolTable::addConst(XglToken *type, XglToken *variable, XglNode *expression)
{
	XglSymbolTableRec *record = new XglSymbolTableRec(type, variable, expression);

	variables[variable->getString()] = record;
}
