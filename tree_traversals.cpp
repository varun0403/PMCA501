#include<iostream>
#include<malloc.h>
#include<stack>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;
struct node *temp = root;

void insert(int val){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;
	if(root == NULL){
		root = new_node;
		return;
	}
	struct node *current = root;
	while(current != NULL){
		if(val < current->data){
			if(current->left == NULL){
				current->left = new_node;
				return;
			}
			else{
				current = current->left;
			}
		}
		else{
			if(current->right == NULL){
				current->right = new_node;
				return;
			}
			else{
				current = current->right;
			}
		}
	}
}

void preorder(struct node *temp){
	cout<<temp->data<<" ";
	if(temp->left != NULL){
		preorder(temp->left);
	}
	if(temp->right != NULL){
		preorder(temp->right);
	}
}

void inorder(struct node *temp){
	if(temp->left != NULL){
		inorder(temp->left);
	}
	cout<<temp->data<<" ";
	if(temp->right != NULL){
		inorder(temp->right);
	}
}
void postorder(struct node *temp){
    if(temp->left != NULL){
        postorder(temp->left);
    }
    if(temp->right != NULL){
        postorder(temp->right);
    }
    cout<<temp->data<<" "; 
}

int main(){
	insert(12);
	insert(15);
	insert(8);
	insert(9);
	insert(4);
	insert(16);
	insert(14);
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	return 0;
}

