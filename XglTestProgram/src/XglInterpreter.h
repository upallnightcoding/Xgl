#pragma once

#include "Xgl.h"
#include "XglProgram.h"
#include "XglNode.h"
#include "XglExpression.h"
#include "XglExpParse.h"

enum class XglErrorMessageType
{
	EOS_EXPECTED,
	UNKNOWN
};

class XglCmd;
class XglSyntax;

class XglInterpreter 
{
public:
	XglInterpreter(XglProgram *program);
	virtual ~XglInterpreter();

public:
	XglNode *parseStatement();
	XglExpParse *parseExpression();
	void parseArray(XglNode *arrayVariable);

	XglToken *getToken();
	bool skipOver(XglTokenSymbolType symbol);
	XglNode *assign (string keyword);

	void error(XglErrorMessageType type);

	bool isNoErrors();
	int getnErrors();

private:
	void add(XglCmd *command);

	string getErrorMessage(XglErrorMessageType type);

private:
	XglProgram *program;
	map<string, XglCmd*> commandMap;
	XglExpression expression;
	int nErrors;
};

#include "XglCmd.h"