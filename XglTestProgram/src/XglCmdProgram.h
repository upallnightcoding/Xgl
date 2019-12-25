#pragma once
#include "XglCmd.h"
#include "XglSyntax.h"

class XglCmdProgram :
	public XglCmd
{
public:
	XglCmdProgram();
	virtual ~XglCmdProgram();

public:
	virtual XglNode *execute(XglSyntax *syntax);
};

