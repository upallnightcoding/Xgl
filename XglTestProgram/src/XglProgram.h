#pragma once

#include "Xgl.h"
#include "XglToken.h"
#include "XglNumber.h"

/*****************************************************************************
class XglProgram

This class is used to read tokens from a source input, one token at a time.
*****************************************************************************/

class XglProgramLine {
public:
	XglProgramLine(string sourceCode);

public:
	char getChar(size_t characterPos);
	size_t getLength();
	string getSource();

private:
	string sourceCode;
	size_t size;
};

class XglProgram
{
public:
	XglProgram();
	virtual ~XglProgram();

public:
	void add(string source);
	XglToken *getToken();
	string getErrorLine();
	bool isChar(char character);
	void readFile(string pathName);

private:
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
	size_t currentLine;
	vector<XglProgramLine> source;
	bool eop;
};

