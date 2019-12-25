#include "pch.h"
#include "XglNodeProgram.h"


XglNodeProgram::XglNodeProgram(XglNode *codeBlock) : XglNode(XglNodeType::NODE_PROGRAM)
{
	this->codeBlock = codeBlock;
}


XglNodeProgram::~XglNodeProgram()
{
}

XglValue *XglNodeProgram::execute(XglContext *context)
{
	context->getSymbolTable()->createScope();

	codeBlock->execute(context);

	context->getSymbolTable()->deleteScope();

	return(NULL);
}
