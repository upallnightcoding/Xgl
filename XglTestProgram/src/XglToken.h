#pragma once

#include "Xgl.h"

enum class XglTokenType {
	UNKNOWN,
	INTEGER,
	REAL,
	BOOLEAN,
	STRING,
	TOKEN_SYMBOL,
	KEYWORD
};

class XglToken
{
public:
	XglToken();
	XglToken(long value);
	XglToken(double value);
	XglToken(XglTokenType type, string value);
	virtual ~XglToken();

private:
	XglTokenType type;

	long lvalue;
	double dvalue;
	string svalue;
};

