#pragma once

#include "Xgl.h"
#include "XglToken.h"

enum class XglValueType
{
	UNKNOWN,
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

