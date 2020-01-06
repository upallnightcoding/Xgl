#pragma once
#include "XglCmd.h"
class XglCmdFunction :
	public XglCmd
{
public:
	XglCmdFunction();
	virtual ~XglCmdFunction();

public:
	XglNode *execute(XglInterpreter *interpreter);
};

