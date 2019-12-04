#pragma once
#include "XglNode.h"
#include "XglValue.h"
#include "XglContext.h"

class XglNodeProgram :
	public XglNode
{
public:
	XglNodeProgram();
	virtual ~XglNodeProgram();

public:
	virtual XglValue *execute(XglContext &context);
};

