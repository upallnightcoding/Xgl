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
	string getVariableName();

	void set(bool value);
	void set(double value);
	void set(string value);
	void set(long value);

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

