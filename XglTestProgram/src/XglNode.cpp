#include "pch.h"
#include "XglNode.h"


XglNode::XglNode()
{
	this->type = XglNodeType::NODE_UNKNOWN;
}

XglNode::~XglNode()
{
}

void XglNode::add(XglNode *node)
{
	attributes.push_back(node);
}

list<XglNode*> XglNode::getAttributes()
{
	return(attributes);
}
