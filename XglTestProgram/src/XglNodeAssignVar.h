#pragma once
#include "XglNode.h"
class XglNodeAssignVar :
	public XglNode
{
public:
	XglNodeAssignVar(string variableName);
	virtual ~XglNodeAssignVar();

public:
	XglValue *execute(XglContext *context);

	string getVariableName();

private:
	string variableName;
};

