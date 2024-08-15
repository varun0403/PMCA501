/* AREAS OF IMPROVEMENT
1) Need to handle the paranthesis
			current: assumes only one operator 
			modify: loop decremently to pop all the operators
2) Check stack is empty or not before performing certain operations
*/

#include<iostream>
#include<string>
using namespace std;

const int size = 100;
int stack[size];
int top = -1;

bool isFull() {
    if (top == size - 1) {
        return true;
    } 
    else {
        return false;
    }
}

bool isEmpty() {
    if (top == -1) {
        return true;
    } 
    else {
        return false;
    }
}

int push(int val) {
    if (isFull()) {
        cout << "Stack is full!" << endl;
    } 
    else {
        top++;
        stack[top] = val;
    }
    return 0;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack empty!" << endl;
    } 
    else {
        top--;
    }
    return 0;
}

int peek() {
    if (isEmpty()) {
        cout << "Stack empty!" << endl;
    }
    return stack[top];
}

int priority(char a) {
    if ((a == '+') || (a == '-')) {
        return 1;
    }

    if ((a == '*') || (a == '/')) {
        return 2;
    }

    if (a == '^') {
        return 3;
    }
    return 0;
}

string convert(string infix) {
    int i, temp;
    string postfix = "";

    for (i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (priority(c) > 0) {
            if (isEmpty()) {
                push(c);
            } 
	    else {
                temp = peek();
                if (priority(temp) >= priority(c)) {
                    postfix += temp;
                    pop();
                    push(c);
                } 
		else if (priority(temp) < priority(c)) {
                    push(c);
                }
            }
        } 
	else if (c == '(') {
            push(c);
        } 
	else if (c == ')') {
            temp = peek();
            postfix += temp;
            pop();
            pop();
        } 
	else {
            postfix += c;
        }
    }
    while (!isEmpty()) {
        postfix += stack[top];
        pop();
    }
    return postfix;
}

int main() {
    string exp = "A+(B-C)-(D/F)";
    string postfix = convert(exp);
    cout << postfix << endl;
    return 0;
}
