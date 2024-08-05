#include<iostream>
using namespace std;
const int size=5;
int stack[size];
int top=-1;

bool isFull(){
	if (top == size-1){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(){
	if(top == -1){
		return true;
	}
	else{
		return false;
	}
}

int push(int val){
	if(isFull()){
		cout<<"Stack is full!"<<endl;
	}
	else{
		top++;
		stack[top] = val;
	}
	return 0;
}

int pop(){
	if(isEmpty()){
		cout<<"Stack empty!"<<endl;
	}
	else{
		top--;
	}
	return 0;
}

int peek(){
	if(isEmpty()){
		cout<<"Stack empty!"<<endl;
	}
	return stack[top];
}

int main(){
	cout<<"1)Push | 2)Pop | 3)Peek | 4) Exit"<<endl;
	int ch,val,t;
	while(true){
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch){
			case 1:
				cout << "Enter value to push: ";
                cin >> val;
                push(val);
                break;
            
            case 2:
            	pop();
            	break;
            
            case 3:
            	t = peek();
            	cout<<t<<endl;
            	break;
            
            case 4:
            	return 0;
    	}
	}
	return 0;
}

