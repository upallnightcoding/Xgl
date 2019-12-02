#pragma once
#include "XglCommand.h"
#include "XglInterpreterAbstract.h"

class XglCommandPrint :
	public XglCommand
{
public:
	XglCommandPrint();
	virtual ~XglCommandPrint();

public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter);
};

