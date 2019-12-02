#pragma once

#include "XglInterpreterAbstract.h"
#include "XglNode.h"

class XglCommand
{
public:
	XglCommand(string name);
	virtual ~XglCommand();

public:
	virtual XglNode *execute(XglInterpreterAbstract *interpreter) = 0;

	string getName();

private:
	string name;
};

