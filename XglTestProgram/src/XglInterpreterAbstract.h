#pragma once

#include "XglNode.h"
#include "XglToken.h"

class XglInterpreterAbstract
{
public:
	XglInterpreterAbstract();
	virtual ~XglInterpreterAbstract();

public:
	virtual XglNode *parseStatement() = 0;
	virtual XglNode *parseExpression() = 0;
	virtual XglToken *getToken() = 0;
	virtual XglToken *getLastToken() = 0;
};

