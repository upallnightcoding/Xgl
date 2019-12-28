#pragma once
#include "XglCmd.h"
class XglCmdElse :
	public XglCmd
{
public:
	XglCmdElse();
	virtual ~XglCmdElse();

public:
	XglNode *execute(XglInterpreter *interpreter);
};

