#include "sstream"
#include "string"
#include "iostream"
#include "calculator.h"

int calc(int lhs, int rhs, char op) {
	switch (op) {
		case '+':
			return lhs + rhs;
		case '-':
			return lhs - rhs;
		case '*':
			return lhs * rhs;
		case '/':
			return rhs == 0 ? -1 : lhs / rhs;
		case '%':
			return rhs == 0 ? -1 : lhs % rhs;
		default:
			// Handle exception?
			break;
	}
	return -1;
}

int calc(std::istream& in){
	int lhs{-1};
	char op {};
	int rhs{-1};
	if(in >> lhs >> op >> rhs){
		return calc(lhs,rhs, op);
	}
	// Handle exception?
	return -1;
}