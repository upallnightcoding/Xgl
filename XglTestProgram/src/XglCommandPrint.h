#pragma once
#include "XglCommand.h"
class XglCommandPrint :
	public XglCommand
{
public:
	XglCommandPrint();
	virtual ~XglCommandPrint();

public:
	virtual XglNode *execute(XglInterpreter &interpreter);
};

