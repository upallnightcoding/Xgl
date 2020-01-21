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
	this->symbol = XglTokenSymbolType::UNKNOWN;
}

XglToken::XglToken(double value)
{
	this->type = XglTokenType::REAL;
	this->lvalue = 0;
	this->dvalue = value;
	this->svalue = "";
	this->bvalue = false;
	this->symbol = XglTokenSymbolType::UNKNOWN;
}

XglToken::XglToken(XglTokenType type, string value)
{
	this->type = type;
	this->lvalue = 0;
	this->dvalue = 0.0;
	this->svalue = value;
	this->bvalue = false;
	this->symbol = XglTokenSymbolType::UNKNOWN;
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

bool XglToken::is(XglTokenSymbolType target)
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == target));
}

bool XglToken::isKeyword() 
{
	return(type == XglTokenType::KEYWORD);
}

/*****************************************************************************
isComma() - Returns true if the token is a comma ","
*****************************************************************************/
bool XglToken::isComma() {
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_COMMA));
}

/*****************************************************************************
isEos() - Returns true if the token is a semi colon ";"
*****************************************************************************/
bool XglToken::isEos() {
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_SEMI));
}

/*****************************************************************************
isColon() 
*****************************************************************************/
bool XglToken::isColon() {
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_COLON));
}

/*****************************************************************************
isQuestion() - 
*****************************************************************************/
bool XglToken::isQuestion() {
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_QUESTION));
}

/*****************************************************************************
isEndExpression() - Returns true if the token represents the end of an 
expression.  This is used to determine the end of an expression that could 
be in a comma separated list.  The expression is complete if the token is
a comma or semi-colon.
*****************************************************************************/
bool XglToken::isEndExpression() 
{
	return(isComma() || isEos() || isQuestion() || isColon() || isRightBracket());
}

/*****************************************************************************
isConstant() - 
*****************************************************************************/
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
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_RIGHT_PAREN));
}

bool XglToken::isLeftParen() 
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_LEFT_PAREN));
}

bool XglToken::isRightBracket()
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_RIGHT_BRACKET));
}

bool XglToken::isLeftBracket()
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_LEFT_BRACKET));
}

bool XglToken::isEOE()
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_EOE));
}

bool XglToken::isAssignment()
{
	return((type == XglTokenType::TOKEN_SYMBOL) && (symbol == XglTokenSymbolType::SYMBOL_ASSIGN));
}

bool XglToken::isOperator()
{
	bool value = false;

	switch (symbol) {
	case XglTokenSymbolType::SYMBOL_TILDE:
	case XglTokenSymbolType::SYMBOL_NOT:

	case XglTokenSymbolType::SYMBOL_MULT:
	case XglTokenSymbolType::SYMBOL_DIVIDE:

	case XglTokenSymbolType::SYMBOL_ADD:
	case XglTokenSymbolType::SYMBOL_SUB:

	case XglTokenSymbolType::SYMBOL_EQ:
	case XglTokenSymbolType::SYMBOL_NE:
	case XglTokenSymbolType::SYMBOL_GT:
	case XglTokenSymbolType::SYMBOL_LT:
	case XglTokenSymbolType::SYMBOL_GE:
	case XglTokenSymbolType::SYMBOL_LE:

	case XglTokenSymbolType::SYMBOL_LEFT_PAREN:

	case XglTokenSymbolType::SYMBOL_EOE:
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
	case XglTokenSymbolType::SYMBOL_TILDE:
	case XglTokenSymbolType::SYMBOL_NOT:
		value = 50;
		break;
	case XglTokenSymbolType::SYMBOL_MULT:
	case XglTokenSymbolType::SYMBOL_DIVIDE:
		value = 20;
		break;
	case XglTokenSymbolType::SYMBOL_ADD:
	case XglTokenSymbolType::SYMBOL_SUB:
		value = 10;
		break;
	case XglTokenSymbolType::SYMBOL_EQ:
	case XglTokenSymbolType::SYMBOL_NE:
	case XglTokenSymbolType::SYMBOL_GT:
	case XglTokenSymbolType::SYMBOL_LT:
	case XglTokenSymbolType::SYMBOL_GE:
	case XglTokenSymbolType::SYMBOL_LE:
		value = 5;
		break;
	case XglTokenSymbolType::SYMBOL_LEFT_PAREN:
		value = 1;
		break;
	case XglTokenSymbolType::SYMBOL_EOE:
	case XglTokenSymbolType::SYMBOL_RIGHT_PAREN:
		value = 0;
		break;
	}

	return(value);
}
