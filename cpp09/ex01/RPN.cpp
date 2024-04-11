#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cstdlib>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(char op, int operand1, int operand2) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else
                throw "Division by zero!";
        default:
            throw "Invalid operator!";
    }
}

int evaluateRPN(const std::string& expression) {
    std::stack<int> operands;
    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            operands.push(atoi(token.c_str()));
        } else if (isOperator(token[0])) {
            if (operands.size() < 2)
                throw "Not enough operands!";
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(performOperation(token[0], operand1, operand2));
        } else {
            throw "";
        }
    }
    if (operands.size() != 1)
        throw "Invalid expression!";
    return operands.top();
}
