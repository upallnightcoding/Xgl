#pragma once
#include "XglCmd.h"
#include "XglInterpreterAbstract.h"

/*****************************************************************************
class XglCommandConst - 

Command Syntax:

const 
	integer MIN_VALUE = 0,
	integer MAX_VALUE = 100;
*****************************************************************************/

class XglCmdConst :
	public XglCmd
{
public:
	XglCmdConst();
	virtual ~XglCmdConst();


public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter);
};

