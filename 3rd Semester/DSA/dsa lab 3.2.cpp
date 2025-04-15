#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    else if (C == '$')
        return 4;
    return 0;
}

string infixToPrefix(const string& infix) {
    string modifiedInfix = '(' + infix + ')';
    reverse(modifiedInfix.begin(), modifiedInfix.end());
    int length = modifiedInfix.size();
    stack<char> charStack;
    string prefix;

    for (int i = 0; i < length; i++) {
        if (isalpha(modifiedInfix[i]) || isdigit(modifiedInfix[i]))
            prefix += modifiedInfix[i];
        else if (modifiedInfix[i] == ')')
            charStack.push(')');
        else if (modifiedInfix[i] == '(') {
            while (charStack.top() != ')') {
                prefix += charStack.top();
                charStack.pop();
            }
            charStack.pop();
        } else {
            if (isOperator(charStack.top())) { 
                if (modifiedInfix[i] == '^') {
                    while (getPriority(modifiedInfix[i]) <= getPriority(charStack.top())) {
                        prefix += charStack.top();
                        charStack.pop();
                    }
                } else {
                    while (getPriority(modifiedInfix[i]) < getPriority(charStack.top())) {
                        prefix += charStack.top();
                        charStack.pop();
                    }
                }
                charStack.push(modifiedInfix[i]);
            }
        }
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infixExpression;
    cout << "Enter the infix expression: ";
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
