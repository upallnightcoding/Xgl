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
	UNKNOWN,

	SYMBOL_EOE,

	// Not Operators
	//--------------
	SYMBOL_TILDE,	// '~'
	SYMBOL_NOT,		// '!'

	// Triplet operators
	SYMBOL_QUESTION,	// '?'
	SYMBOL_COLON,		// ':'

	// Binary Operators
	//-----------------
	SYMBOL_MULT,	// '*'
	SYMBOL_DIVIDE,	// '/'
	SYMBOL_PLUS,	// '+'
	SYMBOL_MINUS,	// '-'

	// Conditional Operators
	//----------------------
	SYMBOL_EQ,	// ==
	SYMBOL_NE,	// !=
	SYMBOL_GT,	// >
	SYMBOL_LT,	// <
	SYMBOL_GE,	// <=
	SYMBOL_LE,	// <=

	// Left & Right Parentheses ()
	//----------------------------
	SYMBOL_RPAREN,
	SYMBOL_LPAREN,

	// Left & Right Brace {}
	//----------------------
	SYMBOL_LBRACE,
	SYMBOL_RBRACE,

	// Variable assignment operator '='
	//---------------------------------
	SYMBOL_ASSIGN,

	// Statement separator token ';'
	//------------------------------
	SYMBOL_SEMI,

	// Expression separator token ','
	//-------------------------------
	SYMBOL_COMMA
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
	bool isAssignment();
	bool isColon();
	bool isQuestion();

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

