#include <iostream>
using namespace std;
const int size = 5;

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;
int count = 0;

bool isEmpty(){
    return count == 0;
}

bool isFull(){
    return count == size;
}

void push(int val){
    if(isFull()){
        cout<<"Queue is full!"<<endl; 
    }
    else{
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = val;
        new_node->next = NULL;
        if (isEmpty()){
            front = new_node;
            rear = new_node;
        }
        else{
            if(front == rear){
                rear = new_node;
                front->next = rear;
            }
            else{
                struct node* current = front;
                while(current->next != NULL){
                    current = current->next;
                }
                current->next = new_node;
            }
        }
        count++;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Empty list!";
    }
    else{
        if(front == rear){
            front = NULL;
            rear = NULL;
	    free(front);
            free(rear);
        }
        else{
            front = front->next;
        }
        count--;
    }
}

int peek(){
    int d = front->data;
    return d;
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
			
			case 5:
				return 0;
				break;
				
			default:
				cout<<"Retry"<<endl;
		}
	}
	return 0;
}
