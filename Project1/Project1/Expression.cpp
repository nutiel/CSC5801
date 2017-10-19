#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"
#include "Expression.h"

Expression::Expression(int b, int e, vector< string> input) :
value(0),
begin(b),
end(e),
syntaxOk(true),
if_stmt(input) {

}

Expression::~Expression() {

}

int Expression::getValue() {
	return value;
}

bool Expression::getSyntaxCheck() {
	return syntaxOk;
}