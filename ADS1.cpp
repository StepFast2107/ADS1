// ADS1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool areSymbolsBalanced(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        switch (ch) {
        case '(':
        case '[':
        case '{':
            s.push(ch);
            break;
        case ')':
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{')
                return false;
            s.pop();
            break;
        }
    }
    return s.empty();  // If stack is empty, symbols are balanced
}

int main() {
    string expr;
    cout << "Enter an expression: ";  // User prompt
    getline(cin, expr);  // Read a line from cin to expr

    if (areSymbolsBalanced(expr))
        cout << "Balanced.\n";
    else
        cout << "Not balanced.\n";

    return 0;
}


