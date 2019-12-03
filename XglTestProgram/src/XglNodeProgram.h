#pragma once
#include "XglNode.h"
#include "XglValue.h"

class XglNodeProgram :
	public XglNode
{
public:
	XglNodeProgram();
	virtual ~XglNodeProgram();

public:
	virtual XglValue *execute();
};

