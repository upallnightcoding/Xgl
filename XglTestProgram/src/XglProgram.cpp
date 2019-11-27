#include "pch.h"
#include "XglProgram.h"

#include "XglNumber.h"


XglProgram::XglProgram()
{
	program = "";
	eop = false;
	currentChar = 0;

	add("  123  345    'this is a test' 678 ");
	add("333  88    90909 123.456 'String ending a line'   ");
	add(" 'String at the start' 0678.0999 0.00543 ");

	skipBlanks();
}


XglProgram::~XglProgram()
{
}

/*****************************************************************************
getToken() -
*****************************************************************************/
XglToken *XglProgram::getToken()
{
	XglToken *token = NULL;

	if (!isEop()) {
		if (isdigit(getCurrentChar()) || isChar(XglConstants::DOT_CHAR)) {
			token = getNumber();
		}
		else if (isChar(XglConstants::SINGLE_QUOTE)) {
			token = getString();
		}

		skipBlanks();
	}

	return(token);
}

/*****************************************************************************
getString() -
*****************************************************************************/
XglToken *XglProgram::getString()
{
	string value = "";

	// Move off of the starting single quote
	//--------------------------------------
	moveToNextChar();

	// Read all characters into the string constant until the ending quote
	//--------------------------------------------------------------------
	while (!isChar(XglConstants::SINGLE_QUOTE)) {
		value += getCurrentChar();
		moveToNextChar();
	}

	// Move off of the ending single quote
	//------------------------------------
	moveToNextChar();

	return(new XglToken(XglTokenType::STRING, value));
}

/*****************************************************************************
getNumber() -
*****************************************************************************/
XglToken *XglProgram::getNumber()
{
	XglNumber number = getInteger();

	if (isChar(XglConstants::DOT_CHAR)) {
		moveToNextChar();

		XglNumber fraction = getInteger();

		number.add(fraction);
	}

	return(number.getToken());
}

/*****************************************************************************
getInteger() -
*****************************************************************************/
XglNumber XglProgram::getInteger()
{
	long value = 0;
	int ndigits = 0;

	while ((!isEop()) && (isdigit(getCurrentChar()))) {
		value = (10 * value) + (getCurrentChar() - '0');

		ndigits++;

		moveToNextChar();
	}

	return(XglNumber(value, ndigits));
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglProgram::add(string source)
{
	program = program + XglConstants::SPACE_CHAR + source;
}

/*****************************************************************************
skipBlanks() - Skips white space between tokens.  If a '#' is detected, then
it is taken as a comment.  All characters between the '#' are skipped.  The
ending '#' is also skipped and the skipping of blanks then continues.
*****************************************************************************/
void XglProgram::skipBlanks()
{
	bool skipping = true;

	while (skipping) {
		while ((!isEop()) && (isspace(getCurrentChar()))) {
			moveToNextChar();
		}

		if ((!eop) && (isChar(XglConstants::POUND_CHAR))) {
			moveToNextChar();

			while ((!eop) && (isChar(XglConstants::POUND_CHAR))) {
				moveToNextChar();
			}

			if (!eop) {
				moveToNextChar();
			}
		}
		else {
			skipping = false;
		}
	}

}

/*****************************************************************************
isChar() - Returns true if the current active program character is the
same as the parameter passed.  It returns false otherwise.
*****************************************************************************/
bool XglProgram::isChar(char character)
{
	return(character == getCurrentChar());
}

/*****************************************************************************
nextChar() - Skips to the next character in the source code.
*****************************************************************************/
void XglProgram::moveToNextChar()
{
	if (!eop) {
		currentChar++;

		if (currentChar >= program.length()) {
			eop = true;
		}
	}
}

/*****************************************************************************
getCurrentChar() - Returns the current active character in the source code.
*****************************************************************************/
char XglProgram::getCurrentChar()
{
	return(program.at(currentChar));
}

/*****************************************************************************
isEop() - Returns the value of the end-of-program pointer.
*****************************************************************************/
bool XglProgram::isEop()
{
	return(eop);
}

