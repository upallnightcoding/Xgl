#include "pch.h"
#include "XglExpression.h"
#include "XglNodeAdd.h"
#include "XglNodeMult.h"
#include "XglNodeSub.h"
#include "XglNodeDivide.h"
#include "XglNodeValue.h"
#include "XglNodeNot.h"
#include "XglNodeNeg.h"

XglExpression::XglExpression()
{
	oprStack.push(new XglToken(XglTokenSymbolType::TOKEN_SYMBOL_EOE));
}

XglExpression::~XglExpression()
{
}

XglToken *XglExpression::getLastToken()
{
	return(lastToken);
}

/*****************************************************************************
parse()
*****************************************************************************/
/*XglNode *XglExpression::parse(XglProgram &program)
{
	this->program = program;
	this->lastToken = NULL;

	XglNode *expression = parse();

	return(expression);
}*/

/*****************************************************************************
parse()
*****************************************************************************/
XglNode *XglExpression::parse(XglProgram &program)
{
	int balance = 0;
	bool interpreting = true;

	lastToken = NULL;

	while (interpreting) {
		XglToken *token = program.getToken();

		if (token->isEndExpression()) {
			interpreting = false;
			lastToken = token;
		}
		else if (token->isConstant()) {
			expStack.push(new XglNodeValue(new XglValue(token)));
		}
		//else if (token->isKeyword()) {
			//pushKeywordOnExpStack(token);
		//}
		else if (token->isLeftParen()) {
			balance++;
			oprStack.push(token);
		}
		else if (token->isRightParen() && (balance == 0)) {
			interpreting = false;
			lastToken = token;
		}
		else if (token->isRightParen()) {
			balance--;
			popUntilRightParen();
		}
		else if (token->isOperator()) {
			pushOperOnStack(token);
		}
	}

	emptyOprStack();

	return (expStack.top());
}

/*****************************************************************************
emptyOprStack()
*****************************************************************************/
void XglExpression::emptyOprStack() 
{
	while (!oprStack.top()->isEOE()) {
		popOprStack();
	}
}

/*****************************************************************************
popUntilRightParen()
*****************************************************************************/
void XglExpression::popUntilRightParen() 
{
	// Pop the operator stack until the first left parenthesis
	//--------------------------------------------------------
	while (!oprStack.top()->isLeftParen()) {
		popOprStack();
	}

	// Pop the left parenthesis off the stack
	//---------------------------------------
	oprStack.pop();
}

/*****************************************************************************
pushOperOnStack()
*****************************************************************************/
void XglExpression::pushOperOnStack(XglToken *token) 
{
	while (token->rank() <= oprStack.top()->rank()) {
		popOprStack();
	}

	oprStack.push(token);
}

/*****************************************************************************
popOprStack()
*****************************************************************************/
void XglExpression::popOprStack() 
{
	XglNode *expression = NULL;
	XglTokenSymbolType symbol = oprStack.top()->getSymbol();

	switch (symbol) {
	case XglTokenSymbolType::TOKEN_SYMBOL_PLUS:
		expression = new XglNodeAdd();
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_MULT: 
		expression = new XglNodeMult();
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_MINUS:
		expression = new XglNodeSub();
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_DIVIDE:
		expression = new XglNodeDivide();
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_TILDE:
		expression = new XglNodeNeg();
		break;
	case XglTokenSymbolType::TOKEN_SYMBOL_NOT:
		expression = new XglNodeNot();
		break;
	}

	if (expression != NULL) {
		switch (symbol) {
		case XglTokenSymbolType::TOKEN_SYMBOL_TILDE:
		case XglTokenSymbolType::TOKEN_SYMBOL_NOT:
			expression->add(expStack.top());
			expStack.pop();
			break;
		default:
			XglNode *value2 = expStack.top(); expStack.pop();
			XglNode *value1 = expStack.top(); expStack.pop();

			expression->add(value1);
			expression->add(value2);
			break;
		}
	}

	expStack.push(expression);

	oprStack.pop();
}
