#pragma once

#include "Xgl.h"
#include "XglValue.h"
#include "XglSymbolTableData.h"

class XglNode;
class XglContext;

enum class XglSymbolTableRecDesType {
	UNKNOWN,
	SCALER,
	CONSTANT
};

/*****************************************************************************
XglSymbolTableRec -
*****************************************************************************/
class XglSymbolTableRec
{
public:
	// Xgl Internal Constants
	XglSymbolTableRec(string variable, bool value);
	XglSymbolTableRec(string variable, double value);

	// Symbol Table Constants
	XglSymbolTableRec(XglToken *type, XglToken *variable, XglNode *expression);

	// Variable Constants
	XglSymbolTableRec(XglToken *type, XglToken *variable, int size, XglNode *expression);
	virtual ~XglSymbolTableRec();

public:
	XglValue *getValue(XglContext &context);
	string getVariableName();
	XglSymbolTableData *getData();

	bool isConstant();

private:
	// Variable Name
	string variable;

	// Tyep of variable, integer, real, boolean, string ...
	XglValueType type;

	// Designation of the vairable, scalar, array, function, procedure ...
	XglSymbolTableRecDesType designation;

	// Expression initialization
	XglNode *expression;

	// Value help by scalars and arrays
	XglSymbolTableData *data;

	// Number of maximum elements in an array
	int size;
};

#include "XglNode.h"
#include "XglContext.h"