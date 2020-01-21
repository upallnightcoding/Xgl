#pragma once

#include "Xgl.h"
#include "XglValue.h"
#include "XglNode.h"

class XglSymbolTableData
{
public:
	XglSymbolTableData(XglValueType type, XglValue *initialize);
	XglSymbolTableData(XglValueType type, vector<int> &dimensions, XglValue *initialize);
	virtual ~XglSymbolTableData();

public:
	XglValue *getValue(int index);
	XglValue *getValue();

	void assign(XglValue *value);
	void assign(int col, int row, XglValue *value);

	//void assign(XglNode *variable, XglValue *value);

	XglValue *access(vector<int> elements);

	void assign(vector<int> elements, XglValue *value);

private:
	void allocateData(XglValueType type, int size);

	void init(XglValueType type, int size, XglValue *initialize);

	void assign(int index, XglValue *value);

	int calcArrayIndex(vector<int> elements);

private:
	string *svalue;
	long *lvalue;
	double *dvalue;
	bool *bvalue;

	int width;

	XglValue *value;
	XglValueType type;
};

