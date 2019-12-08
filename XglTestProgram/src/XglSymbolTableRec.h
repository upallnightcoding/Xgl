#pragma once

#include "Xgl.h"
#include "XglValue.h"
#include "XglNode.h"

enum class XglSymbolTableRecDes {
	UNKNOWN,
	SCALER
};

class XglSymbolTableRec
{
public:
	XglSymbolTableRec();
	virtual ~XglSymbolTableRec();

private:
	string name;
	XglValueType type;
	XglSymbolTableRecDes designation;
	XglNode *expression;
};

