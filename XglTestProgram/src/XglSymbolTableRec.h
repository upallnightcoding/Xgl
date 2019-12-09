#pragma once

#include "Xgl.h"
#include "XglValue.h"

class XglNode;

enum class XglSymbolTableRecDesType {
	UNKNOWN,
	SCALER,
	CONSTANT
};

class XglSymbolTableRec
{
public:
	XglSymbolTableRec(XglToken *type, XglToken *variable, XglNode *expression);
	virtual ~XglSymbolTableRec();

private:
	string name;
	XglValueType type;
	XglSymbolTableRecDesType designation;
	XglNode *expression;
};

#include "XglNode.h"