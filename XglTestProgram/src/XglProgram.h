#pragma once

#include "Xgl.h"
#include "XglToken.h"
#include "XglNumber.h"

/*****************************************************************************
class XglProgram

This class is used to read tokens from a source input, one token at a time.
*****************************************************************************/

class XglProgram
{
public:
	XglProgram();
	virtual ~XglProgram();

public:
	void add(string source);
	XglToken *getToken();

private:
	bool isChar(char character);
	void moveToNextChar();
	char peekChar();
	void skipBlanks();
	bool isEop();

	XglToken *getString();
	XglToken *getKeyword();
	XglToken *getSingleToken();
	XglToken *getDoubleToken();
	XglToken *getNumber();

	XglNumber getInteger();

	XglTokenSymbolType getDoubleCharSymbol(char character, XglTokenSymbolType first, XglTokenSymbolType second);

private:
	size_t currentChar;
	string program;
	bool eop;
};

