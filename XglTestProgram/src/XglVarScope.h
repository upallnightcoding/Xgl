#pragma once

#include "Xgl.h"
#include "XglSymbolTableRec.h"

class XglVarScope
{
public:
	XglVarScope();
	virtual ~XglVarScope();

private:
	map<string, XglSymbolTableRec*> scope;
};

