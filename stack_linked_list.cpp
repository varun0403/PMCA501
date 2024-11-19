#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *createNode(int val){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}

void push(struct node *&root,int val){
	if(root == NULL){
		root = createNode(val);
	}
	else{
		struct node *temp = root;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = createNode(val);
	}
}

void pop(struct node *&root){
	if(root == NULL){
		cout << "Empty stack!" << endl;
	}
	else{
		struct node *temp = root;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		temp->next = NULL;
	}
}

void peek(struct node *root){
	if(root == NULL){
		cout << "Empty stack!" << endl;
	}
	else{
		struct node *temp = root;
		while(temp->next != NULL){
			temp = temp->next;
		}
		cout << "STACK[TOP] : " << temp->data << endl;
	}
}

int main(){
	struct node *stack = NULL;
	push(stack,12);
	push(stack,16);
	push(stack,17);
	push(stack,18);
	peek(stack);
	pop(stack);
	peek(stack);
	return 0;
}
