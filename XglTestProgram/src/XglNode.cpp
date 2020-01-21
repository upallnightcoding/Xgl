#include "pch.h"
#include "XglNode.h"


XglNode::XglNode(XglNodeType type)
{
	this->type = type;
}

XglNode::~XglNode()
{
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglNode::add(XglNode *code)
{
	children.push_back(code);
}

/*****************************************************************************
getAttributes() -
*****************************************************************************/
vector<XglNode*> XglNode::getAttributes()
{
	return(children);
}

/*****************************************************************************
isEnd() - Returns true if the node is a END statement node.
*****************************************************************************/
bool XglNode::isEnd() 
{
	return(type == XglNodeType::NODE_END);
}

/*****************************************************************************
isElseIf() - Returns true if the node is a ELSEIF statement node.
*****************************************************************************/
bool XglNode::isElseIf() 
{
	return(type == XglNodeType::NODE_ELSEIF);
}

/*****************************************************************************
isElse() - Returns true if the node is a ELSE statement node.
*****************************************************************************/
bool XglNode::isElse()
{
	return(type == XglNodeType::NODE_ELSE);
}

/*****************************************************************************
evaluate() -
*****************************************************************************/
XglValue *XglNode::evaluate(XglContext *context) 
{
	return(execute(context));
}

/*****************************************************************************
evaluate() -
*****************************************************************************/
XglValue *XglNode::evaluate(int index, XglContext *context) 
{
	return(children[index]->execute(context)); 
}

/*****************************************************************************
getnChildren() - Returns the number of children in the node
*****************************************************************************/
int XglNode::getnChildren()
{
	return(children.size());
}
