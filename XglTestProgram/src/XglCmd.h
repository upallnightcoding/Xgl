#pragma once

#include "XglNode.h"
#include "XglInterpreter.h"

class XglCmd
{
public:
	XglCmd(string name);
	virtual ~XglCmd();

public:
	virtual XglNode *execute(XglInterpreter *interpreter) = 0;

	string getName();

private:
	string name;
};
