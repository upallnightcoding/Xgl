#pragma once
#include "XglCommand.h"
class XglCommandDeclare :
	public XglCommand
{
public:
	XglCommandDeclare();
	virtual ~XglCommandDeclare();

public:
	XglNode *execute(XglInterpreterAbstract *interpreter);
};

