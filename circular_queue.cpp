#include<iostream>
using namespace std;
const int size = 3;
int arr[size];
int front = -1;
int rear = -1;

bool isFull(){
	if (((rear+1)%size) == front){
		return true;
	}
	return false;
}

bool isEmpty(){
	if (front == -1){
		return true;
	}
	return false;
}

int enqueue(int val){
	if (isFull()){
		cout<<"Queue is full!"<<endl;
		return -1;
	}
	if(isEmpty()){
		front++;
		rear++;
		arr[rear] = val;
	}
	else{
		rear = (rear+1)%size;
		arr[rear] = val;
	}
}

int dequeue(){
	if(isEmpty()){
		cout<<"Queue empty!"<<endl;
		return -1;
	}
	if (front == rear){
		front = -1;
		rear = -1;
	}
	else{
		front = (front+1)%size;
	}
}

int peek(){
	if (front == -1){
		cout<<"No items available!"<<endl;
	}
	else{
		return arr[front];
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

