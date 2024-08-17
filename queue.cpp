#include<iostream>
using namespace std;

const int size=5;
int queue[size];
int front = -1;
int rear = -1;

bool isFull(){
	if(rear == size-1){
		return true;
	}
	return false;
}

bool isEmpty(){
	if(rear == -1){
		return true;
	}
	return false;
}

int enqueue(int val){
	if((front == -1) && (rear == -1)){
		front++;
		rear++;
		queue[front] = val;
	}
	else{
		if(isFull()){
			cout<<"Queue full!"<<endl;
		}
		else{
			rear++;
			queue[rear] = val;
		}
	}
	return 0;
}

int dequeue(){
	if(isEmpty() || front>rear){
		cout<<"Queue empty!"<<endl;
	}
	else{
		front++;
	}
	return 0;
}

int peek(){
	if(!isEmpty()){
		return queue[front];
	}
	else{
		cout<<"Empty queue!"<<endl;
	}
}

int main(){
	int c,val;
	cout<<"1)Push 2)Pop 3)Peek 4)Exit"<<endl;
	while(true){
		cout<<"Enter your choice: ";
		cin>>c;
		switch(c){
			case 1:
				cout<<"\nEnter a value: ";
				cin>>val;
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				val = peek();
				cout<<val<<endl;
				break;
			case 4:
				return 0;
		}
	}
}
