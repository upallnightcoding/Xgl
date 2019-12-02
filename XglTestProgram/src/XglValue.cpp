#include "pch.h"
#include "XglValue.h"


XglValue::XglValue()
{
	lvalue = 0;
	dvalue = 0.0;
	svalue = "";
	variable = "";
	bvalue = false;
	type = XglValueType::VALUE_UNKNOWN;
}

XglValue::XglValue(XglToken *token) {

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
		type = XglValueType::VALUE_UNKNOWN;
		break;
	}
}


XglValue::~XglValue()
{
}

void XglValue::print() {
	switch (type) {
	case XglValueType::VALUE_INTEGER:
		cout << lvalue << " ";
		break;
	case XglValueType::VALUE_REAL:
		cout << dvalue << " ";
		break;
	case XglValueType::VALUE_STRING:
		cout << svalue << " ";
		break;
	case XglValueType::VALUE_KEYWORD:
		cout << variable << " ";
		break;
	case XglValueType::VALUE_BOOLEAN:
		cout << bvalue << " ";
		break;
	}
}
