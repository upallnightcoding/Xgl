#pragma once

#include "Xgl.h"
#include "XglValue.h"
#include "XglNode.h"

class XglSymbolTableData
{
public:
	XglSymbolTableData(XglValueType type, int size, XglValue *initialize);
	virtual ~XglSymbolTableData();

public:
	XglValue *getValue(int index);

	void assign(XglValue *value);

	//void assign(XglNode *variable, XglValue *value);

	void assign(int index, XglValue *value);

private:
	void allocateData(XglValueType type, int size);

private:
	string *svalue;
	long *lvalue;
	double *dvalue;
	bool *bvalue;

	XglValue *value;
	XglValueType type;
};

