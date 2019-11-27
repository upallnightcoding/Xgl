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
