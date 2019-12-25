#pragma once
#include "XglCmd.h"
class XglCmdFor :
	public XglCmd
{
public:
	XglCmdFor();
	virtual ~XglCmdFor();

public:
	XglNode *execute(XglSyntax *syntax);
};

