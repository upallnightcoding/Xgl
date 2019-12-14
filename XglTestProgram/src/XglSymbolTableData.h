#pragma once

#include "Xgl.h"
#include "XglValue.h"

class XglSymbolTableData
{
public:
	XglSymbolTableData(XglValueType type, int size);
	virtual ~XglSymbolTableData();

public:
	XglValue *getValue();
	void set(int index, XglValue *value);

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

