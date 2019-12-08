#pragma once
#include "XglCommand.h"
#include "XglInterpreterAbstract.h"

/*****************************************************************************
class XglCommandConst - 

Command Syntax:

const 
	integer MIN_VALUE = 0,
	integer MAX_VALUE = 100;
*****************************************************************************/

class XglCommandConst :
	public XglCommand
{
public:
	XglCommandConst();
	virtual ~XglCommandConst();


public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter);
};

