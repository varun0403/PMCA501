#include<iostream>
#include<malloc.h>
using namespace std;
const int size = 5;

struct node{
	int val;
	struct node* next;
};

struct node* head = NULL;
struct node* top = NULL;
int count = 0;


bool isFull(){
	return size == count;
}

bool isEmpty(){
	return count == 0;
}

void push(int data){
	if(isFull()){
		cout<<"Stack full!"<<endl;
	}
	else{
		struct node* new_node = (struct node*)malloc(sizeof(struct node));
		new_node->next = NULL;
		new_node->val = data;
		if(isEmpty()){
			head = new_node;
			top = new_node;
			count++;
		}
		else{
			struct node* current = head;
		        while (current->next != NULL) {
		        	current = current->next;
		        }
		        current->next = new_node;
		        top = new_node;
		        count++;
		}
	}
}

void pop() {
    if (!isEmpty()){
        if (head->next == NULL){
            free(head);
            head = NULL;
            count--;
        } 
	else{
            struct node* current = head;
            while (current->next->next != NULL){
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
            top = current;
            count--;
        }
    } 
    else {
        cout<<"Stack is empty!"<<endl;
    }
}

int peek(){
	if(isEmpty()){
		return 0;
	}
	return top->val;
}

void display(){
	if(head == NULL){
		cout<<"Empty!";
	}
	else{
		struct node* current = head;
		while(current->next != NULL){
			cout<<current->val<<" -> ";
			current = current->next;
		}
		cout<<current->val;
	}
}

int main(){
	cout<<"1)Push 2)Pop 3)Peek 4)Display 5)Exit"<<endl;
	int inp,temp,data;
	while(true){
		cout<<"\nEnter your choice: ";
		cin>>inp;
		switch(inp){
			case 1:
				cout<<"Enter value: ";
				cin>>data;
				push(data);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				temp = peek();
				if(temp == 0){
					cout<<"Empty list!"<<endl;
				}
				else{
					cout<<temp<<endl;
				}
				break;
				
			case 4:
				display();
				break;
			
			case 5:
				return 0;
				break;
				
			default:
				cout<<"Retry"<<endl;
		}
	}
	return 0;
}


