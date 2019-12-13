#pragma once
#include "XglCmd.h"
#include "XglInterpreterAbstract.h"
class XglCommandProgram :
	public XglCmd
{
public:
	XglCommandProgram();
	virtual ~XglCommandProgram();

public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter);
};

