#pragma once

#include "Xgl.h"
#include "XglValueType.h"

class XglSymbolTableData
{
public:
	XglSymbolTableData();
	virtual ~XglSymbolTableData();

public:
	void allocateData(XglValueType type, int size);

private:
	string *svalue;
	long *lvalue;
	double *dvalue;
	bool *bvalue;
};

