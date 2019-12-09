#pragma once

class XglSymbolTable;

class XglContext
{
public:
	XglContext(XglSymbolTable *symbolTable);
	~XglContext();

public:
	XglSymbolTable *getSymbolTable();

public:
	XglSymbolTable *symbolTable;
};

#include "XglSymbolTable.h"
