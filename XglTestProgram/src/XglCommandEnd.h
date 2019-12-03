#pragma once
#include "XglCommand.h"
class XglCommandEnd :
	public XglCommand
{
public:
	XglCommandEnd();
	virtual ~XglCommandEnd();

public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter);
};

