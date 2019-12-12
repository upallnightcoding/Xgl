#pragma once

#include "Xgl.h"
#include "XglValue.h"

class XglNode;
class XglContext;

enum class XglSymbolTableRecDesType {
	UNKNOWN,
	SCALER,
	CONSTANT
};

class XglSymbolTableRec
{
public:
	XglSymbolTableRec(string variable, bool value);
	XglSymbolTableRec(string variable, double value);
	XglSymbolTableRec(XglToken *type, XglToken *variable, XglNode *expression);
	virtual ~XglSymbolTableRec();

public:
	XglValue *getValue(XglContext &context);
	string getVariableName();

	bool isConstant();

private:
	string variable;
	XglValueType type;
	XglSymbolTableRecDesType designation;
	XglNode *expression;
	XglValue *value;
};

#include "XglNode.h"
#include "XglContext.h"