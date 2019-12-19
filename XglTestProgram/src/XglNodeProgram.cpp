#include "pch.h"
#include "XglNodeProgram.h"


XglNodeProgram::XglNodeProgram(XglNode *codeBlock) : XglNode(XglNodeType::NODE_PROGRAM)
{
	this->codeBlock = codeBlock;
}


XglNodeProgram::~XglNodeProgram()
{
}

XglValue *XglNodeProgram::execute(XglContext &context)
{
	codeBlock->execute(context);

	return(NULL);
}
