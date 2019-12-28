#pragma once
#include "XglCmd.h"

class XglCmdPrint :
	public XglCmd
{
public:
	XglCmdPrint();
	virtual ~XglCmdPrint();

public:
	virtual XglNode *execute(XglInterpreter *interpreter);
};

