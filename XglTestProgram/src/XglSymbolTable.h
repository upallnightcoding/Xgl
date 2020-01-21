#pragma once

#include "Xgl.h"
#include "XglNode.h"
#include "XglToken.h"
#include "XglValue.h"
#include "XglSymbolTableRec.h"

class XglVarScope;

class XglSymbolTable
{
public:
	XglSymbolTable();
	virtual ~XglSymbolTable();

public:
	void declareSystemConstant(string variable, bool value);
	void declareSystemConstant(string variable, double value);

	void declareConstant(XglToken *type, XglToken *variable, XglValue *initialize);
	void declareScalar(XglToken *type, XglToken *variable, XglValue *initialize);

	void declareArray(XglToken *type, XglToken *variable, vector<int> &dimensions, XglValue *initialize);
	//void add(XglToken *type, XglToken *variable, XglValue *initialize);

	void assign(string variable, vector<int> elements, XglValue *value);
	XglValue *access(XglValue *variable, vector<int> elements);

	void createScope();
	void deleteScope();

private:
	XglSymbolTableRec *find(XglValue *variable);
	XglSymbolTableRec *find(string variableName);

private:
	XglVarScope *variables;

	int varScopePtr = 0;
};

#include "XglVarScope.h"