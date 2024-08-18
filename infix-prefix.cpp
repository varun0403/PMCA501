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

string reverse(string str){
    string temp = "";
    int i;
    for(i = str.length() ; i >= 0 ; i--){
        temp += str[i];
    }
    return temp;
}

string replace(string str){
    int i;
    for(i = 0 ; i <= str.length() ; i++){
        if (str[i] == '('){
            str[i] = ')';
        }
        else if (str[i] == ')'){
            str[i] = '(';
        }
    }
    return str;
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
    string prefix = "";

    for (i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (priority(c) > 0) {
            if (isEmpty()) {
                push(c);
            } 
	    else {
                temp = peek();
                if (priority(temp) >= priority(c)) {
                    prefix += temp;
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
            prefix += temp;
            pop();
            pop();
        } 
	else {
            prefix += c;
        }
    }
    while (!isEmpty()) {
        prefix += stack[top];
        pop();
    }
    return reverse(prefix);
}

int main() {
    string exp = "A*B+C";
    string rev_exp = reverse(exp);
    rev_exp = replace(rev_exp);
    string prefix = convert(rev_exp);
    cout << prefix ;
    return 0;
}
