#pragma once


#include "XglNode.h"

class XglSyntax;

class XglCmd
{
public:
	XglCmd(string name);
	virtual ~XglCmd();

public:
	virtual XglNode *execute(XglSyntax *syntax) = 0;

	string getName();

private:
	string name;
};

#include "XglSyntax.h"

