#include "pch.h"
#include "XglNodeCodeBlock.h"


XglNodeCodeBlock::XglNodeCodeBlock() 
	: XglNode(XglNodeType::NODE_EXEC)
{
}


XglNodeCodeBlock::~XglNodeCodeBlock()
{
}

XglValue *XglNodeCodeBlock::execute(XglContext &context)
{
	for (XglNode *attribute : getCodeBlock()) {
		attribute->evaluate(context);
	}

	return(NULL);
}
