#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;

void insert(int val){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = val;
	new_node->next = NULL;
	if(head == NULL){
		head = new_node;
	}
	else{
		if(head->next == NULL){
			head->next = new_node;
		}
		else{
			struct node *current = head;
			while(current->next != NULL){
				current = current->next;
			}
			current->next = new_node;
		}
	}
}

void traverse(){
	if(head == NULL){
		cout<<"No nodes in linked list!"<<endl;;
	}
	else{
		if(head->next == NULL){
			cout<<head->data<<endl;
		}
		else{
			struct node *current = head;
			while(current != NULL){
				cout<<current->data<<" ";
				current = current->next;
			}
		}
	}
}

void bubble_sort(){
	int temp;
	struct node *outer = head;
	while(outer->next != NULL){
		struct node *inner = head;
		while(inner->next != NULL){
			if(inner->data > inner->next->data){
				temp = inner->data;
				inner->data = inner->next->data;
				inner->next->data = temp;
			}
			inner = inner->next;
		}
		outer = outer->next;
	}
}

void insertion_sort(){
	int temp;
	struct node *outer = head;
	while(outer != NULL){
		struct node *min_node = outer;
		struct node *inner = outer->next;
		while(inner != NULL){
			if(inner->data < min_node->data){
				min_node = inner;
			}
			inner = inner->next;
		}
		if(min_node->data != outer->data){
			temp = outer->data;
			outer->data = min_node->data;
			min_node->data = temp;
		}
		outer = outer->next;
	}
}

int main(){
	insert(5);
	insert(4);
	insert(1);
	insert(2);
	insert(3);
	insertion_sort();
	traverse();
	return 0;
}
