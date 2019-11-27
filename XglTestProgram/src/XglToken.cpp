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
}

XglToken::XglToken(double value)
{
	this->type = XglTokenType::REAL;
	this->dvalue = value;
	this->lvalue = 0;
	this->svalue = "";
}

XglToken::XglToken(XglTokenType type, string value)
{
	this->type = type;
	this->svalue = value;
	this->dvalue = 0.0;
	this->lvalue = 0;
}

XglToken::~XglToken()
{
}
