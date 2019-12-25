#pragma once
#include "XglCmd.h"
#include "XglSyntax.h"

class XglCmdPrint :
	public XglCmd
{
public:
	XglCmdPrint();
	virtual ~XglCmdPrint();

public:
	virtual XglNode *execute(XglSyntax *syntax);
};

