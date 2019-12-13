#pragma once
#include "XglCmd.h"
#include "XglInterpreterAbstract.h"

class XglCommandPrint :
	public XglCmd
{
public:
	XglCommandPrint();
	virtual ~XglCommandPrint();

public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter);
};

