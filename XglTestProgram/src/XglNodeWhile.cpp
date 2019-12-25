#include "pch.h"
#include "XglNodeWhile.h"


XglNodeWhile::XglNodeWhile(XglNode *expression, XglNode *codeBlock) : XglNode(XglNodeType::NODE_DECLARE)
{
	this->expression = expression;
	this->codeBlock = codeBlock;
}


XglNodeWhile::~XglNodeWhile()
{
}

XglValue *XglNodeWhile::execute(XglContext *context)
{

	while (expression->execute(context)->getBool()) {
		context->getSymbolTable()->createScope();

		codeBlock->execute(context);

		context->getSymbolTable()->deleteScope();
	}

	return(NULL);
}
