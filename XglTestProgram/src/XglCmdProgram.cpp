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
	XglNode *codeBlock = NULL;
	XglNode *command = NULL;

	// Skip over end of statement token
	//---------------------------------
	if (interpreter->skipOver(XglTokenSymbolType::SYMBOL_SEMI)) {

		// Create code block object and read first while loop statement
		//-------------------------------------------------------------
		codeBlock = new XglNodeCodeBlock();
		XglNode *statement = interpreter->parseStatement();

		// Continue to read and collect statements until the "END"
		//--------------------------------------------------------
		while (!statement->isEnd()) {
			codeBlock->add(statement);

			statement = interpreter->parseStatement();
		}

		// Set the node command
		//---------------------
		command = new XglNodeProgram(codeBlock);
	}
	else {
		interpreter->error(XglErrorMessageType::EOS_EXPECTED);
	}

	// Create the program node
	//------------------------
	return(command);
}
