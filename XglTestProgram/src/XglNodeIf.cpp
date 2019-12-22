#include "pch.h"
#include "XglNodeIf.h"

XglNodeIf::XglNodeIf() : XglNode(XglNodeType::NODE_IF)
{
	this->nIfs = 0;
	this->elseStatement = NULL;
}

XglNodeIf::~XglNodeIf()
{
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglNodeIf::add(XglNode *expression, XglNode *codeBlock)
{
	expressions[nIfs] = expression;
	codeBlocks[nIfs] = codeBlock;

	nIfs++;
}

/*****************************************************************************
setElse() -
*****************************************************************************/
void XglNodeIf::setElse(XglNode *codeBlock)
{
	elseStatement = codeBlock;
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeIf::execute(XglContext &context)
{
	int foundTrue = -1;

	for (int i = 0; (i < nIfs) && (foundTrue == -1); i++) {
		if (expressions[i]->execute(context)->getBool()) {
			foundTrue = i;
		}
	}

	if (foundTrue >= 0) {
		codeBlocks[foundTrue]->execute(context);
	}
	else {
		if (elseStatement != NULL) {
			elseStatement->execute(context);
		}
	}

	return(NULL);
}