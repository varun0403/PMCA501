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
                return a/b
            }
  			    return b/a;
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
  	string postfix;
  	int temp;
  	cout<<"Enter postfix expression: ";
  	cin>>postfix;
  	temp = getResult(postfix);
  	cout<<temp;
  	return 0;
}
