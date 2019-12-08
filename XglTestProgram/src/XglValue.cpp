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

XglValue::XglValue(bool value) {
	type = XglValueType::VALUE_BOOLEAN;
	bvalue = value;
}

XglValue::XglValue(long value) {
	type = XglValueType::VALUE_INTEGER;
	lvalue = value;
}

XglValue::XglValue(double value) {
	type = XglValueType::VALUE_REAL;
	dvalue = value;
}

XglValue::XglValue(string value) {
	type = XglValueType::VALUE_STRING;
	svalue = value;
}

XglValue::XglValue(XglToken *token) 
{

	switch (token->getType()) {
	case XglTokenType::INTEGER:
		type = XglValueType::VALUE_INTEGER;
		lvalue = token->getInteger();
		break;
	case XglTokenType::REAL:
		type = XglValueType::VALUE_REAL;
		dvalue = token->getReal();
		break;
	case XglTokenType::STRING:
		type = XglValueType::VALUE_STRING;
		svalue = token->getString();
		break;
	case XglTokenType::KEYWORD:
		type = XglValueType::VALUE_KEYWORD;
		variable = token->getString();
		break;
	case XglTokenType::BOOLEAN:
		type = XglValueType::VALUE_BOOLEAN;
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
	case XglValueType::VALUE_INTEGER:
		value = lvalue;
		break;
	case XglValueType::VALUE_REAL:
		value = dvalue;
		break;
	case XglValueType::VALUE_STRING:
		value = atof(svalue.c_str());
		break;
	case XglValueType::VALUE_BOOLEAN:
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
	case XglValueType::VALUE_INTEGER:
		value = to_string(lvalue);
		break;
	case XglValueType::VALUE_REAL:
		value = to_string(dvalue);
		break;
	case XglValueType::VALUE_STRING:
		value = svalue;
		break;
	case XglValueType::VALUE_BOOLEAN:
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
	case XglValueType::VALUE_INTEGER:
		value = (lvalue == 0) ? false : true;
		break;
	case XglValueType::VALUE_REAL:
		value = (dvalue > 0.0) ? true : false;
		break;
	case XglValueType::VALUE_STRING:
		break;
	case XglValueType::VALUE_BOOLEAN:
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
	case XglValueType::VALUE_INTEGER:
		value = lvalue;
		break;
	case XglValueType::VALUE_REAL:
		value = (long) dvalue;
		break;
	case XglValueType::VALUE_STRING:
		value = stol(svalue);
		break;
	case XglValueType::VALUE_BOOLEAN:
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
	case XglValueType::VALUE_INTEGER:
		cout << lvalue;
		break;
	case XglValueType::VALUE_REAL:
		cout << dvalue;
		break;
	case XglValueType::VALUE_STRING:
		cout << svalue;
		break;
	case XglValueType::VALUE_KEYWORD:
		cout << variable;
		break;
	case XglValueType::VALUE_BOOLEAN:
		cout << bvalue;
		break;
	}
}
