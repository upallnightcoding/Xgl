#pragma once

#include "Xgl.h"
#include "XglToken.h"
#include "XglNumber.h"

/*****************************************************************************
class XglProgram

This class is used to read token from a source input, one token at a time.
*****************************************************************************/

class XglProgram
{
public:
	XglProgram();
	virtual ~XglProgram();

public:
	void add(string source);
	XglToken *getToken();
	bool isEop();

private:
	bool isChar(char character);
	void moveToNextChar();
	char getCurrentChar();
	void skipBlanks();

	XglToken *getString();

	XglToken *getNumber();

	XglNumber getInteger();

	XglToken *getSingleToken();
	XglToken *getDoubleToken();
	XglTokenSymbolType getDoubleCharSymbol(char character, XglTokenSymbolType first, XglTokenSymbolType second);

private:
	size_t currentChar;
	string program;
	bool eop;
};

