#pragma once

#include "Xgl.h"

//#include "XglNode.h"
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

	void add(XglNode *node);

	list<XglNode*> getAttributes();

private:
	list<XglNode*> attributes;
	XglNodeType type;
};

