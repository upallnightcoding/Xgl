#pragma once
#include "XglCmd.h"

class XglCmdDeclare :
	public XglCmd
{
public:
	XglCmdDeclare();
	virtual ~XglCmdDeclare();

public:
	XglNode *execute(XglInterpreter *interpreter);
};

