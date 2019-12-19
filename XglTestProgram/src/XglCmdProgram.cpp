#include "pch.h"
#include "XglCmdProgram.h"
#include "XglNodeCodeBlock.h"
#include "XglNodeProgram.h"

XglCmdProgram::XglCmdProgram() 
	: XglCmd("PROGRAM")
{
}


XglCmdProgram::~XglCmdProgram()
{
}


/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdProgram::execute(XglInterpreter *interpreter)
{
	// Skip over end of statement token
	//---------------------------------
	interpreter->skipOver();

	// Create code block object and read first while loop statement
	//-------------------------------------------------------------
	XglNode *codeBlock = new XglNodeCodeBlock();
	XglNode *statement = interpreter->parseStatement();

	// Continue to read and collect statements until the "END"
	//--------------------------------------------------------
	while (!statement->isEnd()) {
		codeBlock->add(statement);

		statement = interpreter->parseStatement();
	}

	// Create the program node
	//------------------------
	return(new XglNodeProgram(codeBlock));
}
