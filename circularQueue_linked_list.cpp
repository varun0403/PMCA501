#include <iostream>
#include <malloc.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;
int count = 0, size = 5;

bool isFull(){
    return count == size;
}

bool isEmpty(){
    return count == 0;
}

void push(int val) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
    } 
    else {
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = val;
        new_node->next = NULL;
        
        if (isEmpty()) {
            front = new_node;
            rear = new_node;
            front->next = rear;
            rear->next = front;
        } 
        else {
            new_node->next = front;  
            rear->next = new_node;  
            rear = new_node;         
        }
        
        count++;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"No elements in the circular queue"<<endl;
    }
    else{
        if(count == 1){
            front = NULL;
            rear = NULL;
            free(front);
            free(rear);
        }
        else{
            front = front->next;
            rear->next = front;
        }
        count--;
    }
}

void traverse(){
    if(count == 0){
        cout<<"Queue is empty!"<<endl;
    }
    else{
    struct node* current = front;
    while(current->next != front){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<current->data<<endl;
    }
}

int main(){
    cout<<"1)Push 2)Pop 3)Traverse"<<endl;
    int c,val;
    while(true){
        cout<<"Enter choice: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter val: ";
                cin>>val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}
