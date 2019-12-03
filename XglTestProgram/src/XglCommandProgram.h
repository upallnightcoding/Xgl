#pragma once
#include "XglCommand.h"
#include "XglInterpreterAbstract.h"
class XglCommandProgram :
	public XglCommand
{
public:
	XglCommandProgram();
	virtual ~XglCommandProgram();

public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter);
};

