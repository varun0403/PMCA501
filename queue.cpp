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
	if(isFull()){
		cout<<"Queue is full!"<<endl;
	}
	else{
	    	cout<<"The inserted value is "<<val<<endl;
		if((front == -1) && (rear == -1)){
		    	front++;
		    	rear++;
		    	queue[front] = val;
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
	    	cout<<"Dequed value is "<<queue[front]<<endl;
	    	front++;
	}
	return 0;
}

void display(){
	int i;
	for (i=front;i<=rear;i++){
	    cout<<queue[i]<<"\t";
	}
}

int main(){
	int c,val;
	cout<<"1)Push 2)Pop 3)Display 4)Exit"<<endl;
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
				display();
				break;
			case 4:
				return 0;
		}
	}
}
