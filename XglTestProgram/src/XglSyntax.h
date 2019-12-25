#pragma once

#include "XglInterpreter.h"
#include "XglErrorMgr.h"

class XglSyntax
{
public:
	XglSyntax(XglInterpreter *interpreter);
	virtual ~XglSyntax();

public:
	XglInterpreter *getInterpreter();
	XglErrorMgr *getErrorMgr();

private:
	XglInterpreter *interpreter;
	XglErrorMgr *errorMrg;
};

