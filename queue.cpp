#include<iostream>
using namespace std;

const int size = 5;
int arr[size];
int front = -1, rear = -1;

bool isFull(){
	if(rear == size-1){
		return true;
	}
	return false;
}

bool isEmpty(){
	if(front == -1){
		return true;
	}
	return false;
}

void enqueue(int val){
	if(isFull()){
		cout<<"Queue is full!"<<endl;
	}
	else{
		if(isEmpty()){
			front++;
			rear++;
			arr[rear] = val;
		}
		else{
			rear++;
			arr[rear] = val;
		}
	}
}

void dequeue(){
	if(isEmpty()){
		cout<<"Queue is empty!"<<endl;
	}
	else{
		if(front == rear){
			front = -1;
			rear = -1;
		}
		else{
			front++;
		}
	}
}

void display(){
	if(!isEmpty()){
		for(int i=front; i<=rear; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return;
	}
	cout<<"Queue is empty!"<<endl;
}

int main(){
	int data,ch;
	cout<<"1) Enqueue 2) Dequeue 3) Display 4) Exit"<<endl;
	while(true){
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"\nEnter insert value: ";
				cin>>data;
				enqueue(data);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				return -1;
			default:
				cout<<"\nIncorrect option!"<<endl;
		}
	}
}
