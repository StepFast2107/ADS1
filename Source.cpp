#include <iostream>
#include "GenericStack.h"

int main() {
    std::string infix = "2 * (3 + 4) - 5 / 6";
    std::string postfix = infixToPostfix(infix);
    float result = evaluatePostfix(postfix);

    std::cout << "Infix expression: " << infix << std::endl;
    std::cout << "Postfix expression: " << postfix << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
