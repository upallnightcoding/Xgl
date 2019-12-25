#pragma once
#include "XglCmd.h"
class XglCmdElseIf :
	public XglCmd
{
public:
	XglCmdElseIf();
	virtual ~XglCmdElseIf();

public:
	XglNode *execute(XglSyntax *syntax);
};

