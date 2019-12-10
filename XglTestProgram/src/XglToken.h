#pragma once

#include "Xgl.h"
#include "XglValueType.h"

enum class XglTokenType {
	UNKNOWN,
	INTEGER,
	REAL,
	BOOLEAN,
	STRING,
	TOKEN_SYMBOL,
	KEYWORD
};

enum class XglTokenSymbolType {
	TOKEN_SYMBOL_UNKNOWN,

	TOKEN_SYMBOL_EOE,

	// Not Operators
	//--------------
	TOKEN_SYMBOL_TILDE,
	TOKEN_SYMBOL_NOT,

	// Binary Operators
	//-----------------
	TOKEN_SYMBOL_MULT,
	TOKEN_SYMBOL_DIVIDE,
	TOKEN_SYMBOL_PLUS,
	TOKEN_SYMBOL_MINUS,

	// Conditional Operators
	//----------------------
	TOKEN_SYMBOL_EQ,
	TOKEN_SYMBOL_NE,
	TOKEN_SYMBOL_GT,
	TOKEN_SYMBOL_LT,
	TOKEN_SYMBOL_GE,
	TOKEN_SYMBOL_LE,

	// Left & Right Parentheses ()
	//----------------------------
	TOKEN_SYMBOL_RPAREN,
	TOKEN_SYMBOL_LPAREN,

	// Left & Right Brace {}
	//----------------------
	TOKEN_SYMBOL_LBRACE,
	TOKEN_SYMBOL_RBRACE,

	// Variable assignment operator
	//-----------------------------
	TOKEN_SYMBOL_ASSIGN,

	// Statement separator token
	//--------------------------
	TOKEN_SYMBOL_SEMI,

	// Expression separator token
	//---------------------------
	TOKEN_SYMBOL_COMMA
};

class XglToken
{
public:
	XglToken();
	XglToken(long value);
	XglToken(double value);
	XglToken(XglTokenType type, string value);
	XglToken(XglTokenSymbolType symbol);

	virtual ~XglToken();

public:
	int rank();

	bool isEos();
	bool isEndExpression();
	bool isComma();
	bool isLeftParen();
	bool isRightParen();
	bool isEOE();
	bool isConstant();
	bool isOperator();
	bool isKeyword();

	XglTokenType getType();
	XglTokenSymbolType getSymbol();
	XglValueType getTypeFromKeyword();

	long getInteger();
	bool getBoolean();
	double getReal();
	string getString();

private:
	XglTokenType type;
	XglTokenSymbolType symbol;

	long lvalue;
	double dvalue;
	string svalue;
	bool bvalue;
};

