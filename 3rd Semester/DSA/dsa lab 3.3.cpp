#include<iostream>
#include<string>
using namespace std;

const int MAX_SIZE = 20;
int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            int operand = c - '0';
            push(operand);
        }
        else {
            int operand2 = pop();
            int operand1 = pop();
            int result;

            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(result);
        }
    }

    return pop();
}

int main() {
    string postfix;
    cout << "Enter the postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}

