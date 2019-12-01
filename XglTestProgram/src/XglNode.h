#pragma once

#include "Xgl.h"

#include "XglNode.h"
#include "XglValue.h"

enum class XglNodeType
{
	NODE_VALUE,

	NODE_UNKNOWN
};

class XglNode
{
public:
	XglNode();
	virtual ~XglNode();

public:
	virtual XglValue *execute() = 0;

private:
	list<XglNode*> attributes;
	XglNodeType type;
};

