#include<iostream>
#include<queue>
#include<malloc.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

struct node *createNode(int val){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;
}

void insert(struct node *&root,int val){
	if(root == NULL){
		root = createNode(val);
		return;
	}
	queue<node*>q;
	q.push(root);
	struct node *temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp->left == NULL){
			temp->left = createNode(val);
			return;
		}
		else{
			q.push(temp->left);
		}
		if(temp->right == NULL){
			temp->right = createNode(val);
			return;
		}
		else{
			q.push(temp->right);
		}
	}
}

void traverse_bfs(struct node *topnode){
	queue<node*>q;
	q.push(topnode);
	struct node *temp = NULL;
	while(!q.empty()){
		temp = q.front();
		cout << temp->data << " ";
		q.pop();
		if(temp->left != NULL){
			q.push(temp->left);
		}
		if(temp->right != NULL){
			q.push(temp->right);
		}
	}
	cout << endl;
}

int main(){
	struct node *root1 = NULL;
	insert(root1,1);
	insert(root1,2);
	insert(root1,31);
	insert(root1,4);
	insert(root1,5);
	insert(root1,6);
	traverse_bfs(root1);
	return 0;
}
