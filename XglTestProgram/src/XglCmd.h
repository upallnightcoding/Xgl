#pragma once

#include "XglInterpreterAbstract.h"
#include "XglNode.h"

class XglCmd
{
public:
	XglCmd(string name);
	virtual ~XglCmd();

public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter) = 0;

	string getName();

private:
	string name;
};

