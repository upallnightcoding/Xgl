#include "pch.h"
#include "XglNumber.h"


XglNumber::XglNumber(long whole, int ndigits)
{
	this->type = XglTokenType::INTEGER;
	this->lvalue = whole;
	this->dvalue = 0.0;
	this->ndigits = ndigits;
}

XglNumber::~XglNumber()
{
}

/*****************************************************************************
calcFractional() - Calculates the fractional part of a floating point
number.  The fractional is calculated by raising the integer representation
to the negative base 10 of the number of digits in integer number.

Example:
	0.123 => 123 * pow(10, -3)
	0.0123 => 123 * pos(10, -4)
*****************************************************************************/
double XglNumber::calcFractional()
{
	return(lvalue * pow(10.0, -ndigits));
}

/*****************************************************************************
add() - 
*****************************************************************************/
void XglNumber::add(XglNumber &fraction)
{
	type = XglTokenType::REAL;

	dvalue = lvalue + fraction.calcFractional();
}

/*****************************************************************************
getToken() -
*****************************************************************************/
XglToken *XglNumber::getToken()
{
	XglToken *token = NULL;

	switch (type) {
	case XglTokenType::INTEGER:
		token = new XglToken(lvalue);
		break;
	case XglTokenType::REAL:
		token = new XglToken(dvalue);
		break;
	default:
		token = NULL;
		break;
	}

	return(token);
}
