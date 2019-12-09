#include "pch.h"
#include "XglContext.h"


XglContext::XglContext(XglSymbolTable *symbolTable)
{
	this->symbolTable = symbolTable;
}


XglContext::~XglContext()
{
}

XglSymbolTable *XglContext::getSymbolTable()
{
	return(symbolTable);
}