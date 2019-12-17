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
	this->bvalue = false;
	this->symbol = XglTokenSymbolType::TOKEN_SYMBOL_UNKNOWN;
}

XglToken::XglToken(double value)
{
	this->type = XglTokenType::REAL;
	this->lvalue = 0;
	this->dvalue = value;
	this->svalue = "";
	this->bvalue = false;
	this->symbol = XglTokenSymbolType::TOKEN_SYMBOL_UNKNOWN;
}

XglToken::XglToken(XglTokenType type, string value)
{
	this->type = type;
	this->lvalue = 0;
	this->dvalue = 0.0;
	this->svalue = value;
	this->bvalue = false;
	this->symbol = XglTokenSymbolType::TOKEN_SYMBOL_UNKNOWN;
}

XglToken::XglToken(XglTokenSymbolType symbol)
{
	this->type = XglTokenType::TOKEN_SYMBOL;
	this->lvalue = 0;
	this->dvalue = 0.0;
	this->svalue = "";
	this->bvalue = false;
	this->symbol = symbol;
}

XglToken::~XglToken()
{
}

XglValueType XglToken::getTypeFromKeyword() 
{
	XglValueType type = XglValueType::UNKNOWN;

	if (svalue == "INTEGER") {
		type = XglValueType::INTEGER;
	} else if (svalue == "REAL") {
		type = XglValueType::REAL;
	} else if (svalue == "STRING") {
		type = XglValueType::STRING;
	} else if (svalue == "BOOLEAN") {
		type = XglValueType::BOOLEAN;
	}

	return(type);
}

bool XglToken::isKeyword() 
{
	return(type == XglTokenType::KEYWORD);
}

/*****************************************************************************
isComma() - Returns true if the token is a comma ","
*****************************************************************************/
bool XglToken::isComma() {
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::TOKEN_SYMBOL_COMMA));
}

/*****************************************************************************
isEos() - Returns true if the token is a semi colon ";"
*****************************************************************************/
bool XglToken::isEos() {
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::TOKEN_SYMBOL_SEMI));
}

/*****************************************************************************
isEndExpression() - Returns true if the token represents the end of an 
expression.  This is used to determine the end of an expression that could 
be in a comma separated list.  The expression is complete if the token is
a comma or semi-colon.
*****************************************************************************/
bool XglToken::isEndExpression() 
{
	return(isComma() || isEos());
}

bool XglToken::isConstant() 
{
	bool constant = false;

	switch (type) {
	case XglTokenType::INTEGER:
	case XglTokenType::REAL:
	case XglTokenType::STRING:
		constant = true;
		break;
	default:
		break;
	}

	return(constant);
}

bool XglToken::isRightParen() 
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::TOKEN_SYMBOL_RPAREN));
}

bool XglToken::isLeftParen() 
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::TOKEN_SYMBOL_LPAREN));
}

bool XglToken::isEOE()
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::TOKEN_SYMBOL_EOE));
}

bool XglToken::isAssignment()
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::TOKEN_SYMBOL_ASSIGN));
}

bool XglToken::isOperator()
{
	bool value = false;

	switch (symbol) {
	case XglTokenSymbolType::TOKEN_SYMBOL_TILDE:
	case XglTokenSymbolType::TOKEN_SYMBOL_NOT:

	case XglTokenSymbolType::TOKEN_SYMBOL_MULT:
	case XglTokenSymbolType::TOKEN_SYMBOL_DIVIDE:

	case XglTokenSymbolType::TOKEN_SYMBOL_PLUS:
	case XglTokenSymbolType::TOKEN_SYMBOL_MINUS:

	case XglTokenSymbolType::TOKEN_SYMBOL_EQ:
	case XglTokenSymbolType::TOKEN_SYMBOL_NE:
	case XglTokenSymbolType::TOKEN_SYMBOL_GT:
	case XglTokenSymbolType::TOKEN_SYMBOL_LT:
	case XglTokenSymbolType::TOKEN_SYMBOL_GE:
	case XglTokenSymbolType::TOKEN_SYMBOL_LE:

	case XglTokenSymbolType::TOKEN_SYMBOL_LPAREN:

	case XglTokenSymbolType::TOKEN_SYMBOL_EOE:
		value = true;
		break;
	default:
		value = false;
		break;
	}

	return(value);
}

/*****************************************************************************
getBoolean()
*****************************************************************************/
bool XglToken::getBoolean() {
	return(bvalue);
}

/*****************************************************************************
getString()
*****************************************************************************/
string XglToken::getString() {
	return(svalue);
}

/*****************************************************************************
getInteger()
*****************************************************************************/
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

/*****************************************************************************
getReal()
*****************************************************************************/
double XglToken::getReal() {
	double value = 0.0;

	switch (type) {
	case XglTokenType::INTEGER:
		value = lvalue;
		break;
	case XglTokenType::REAL:
		value = dvalue;
		break;
	case XglTokenType::BOOLEAN:
		value = (bvalue) ? 1.0 : 0.0;
		break;
	default:
		break;
	}

	return(value);
}

/*****************************************************************************
getType()
*****************************************************************************/
XglTokenType XglToken::getType()
{
	return(type);
}

/*****************************************************************************
getSymbol()
*****************************************************************************/
XglTokenSymbolType XglToken::getSymbol()
{
	return(symbol);
}

/*****************************************************************************
rank()
*****************************************************************************/
int XglToken::rank()
{
	int value = -1;

	switch (symbol) {
	case XglTokenSymbolType::TOKEN_SYMBOL_TILDE:
	case XglTokenSymbolType::TOKEN_SYMBOL_NOT:
		value = 50;
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_MULT:
	case XglTokenSymbolType::TOKEN_SYMBOL_DIVIDE:
		value = 20;
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_PLUS:
	case XglTokenSymbolType::TOKEN_SYMBOL_MINUS:
		value = 10;
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_EQ:
	case XglTokenSymbolType::TOKEN_SYMBOL_NE:
	case XglTokenSymbolType::TOKEN_SYMBOL_GT:
	case XglTokenSymbolType::TOKEN_SYMBOL_LT:
	case XglTokenSymbolType::TOKEN_SYMBOL_GE:
	case XglTokenSymbolType::TOKEN_SYMBOL_LE:
		value = 5;
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_LPAREN:
		value = 1;
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_EOE:
	case XglTokenSymbolType::TOKEN_SYMBOL_RPAREN:
		value = 0;
		break;
	}

	return(value);
}
