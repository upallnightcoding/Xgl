#include "pch.h"
#include "XglNodeCodeBlock.h"


XglNodeCodeBlock::XglNodeCodeBlock() 
	: XglNode(XglNodeType::NODE_EXEC)
{
}


XglNodeCodeBlock::~XglNodeCodeBlock()
{
}

/*****************************************************************************
execute() - Executes the statements that are in a code block.  Each command
is execute in order presented in the block.  This block can be used for any
set of statements, but is usually used to represent a set of statement within
a programming scope.
*****************************************************************************/
XglValue *XglNodeCodeBlock::execute(XglContext &context)
{
	for (XglNode *attribute : getAttributes()) {
		attribute->evaluate(context);
	}

	return(NULL);
}
