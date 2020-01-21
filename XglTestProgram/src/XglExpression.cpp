#include "pch.h"
#include "XglExpression.h"
#include "XglNodeValue.h"
#include "XglNodeVariable.h"
#include "XglNodeBinaryOperator.h"
#include "XglNodeUnaryOperator.h"

XglExpression::XglExpression()
{
}

XglExpression::~XglExpression()
{
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
XglExpParse *XglExpression::parse(XglProgram &program)
{
	stack<XglNode*> expStack;
	stack<XglToken*> oprStack;
	int parenCount = 0;
	bool interpreting = true;
	XglToken *lastToken = NULL;

	oprStack.push(new XglToken(XglTokenSymbolType::SYMBOL_EOE));

	while (interpreting) {
		XglToken *token = program.getToken();

		if (token->isEndExpression()) {
			interpreting = false;
			lastToken = token;
		}
		else if (token->isConstant()) {
			expStack.push(new XglNodeValue(new XglValue(token)));
		}
		else if (token->isKeyword()) {
			pushKeywordOnExpStack(program, token, expStack);
		}
		else if (token->isLeftParen()) {
			parenCount++;
			oprStack.push(token);
		}
		else if (token->isRightParen() && (parenCount == 0)) {
			interpreting = false;
			lastToken = token;
		}
		else if (token->isRightParen()) {
			parenCount--;
			popUntilRightParen(oprStack, expStack);
		}
		else if (token->isOperator()) {
			pushOperOnStack(token, oprStack, expStack);
		}
	}

	emptyOprStack(oprStack, expStack);

	return (new XglExpParse(expStack.top(), lastToken));
}

/*****************************************************************************
pushKeywordOnExpStack() -
*****************************************************************************/
void XglExpression::pushKeywordOnExpStack(XglProgram &program, XglToken *token, stack<XglNode*> &expStack)
{
	XglValue *variable = new XglValue(token);

	// TODO If this is the only place the "variable" could be a string
	XglNode *value = new XglNodeVariable(variable);
	XglToken *lBracket = NULL;
	XglExpParse *element = NULL;

	if (program.isChar('[')) {
		lBracket = program.getToken();

		do {
			element = parse(program);
			value->add(element->getExpression());
		} while (!element->getLastToken()->isRightBracket());

		delete lBracket;
	}

	//XglSymbolTableRec *record = symbolTable->find(variable);
	//XglNode *value = NULL;

	/*if (record != NULL) {
		if (record->isConstant()) {
			value = new XglNodeValue(record->getValue());
		}
		//else if (record->isVariable()) {
			//value = new XglNodeValue(variable);
		//}
		//else if (record->isSystemFunction()) {
			//value = new XglNodeSystemFunction(record, parseArguments());
		//}
	}
	else {
		value = new XglNodeValue(variable);
	}*/

	expStack.push(value);
}

/*****************************************************************************
emptyOprStack()
*****************************************************************************/
void XglExpression::emptyOprStack(stack<XglToken*> &oprStack, stack<XglNode*> &expStack)
{
	while (!oprStack.top()->isEOE()) {
		popOprStack(oprStack, expStack);
	}
}

/*****************************************************************************
popUntilRightParen()
*****************************************************************************/
void XglExpression::popUntilRightParen(stack<XglToken*> &oprStack, stack<XglNode*> &expStack)
{
	// Pop the operator stack until the first left parenthesis
	//--------------------------------------------------------
	while (!oprStack.top()->isLeftParen()) {
		popOprStack(oprStack, expStack);
	}

	// Pop the left parenthesis off the stack
	//---------------------------------------
	oprStack.pop();
}

/*****************************************************************************
pushOperOnStack()
*****************************************************************************/
void XglExpression::pushOperOnStack(XglToken *token, stack<XglToken*> &oprStack, stack<XglNode*> &expStack)
{
	while (token->rank() <= oprStack.top()->rank()) {
		popOprStack(oprStack, expStack);
	}

	oprStack.push(token);
}

/*****************************************************************************
popOprStack()
*****************************************************************************/
void XglExpression::popOprStack(stack<XglToken*> &oprStack, stack<XglNode*> &expStack)
{
	XglNode *expression = NULL;
	XglTokenSymbolType symbol = oprStack.top()->getSymbol();

	switch (symbol) {
	case XglTokenSymbolType::SYMBOL_ADD:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_ADD);
		break;
	case XglTokenSymbolType::SYMBOL_MULT: 
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_MULT);
		break;
	case XglTokenSymbolType::SYMBOL_SUB:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_SUB);
		break;
	case XglTokenSymbolType::SYMBOL_DIVIDE:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_DIVIDE);
		break;
	case XglTokenSymbolType::SYMBOL_LT:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_LT);
		break;
	case XglTokenSymbolType::SYMBOL_GT:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_GT);
		break;
	case XglTokenSymbolType::SYMBOL_EQ:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_EQ);
		break;
	case XglTokenSymbolType::SYMBOL_NE:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_NE);
		break;
	case XglTokenSymbolType::SYMBOL_GE:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_GE);
		break;
	case XglTokenSymbolType::SYMBOL_LE:
		expression = new XglNodeBinaryOperator(XglNodeType::NODE_LE);
		break;
	case XglTokenSymbolType::SYMBOL_TILDE:
		expression = new XglNodeUnaryOperator(XglNodeType::NODE_NEG);
		break;
	case XglTokenSymbolType::SYMBOL_NOT:
		expression = new XglNodeUnaryOperator(XglNodeType::NODE_NOT);
		break;
	}

	if (expression != NULL) {
		switch (symbol) {
		case XglTokenSymbolType::SYMBOL_TILDE:
		case XglTokenSymbolType::SYMBOL_NOT:
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
