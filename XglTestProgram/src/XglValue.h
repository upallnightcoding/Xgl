#pragma once

#include "Xgl.h"
#include "XglToken.h"

enum class XglValueType
{
	VALUE_UNKNOWN,
	VALUE_INTEGER,
	VALUE_REAL,
	VALUE_STRING,
	VALUE_BOOLEAN,
	VALUE_KEYWORD
};

class XglValue
{
public:
	XglValue();
	XglValue(XglToken *token);
	virtual ~XglValue();

public:
	void print();

private:
	XglValueType type;

	long lvalue;
	double dvalue;
	string svalue;
	string variable;
	bool bvalue;
};

