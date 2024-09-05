#include<iostream>
#include<malloc.h>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void insert(int val){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;
	if(root == NULL){
		root = new_node;
		return;
	}
	struct node *temp = root;
	while(temp != NULL){
		if(val < temp->data){
			if(temp->left == NULL){
				temp->left = new_node;
				return;
			}
			else{
				temp = temp->left;
			}
		}
		else{
			if(temp->right == NULL){
				temp->right = new_node;
				return;
			}
			else{
				temp = temp->right;
			}
		}
	}
}

void del(int val){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;
	if(root == NULL){
		root = new_node;
		return;
	}
	struct node *temp = root;
	while(temp->data != val){
		if(val < temp->data){
			temp = temp->left
		}
		else{
			temp = temp->right;
		}
	}
	
	
}

void bfs(){
	queue<node*>q;
	struct node *temp;
	vector<int>arr;
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		if(temp->left != NULL){
			q.push(temp->left);
		}
		if(temp->right != NULL){
			q.push(temp->right);
		}
		arr.push_back(temp->data);
		q.pop();
	}
	for(int i=0; i<arr.size(); i++){
		cout<<arr[i]<<" ";
	}
}

void dfs(){
	stack<node*>s;
	struct node *temp;
	vector<int>arr;
	s.push(root);
	while(!s.empty()){
		temp = s.top();
		s.pop();
		if(temp->right != NULL){
			s.push(temp->right);
		}
		if(temp->left != NULL){
			s.push(temp->left);
		}
		arr.push_back(temp->data);
	}
	for(int i=0; i<arr.size(); i++){
		cout<<arr[i]<<" ";
	}
}

void leaf_nodes(){
	queue<node*>q;
	struct node *temp;
	vector<int>arr;
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		if(temp->left == NULL && temp->right == NULL){
			arr.push_back(temp->data);
		}
		else{
			if(temp->left != NULL){
			q.push(temp->left);
			}
			if(temp->right != NULL){
				q.push(temp->right);
			}
		}
		q.pop();
	}
	for(int i=0; i<arr.size(); i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	insert(7);
	insert(4);
	insert(9);
	insert(3);
	insert(6);
	insert(5);
	insert(11);
	cout<<"Breadth First Search: ";
	bfs();
	cout<<"\nDepth First Search  : ";
	dfs();
	cout<<"\nLeaf Nodes: ";
	leaf_nodes();
	return 0;
}
