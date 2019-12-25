#pragma once
#include "XglCmd.h"
#include "XglInterpreter.h"

class XglCmdWhile :
	public XglCmd
{
public:
	XglCmdWhile();
	virtual ~XglCmdWhile();

public:
	XglNode *execute(XglSyntax *syntax);
};

