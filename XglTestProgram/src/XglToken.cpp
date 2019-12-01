#include "pch.h"
#include "XglToken.h"


XglToken::XglToken()
{
	type = XglTokenType::UNKNOWN;
}

XglToken::XglToken(long value) 
{
	this->type = XglTokenType::INTEGER;
	this->lvalue = value;
	this->dvalue = 0.0;
	this->svalue = "";
	this->symbol = XglTokenSymbolType::TOKEN_SYMBOL_UNKNOWN;
}

XglToken::XglToken(double value)
{
	this->type = XglTokenType::REAL;
	this->lvalue = 0;
	this->dvalue = value;
	this->svalue = "";
	this->symbol = XglTokenSymbolType::TOKEN_SYMBOL_UNKNOWN;
}

XglToken::XglToken(XglTokenType type, string value)
{
	this->type = type;
	this->lvalue = 0;
	this->dvalue = 0.0;
	this->svalue = value;
	this->symbol = XglTokenSymbolType::TOKEN_SYMBOL_UNKNOWN;
}

XglToken::XglToken(XglTokenSymbolType symbol)
{
	this->type = XglTokenType::TOKEN_SYMBOL;
	this->lvalue = 0;
	this->dvalue = 0.0;
	this->svalue = "";
	this->symbol = symbol;
}

XglToken::~XglToken()
{
}

bool XglToken::getBoolean() {
	return(bvalue);
}

string XglToken::getString() {
	return(svalue);
}

long XglToken::getInteger() 
{
	long value = 0;

	switch (type) {
	case XglTokenType::INTEGER:
		value = lvalue;
		break;
	case XglTokenType::REAL:
		value = (long)dvalue;
		break;
	case XglTokenType::BOOLEAN:
		value = (bvalue) ? 1 : 0;
		break;
	default:
		break;
	}

	return (value);
}

double XglToken::getReal() {
	double value = 0.0;

	switch (type) {
	case XglTokenType::INTEGER:
		value = lvalue;
		break;
	case XglTokenType::REAL:
		value = dvalue;
		break;
	default:
		break;
	}

	return(value);
}

bool XglToken::isEos()
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::TOKEN_SYMBOL_SEMI));
}

XglTokenType XglToken::getType()
{
	return(type);
}