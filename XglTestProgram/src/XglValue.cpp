#include "pch.h"
#include "XglValue.h"


XglValue::XglValue()
{
	lvalue = 0;
	dvalue = 0.0;
	svalue = "";
	variable = "";
	bvalue = false;
	type = XglValueType::UNKNOWN;
}

XglValue::XglValue(bool value) 
{
	set(value);
}

XglValue::XglValue(long value) 
{
	set(value);
}

XglValue::XglValue(double value) 
{
	set(value);
}

XglValue::XglValue(string value) 
{
	set(value);
}

void XglValue::set(long value)
{
	type = XglValueType::INTEGER;
	lvalue = value;
}

void XglValue::set(string value)
{
	type = XglValueType::STRING;
	svalue = value;
}

void XglValue::set(double value)
{
	type = XglValueType::REAL;
	dvalue = value;
}

void XglValue::set(bool value)
{
	type = XglValueType::BOOLEAN;
	bvalue = value;
}

XglValue::XglValue(XglToken *token) 
{

	switch (token->getType()) {
	case XglTokenType::INTEGER:
		type = XglValueType::INTEGER;
		lvalue = token->getInteger();
		break;
	case XglTokenType::REAL:
		type = XglValueType::REAL;
		dvalue = token->getReal();
		break;
	case XglTokenType::STRING:
		type = XglValueType::STRING;
		svalue = token->getString();
		break;
	case XglTokenType::KEYWORD:
		type = XglValueType::KEYWORD;
		variable = token->getString();
		break;
	case XglTokenType::BOOLEAN:
		type = XglValueType::BOOLEAN;
		bvalue = token->getBoolean();
		break;
	default:
		type = XglValueType::UNKNOWN;
		break;
	}
}

XglValue::~XglValue()
{
}

/*****************************************************************************
getVariableName() -
*****************************************************************************/
string XglValue::getVariableName()
{
	return(variable);
}

/*****************************************************************************
getType() -
*****************************************************************************/
XglValueType XglValue::getType()
{
	return(type);
}

/*****************************************************************************
getReal() -
*****************************************************************************/
double XglValue::getReal() {
	double value = 0.0;

	switch (type) {
	case XglValueType::INTEGER:
		value = lvalue;
		break;
	case XglValueType::REAL:
		value = dvalue;
		break;
	case XglValueType::STRING:
		value = atof(svalue.c_str());
		break;
	case XglValueType::BOOLEAN:
		value = (bvalue) ? 1.0 : 0.0;
		break;
	default:
		break;
	}

	return(value);
}

/*****************************************************************************
getString() -
*****************************************************************************/
string XglValue::getString() {
	string value = "";

	switch (type) {
	case XglValueType::KEYWORD:
		value = variable;
		break;
	case XglValueType::INTEGER:
		value = to_string(lvalue);
		break;
	case XglValueType::REAL:
		value = to_string(dvalue);
		break;
	case XglValueType::STRING:
		value = svalue;
		break;
	case XglValueType::BOOLEAN:
		value = (bvalue) ? "TRUE" : "FALSE";
		break;
	default:
		break;
	}

	return(value);
}

/*****************************************************************************
getBool() -
*****************************************************************************/
bool XglValue::getBool() {
	bool value = false;

	switch (type) {
	case XglValueType::INTEGER:
		value = (lvalue == 0) ? false : true;
		break;
	case XglValueType::REAL:
		value = (dvalue > 0.0) ? true : false;
		break;
	case XglValueType::STRING:
		break;
	case XglValueType::BOOLEAN:
		value = bvalue;
		break;
	default:
		break;
	}

	return(value);
}

/*****************************************************************************
getInteger() -
*****************************************************************************/
long XglValue::getInteger() {
	long value = 0;

	switch (type) {
	case XglValueType::INTEGER:
		value = lvalue;
		break;
	case XglValueType::REAL:
		value = (long) dvalue;
		break;
	case XglValueType::STRING:
		value = stol(svalue);
		break;
	case XglValueType::BOOLEAN:
		value = (bvalue) ? 1 : 0;
		break;
	default:
		break;
	}

	return(value);
}

/*****************************************************************************
print() -
*****************************************************************************/
void XglValue::print() {
	switch (type) {
	case XglValueType::INTEGER:
		cout << lvalue;
		break;
	case XglValueType::REAL:
		cout << dvalue;
		break;
	case XglValueType::STRING:
		cout << svalue;
		break;
	case XglValueType::KEYWORD:
		cout << variable;
		break;
	case XglValueType::BOOLEAN:
		cout << bvalue;
		break;
	}
}
