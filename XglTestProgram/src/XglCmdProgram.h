#pragma once
#include "XglCmd.h"
#include "XglInterpreter.h"

class XglCmdProgram :
	public XglCmd
{
public:
	XglCmdProgram();
	virtual ~XglCmdProgram();

public:
	virtual XglNode *execute(XglInterpreter *interpreter);
};

