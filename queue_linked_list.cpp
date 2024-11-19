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

void enqueue(struct node *&root,int val){
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

void dequeue(struct node *&root){
	if(root == NULL){
		cout << "Empty queue!" << endl;
	}
	else{
		root = root->next;
	}
}

void peek(struct node *root){
	if(root == NULL){
		cout << "Empty queue!" << endl;
	}
	else{
		cout << "QUEUE[FRONT] : " << root->data;
	}
}

int main(){
	struct node *q = NULL;
	enqueue(q,12);
	enqueue(q,15);
	enqueue(q,16);
	enqueue(q,19);
	peek(q);
	dequeue(q);
	peek(q);
	return 0;
}
