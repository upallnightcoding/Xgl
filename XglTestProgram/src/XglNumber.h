#pragma once

#include "Xgl.h"
#include "XglToken.h"

class XglNumber
{
public:
	XglNumber(long whole, int ndigits);
	virtual ~XglNumber();

public:
	void add(XglNumber &fraction);
	XglToken *getToken();

private:
	double calcFractional();

private:
	XglTokenType type;

	long lvalue;
	int ndigits;
	double dvalue;
};

