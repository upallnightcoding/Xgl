#include "pch.h"
#include "XglNodeFor.h"
#include "XglNodeDeclareVar.h"
#include "XglNodeLe.h"
#include "XglNodeVariable.h"
#include "XglNodeAdd.h"
#include "XglNodeAssign.h"


XglNodeFor::XglNodeFor(XglToken *type, XglToken *variable, XglNode *init, XglNode *fin, XglNode *step, XglNode *codeBlock) :
	XglNode(XglNodeType::NODE_FOR)
{
	this->type = type;
	this->variable = variable;
	this->initialValue = init;
	this->finalValue = fin;
	this->stepValue = step;
	this->codeBlock = codeBlock;
}

XglNodeFor::~XglNodeFor()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeFor::execute(XglContext &context)
{
	// Construct index variable declaration
	//-------------------------------------
	XglNodeDeclareVar *declareIndexVar = new XglNodeDeclareVar(type, variable, initialValue);

	// Construct for loop index var
	//-----------------------------
	XglNode *indexVar = new XglNodeVariable(new XglValue(variable));

	// Construct for loop test, if index variable is <= final value
	//-------------------------------------------------------------
	XglNode *indexVarLeFin = new XglNodeLe();
	indexVarLeFin->add(indexVar);
	indexVarLeFin->add(finalValue);

	// Construct for loop index update
	//-------------------------------- 
	XglNodeAdd *addStep = new XglNodeAdd();
	addStep->add(indexVar);
	addStep->add(stepValue);

	// Construct loop index variable update & assignment
	//--------------------------------------------------
	XglNode *updateIndexVar = new XglNodeAssign(variable, addStep);


	// Execute Xgl For Loop
	//---------------------
	declareIndexVar->execute(context);

	while (indexVarLeFin->execute(context)->getBool()) {
		codeBlock->execute(context);
		updateIndexVar->execute(context);
	}

	return(NULL);
}
