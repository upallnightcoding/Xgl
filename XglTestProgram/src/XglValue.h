#pragma once

#include "Xgl.h"
#include "XglToken.h"
#include "XglValueType.h"

class XglValue
{
public:
	XglValue();
	XglValue(XglToken *token);
	XglValue(double dvalue);
	XglValue(string value);
	XglValue(long value);
	XglValue(bool value);
	virtual ~XglValue();

public:
	double getReal();
	string getString();
	bool getBool();
	long getInteger();

	XglValueType getType();

	void print();

private:
	XglValueType type;

	long lvalue;
	double dvalue;
	string svalue;
	string variable;
	bool bvalue;
};

