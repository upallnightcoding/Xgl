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
	codeBlock.push_back(code);
}

/*****************************************************************************
getAttributes() -
*****************************************************************************/
vector<XglNode*> XglNode::getCodeBlock()
{
	return(codeBlock);
}

/*****************************************************************************
isEnd() -
*****************************************************************************/
bool XglNode::isEnd() {
	return(type == XglNodeType::NODE_END);
}

/*****************************************************************************
evaluate() -
*****************************************************************************/
XglValue *XglNode::evaluate(XglContext &context) 
{
	return(execute(context));
}

/*****************************************************************************
evaluate() -
*****************************************************************************/
XglValue *XglNode::evaluate(int index, XglContext &context) 
{
	return(codeBlock[index]->execute(context)); 
}
