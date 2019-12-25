#pragma once
#include "XglCmd.h"

class XglCmdEnd :
	public XglCmd
{
public:
	XglCmdEnd();
	virtual ~XglCmdEnd();

public:
	virtual XglNode *execute(XglSyntax *syntax);
};

