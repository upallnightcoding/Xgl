#pragma once

#include "Xgl.h"

/*****************************************************************************
class XglProgram
*****************************************************************************/

class XglProgram
{
public:
	XglProgram();
	virtual ~XglProgram();

public:
	void addSourceCode(string code);

private:
	bool isChar(char character);
	void moveToNextChar();
	char getCurrentChar();
	void skipBlanks();
	bool isEop();

private:
	size_t currentChar;
	string program;
	bool eop;
};

