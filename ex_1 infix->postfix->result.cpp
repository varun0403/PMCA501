#include<iostream>
#include<stack>
#include<string>

using namespace std;

int priority(char a){
	if(a == '^'){
		return 3;
	}
	else if((a == '*') || (a == '/')){
		return 2;
	}
	else if((a == '+') || (a == '-')){
		return 1;
	}
	else{
		return 0;
	}
}


string convert(string infix){
	stack<char>s;
	int i,temp;
	string postfix = "";
	
	for(i=0;i<infix.length();i++){
		char c = infix[i];
		if(priority(c) > 0){
			if(s.empty()){
				s.push(c);
			}
			else{
				temp = s.top();
				if(priority(temp) >= priority(c)){
					postfix += temp;
					s.pop();
					s.push(c);
				}
				else if(priority(temp) < priority(c)){
					s.push(c);
				}
			}
		}
		else 
		{
		if(c == '('){
			s.push(c);
		}
		else if(c == ')'){
			temp = s.top();
			postfix += temp;
			s.pop();
			s.pop();
		}
		else{
			postfix += c;
		}
	}
	}
	
	while(!s.empty()){
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

int arith(int a, int b, char c){
	switch(c){
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			if(a>b){
				return a/b;
			}
			else{
				return b/a;
			}
			break;
		case '^':
			return a^b;
			break;
		default:
			return -1;
	}
}

int getResult(string postfix){
	stack<int>s;
	int i,n1,n2,res;
	char ch;
	for(i=0;i<postfix.length();i++){
		ch = postfix[i];
		if(priority(ch) == 0){
			s.push(ch - '0');
		}
		else{
			n2 = s.top();
			s.pop();
			n1 = s.top();
			s.pop();
			res = arith(n2,n1,ch);
			s.push(res);
		}
	}
	return s.top();
}



int main(){
	string infix;
	int temp;
	cout<<"Enter expression: ";
	cin>>infix;
	string postfix = convert(infix);
	temp = getResult(postfix);
	cout<<"Postfix: "<<postfix<<endl;
	cout<<temp;
	return 0;
}
