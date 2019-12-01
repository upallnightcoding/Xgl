#pragma once

#include "XglInterpreter.h"
#include "XglNode.h"

class XglCommand
{
public:
	XglCommand();
	virtual ~XglCommand();

public:
	virtual XglNode *execute(XglInterpreter &interpreter) = 0;
};

