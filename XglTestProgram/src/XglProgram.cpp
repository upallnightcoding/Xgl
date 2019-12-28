#include "pch.h"
#include "XglProgram.h"

#include "XglNumber.h"


XglProgram::XglProgram()
{
	program = "";
	eop = false;
	currentChar = 0;

	add("program 'xxx';");
	/*add("	print '123=', 123;");
	add("	print '87=', 12 + 45 + 30;");
	add("	print '3=', (10 - 9) * 3;");
	add("	print '40=', 8 * 5;");
	add("	print '12.5=', 5.0 * 2.5;");
	add("	print 'AB=', 'A' + 'B';");
	add("	print '0=', 1 / 3;");
	add("	print '0.333=', 1.0 / 3;");
	add("	print '0=', 1 / 3.0;");
	add("	print 'z123m=', 'z' + 123 + 'm';");
	add("	print '-3=', ~3;");
	add("	print '3=', ~(~3);");
	add("	print '==================';");
	add("	print 'TRUE=', 1 < 3;");
	add("	print 'FALSE=', 3 < 1;");
	add("	print 'TRUE=', 'a' < 'b';");
	add("	print 'FALSE=', 3.45 < 1.9;");
	add("	print '==================';");
	add("	print 'FALSE=', 1 > 3;");
	add("	print 'TRUE=', 3 > 1;");
	add("	print 'FALSE=', 'a' > 'b';");
	add("	print 'TRUE=', 3.45 > 1.9;");
	add("	print '==================';");
	add("	print 'FALSE=', 1 == 3;");
	add("	print 'TRUE=', 3 == 3;");
	add("	print 'FALSE=', 'a' == 'b';");
	add("	print 'TRUE=', 1.9 == 1.9;");
	add("	print '==================';");
	add("	print 'TRUE=', 1 <= 3;");
	add("	print 'FALSE=', 3 <= 1;");
	add("	print 'TRUE=', 'b' <= 'b';");
	add("	print 'FALSE=', 3.45 <= 1.9;");
	add("	print '==================';");
	add("	print 'FALSE=', 1 >= 3;");
	add("	print 'TRUE=', 3 >= 1;");
	add("	print 'TRUE=', 'b' >= 'b';");
	add("	print 'TRUE=', 3.45 >= 1.9;");
	add("	print 'FALSE=', !(3.45 >= 1.9);");
	add("	print '==================';");*/
	
	/*add("	const ");
	add("		integer a = 11,");
	add("		real c = 23.45,");
	add("		string b = 'Constant';");
	add("	print 'Value: a=11=', a;");
	add("   print 'Value: c=23.45=', c;");
	add("   print 'Value: b=Constant=', b;");
	add("   print 'Value: true=', TRUE;");
	add("   print 'Value: false=', FALSE;");
	add("   print 'Value: PI=', PI;");
	add("   print 'Value: 2.0*PI=', 2.0*PI;");
	add("   print 'Value: 2*PI=', 2*PI;");*/

	/*add("	declare ");
	add("		real b = 10 * 20 - 1,");
	add("		integer c = 20 * ~2,");
	add("		real d ,");
	add("		integer a ;");
	add("	a = 99;");
	add("	d = false;");
	add("	print 'Value a,d,b:', a, ':', d, ':', b, ':', c;");*/

	/*add("	declare integer n = 10;");
	add("	while (n > 0);");
	add("		print 'n: ', n;");
	add("		n = n - 2;");
	add("	end;");*/

	/*add("	for integer n = 1, 3, 1;");
	add("		for integer m = 4, 6, 1;");
	add("			print 'For Loop: ', n, ':', m;");
	add("		end;");
	add("	end;"); */

	/*add("	# This is just a test of the if statement comment. # ");
	add("	declare integer n = 2;");
	add("	if (n == 1);");
	add("		print 'Value = 1';");
	add("	else;");
	add("		if (n == 2);");
	add("			print 'Value = 2';");
	add("		else;");
	add("			print 'Value is 3';");
	add("		end;");
	add("	end;");*/

	/*add("	declare integer x;");
	add("	declare integer y;");
	add("	x = (1 < 2) ? 10+3 : 20;");
	add("	y = (1 > 2) ? 10 : 20+7-2;");
	add("	print 'Value of x, y: ', x, ':', y;");*/

	add("	for integer n = 1, 2, 1;");
	add("		declare integer y = n;");
	add("		for integer m = 1, 3, 1;");
	add("			declare integer y = m;");
	add("			print 'For Loop: ', n, ':', m;");
	add("		end;");
	add("		print 'Value of y: ', y;");
	add("	end;"); 

	add("end;");

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
		// Check to see if current token is a single character
		//----------------------------------------------------
		token = getSingleToken();

		// Check to see if current token is a double character
		//----------------------------------------------------
		if (token == NULL) {
			token = getDoubleToken();
		}

		// Search for general token types
		//-------------------------------
		if (token == NULL) {
			if (isdigit(peekChar()) || isChar(XglConstant::DOT_CHAR)) {
				token = getNumber();
			}
			else if (isalpha(peekChar())) {
				token = getKeyword();
			}
			else if (isChar(XglConstant::SINGLE_QUOTE)) {
				token = getString();
			}
		}

		skipBlanks();
	}

	return(token);
}

/*****************************************************************************
getDoubleCharSymbol() - Returns a token object that represents a double
token.  A double token is defined as a token that can be made up of one or
two characters.  This function determines if the first character is a 
double token candidate.  If it is not, the token is ignored.  If it is, the
second token it checked.

Example:
	< or <=
	> or >=
*****************************************************************************/
XglToken *XglProgram::getDoubleToken() 
{
	XglTokenSymbolType symbol = XglTokenSymbolType::UNKNOWN;
	XglToken *token = NULL;

	// Search for the first character of a double token
	//-------------------------------------------------
	switch (peekChar()) {
	case '<':
		symbol = getDoubleCharSymbol('=', XglTokenSymbolType::SYMBOL_LT, XglTokenSymbolType::SYMBOL_LE);
		break;
	case '>':
		symbol = getDoubleCharSymbol('=', XglTokenSymbolType::SYMBOL_GT, XglTokenSymbolType::SYMBOL_GE);
		break;
	case '=':
		symbol = getDoubleCharSymbol('=', XglTokenSymbolType::SYMBOL_ASSIGN, XglTokenSymbolType::SYMBOL_EQ);
		break;
	case '!':
		symbol = getDoubleCharSymbol('=', XglTokenSymbolType::SYMBOL_NOT, XglTokenSymbolType::SYMBOL_NE);
		break;
	}

	// If a double token has been found, return a token object
	//--------------------------------------------------------
	if (symbol != XglTokenSymbolType::UNKNOWN) {
		token = new XglToken(symbol);
	}

	return(token);
}

/*****************************************************************************
getDoubleCharSymbol() -
*****************************************************************************/
XglTokenSymbolType XglProgram::getDoubleCharSymbol(char character, XglTokenSymbolType first, XglTokenSymbolType second) 
{
	XglTokenSymbolType symbol = first;

	moveToNextChar();

	if (isChar(character)) {
		symbol = second;
		moveToNextChar();
	}

	return(symbol);
}

/*****************************************************************************
getSingleToken() - Returns an object that represents a single token.  A single
token is defined as a single character.  This function identifies the 
character and moves off the character.
*****************************************************************************/
XglToken *XglProgram::getSingleToken()
{
	XglTokenSymbolType symbol = XglTokenSymbolType::UNKNOWN;

	// Identify the single token character
	//------------------------------------
	switch (peekChar()) {
	case '?':
		symbol = XglTokenSymbolType::SYMBOL_QUESTION;
		break;
	case ':':
		symbol = XglTokenSymbolType::SYMBOL_COLON;
		break;
	case '~':
		symbol = XglTokenSymbolType::SYMBOL_TILDE;
		break;
	case '+':
		symbol = XglTokenSymbolType::SYMBOL_PLUS;
		break;
	case '-':
		symbol = XglTokenSymbolType::SYMBOL_MINUS;
		break;
	case '*':
		symbol = XglTokenSymbolType::SYMBOL_MULT;
		break;
	case '/':
		symbol = XglTokenSymbolType::SYMBOL_DIVIDE;
		break;
	case ';':
		symbol = XglTokenSymbolType::SYMBOL_SEMI;
		break;
	case '{':
		symbol = XglTokenSymbolType::SYMBOL_LBRACE;
		break;
	case '}':
		symbol = XglTokenSymbolType::SYMBOL_RBRACE;
		break;
	case '(':
		symbol = XglTokenSymbolType::SYMBOL_LPAREN;
		break;
	case ')':
		symbol = XglTokenSymbolType::SYMBOL_RPAREN;
		break;
	case ',':
		symbol = XglTokenSymbolType::SYMBOL_COMMA;
		break;
	}

	XglToken *token = NULL;

	// Verify the token and create the token object
	//---------------------------------------------
	if (symbol != XglTokenSymbolType::UNKNOWN) {
		token = new XglToken(symbol);
		moveToNextChar();
	}

	return(token);
}

/*****************************************************************************
getKeyword() -
*****************************************************************************/
XglToken *XglProgram::getKeyword()
{
	string value = "";

	char keywordChar = peekChar();

	// Read all characters into a string constant until the end of keyword
	//--------------------------------------------------------------------
	while (isalnum(keywordChar)) {
		value += toupper(keywordChar);
		moveToNextChar();

		keywordChar = peekChar();
	}

	// Create token object
	//--------------------
	return(new XglToken(XglTokenType::KEYWORD, value));
}

/*****************************************************************************
getString() - Returns a string token to the caller.  A string is setoff by
a single quote, followed by a string of printable characters and then
ended with a terminating single quote.
*****************************************************************************/
XglToken *XglProgram::getString()
{
	string value = "";

	// Move off of the starting single quote
	//--------------------------------------
	moveToNextChar();

	// Read all characters into the string constant until the ending quote
	//--------------------------------------------------------------------
	while (!isChar(XglConstant::SINGLE_QUOTE)) {
		value += peekChar();
		moveToNextChar();
	}

	// Move off of the ending single quote
	//------------------------------------
	moveToNextChar();

	// Create token object
	//--------------------
	return(new XglToken(XglTokenType::STRING, value));
}

/*****************************************************************************
getNumber() -
*****************************************************************************/
XglToken *XglProgram::getNumber()
{
	XglNumber number = getInteger();

	if (isChar(XglConstant::DOT_CHAR)) {
		moveToNextChar();

		XglNumber fraction = getInteger();

		number.add(fraction);
	}

	return(number.getToken());
}

/*****************************************************************************
getInteger() - Returns an object that returns a representation of a integer
number.  The returning object not only contains the integer value but also
the number of digits that make up the integer value.  The integer is read
one character at a time.  Each charater is summed into the total by 
multiplying the current value by 10 and adding in the current value.

Example: 123
	value = (10 * 0) + 1;
	value = (10 * 1) + 2;
	value = (10 * 12) + 3;
	value = 123
*****************************************************************************/
XglNumber XglProgram::getInteger()
{
	long value = 0;
	int ndigits = 0;

	// Read integer values, one digit at a time
	//-----------------------------------------
	while ((!isEop()) && (isdigit(peekChar()))) {
		value = (10 * value) + (peekChar() - '0');

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
	program = program + XglConstant::SPACE_CHAR + source;
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
		while ((!isEop()) && (isspace(peekChar()))) {
			moveToNextChar();
		}

		if ((!eop) && (isChar(XglConstant::POUND_CHAR))) {
			moveToNextChar();

			while ((!eop) && (!isChar(XglConstant::POUND_CHAR))) {
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
	return(character == peekChar());
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
char XglProgram::peekChar()
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

