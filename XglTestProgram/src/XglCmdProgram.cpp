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
XglNode *XglCmdProgram::execute(XglSyntax *syntax)
{
	// Skip over end of statement token
	//---------------------------------
	syntax->getInterpreter()->skipOver();

	// Create code block object and read first while loop statement
	//-------------------------------------------------------------
	XglNode *codeBlock = new XglNodeCodeBlock();
	XglNode *statement = syntax->getInterpreter()->parseStatement();

	// Continue to read and collect statements until the "END"
	//--------------------------------------------------------
	while (!statement->isEnd()) {
		codeBlock->add(statement);

		statement = syntax->getInterpreter()->parseStatement();
	}

	// Create the program node
	//------------------------
	return(new XglNodeProgram(codeBlock));
}
