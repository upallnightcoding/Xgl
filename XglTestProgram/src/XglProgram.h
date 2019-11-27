#pragma once

#include "Xgl.h"
#include "XglToken.h"
#include "XglNumber.h"

/*****************************************************************************
class XglProgram
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

private:
	size_t currentChar;
	string program;
	bool eop;
};

