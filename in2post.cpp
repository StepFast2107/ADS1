#include "GenericStack.cpp"
#include <sstream>
#include <iostream>

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Utility function to check if a character is alphanumeric
bool isAlnum(char c) {
    return isalnum(c) || c == '.';
}

std::string infixToPostfix(std::string infix) {
    GenericStack<char> opStack;
    std::ostringstream out;

    for (char c : infix) {
        if (c == ' ') continue;  // skip spaces

        if (isAlnum(c)) {
            out << c;
        }
        else if (c == '(') {
            opStack.push(c);
            out << ' ';
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                out << ' ' << opStack.top();
                opStack.pop();
            }
            // Pop '(' from the stack
            if (!opStack.empty()) opStack.pop();
        }
        else { // an operator is encountered
            out << ' ';
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                out << opStack.top() << ' ';
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!opStack.empty()) {
        out << ' ' << opStack.top();
        opStack.pop();
    }

    return out.str();





}

float evaluatePostfix(std::string postfix) {
    GenericStack<float> operandStack;
    std::istringstream in(postfix);
    std::string token;

    while (in >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop two operands from the stack
            float op2 = operandStack.top(); operandStack.pop();
            float op1 = operandStack.top(); operandStack.pop();
            // Perform the operation and push the result back to the stack
            if (token == "+") operandStack.push(op1 + op2);
            else if (token == "-") operandStack.push(op1 - op2);
            else if (token == "*") operandStack.push(op1 * op2);
            else operandStack.push(op1 / op2);
        }
        else {
            // Push the operand (convert from string to float) to the stack
            operandStack.push(std::stof(token));
        }
    }

    // The final result is on the top of the stack
    return operandStack.top();
}

int main() {
    std::string infixExpression;
    while (true) {
        std::cout << "Enter an infix arithmetic expression (or 'exit' to stop):" << std::endl;
        std::getline(std::cin, infixExpression);

        // If the user enters 'exit', break from the loop
        if (infixExpression == "exit") {
            break;
        }

        std::string postfixExpression = infixToPostfix(infixExpression);
        std::cout << "Postfix expression: " << postfixExpression << std::endl;

        // Check if the postfix expression contains only numeric operands
        bool containsOnlyNumericOperands = true;
        for (char c : postfixExpression) {
            if (isalpha(c)) {
                containsOnlyNumericOperands = false;
                break;
            }
        }

        if (containsOnlyNumericOperands) {
            float result = evaluatePostfix(postfixExpression);
            std::cout << "Result: " << result << "\n" << std::endl;
        }
        else {
            std::cout << "Cannot evaluate the expression as it contains non-numeric operands." << "\n" << std::endl;
        }
    }

    return 0;
}


