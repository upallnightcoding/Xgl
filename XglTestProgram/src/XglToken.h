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
	SYMBOL_ADD,	// '+'
	SYMBOL_SUB,	// '-'

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
	SYMBOL_RIGHT_PAREN,
	SYMBOL_LEFT_PAREN,

	// Left & Right Brace {}
	//----------------------
	SYMBOL_LEFT_BRACE,
	SYMBOL_RIGHT_BRACE,

	// Left & Right Brace []
	//----------------------
	SYMBOL_LEFT_BRACKET,
	SYMBOL_RIGHT_BRACKET,

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

	bool is(XglTokenSymbolType target);
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
	bool isRightBracket();
	bool isLeftBracket();

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

