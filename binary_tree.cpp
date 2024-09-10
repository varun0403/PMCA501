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

void insert_recursive(struct node* temp,int val){
	if(root == NULL){
		struct node* new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = val;
		new_node->left = NULL;
		new_node->right = NULL;
		root = new_node;
		return;
	}
	if(temp->data > val){
		if(temp->left == NULL){
			struct node* new_node = (struct node*)malloc(sizeof(struct node));
			new_node->data = val;
			new_node->left = NULL;
			new_node->right = NULL;
			temp->left = new_node;
		}
		else{
			temp = temp->left;
			insert_recursive(temp,val);
		}
	}
	else{
		if(temp->right == NULL){
			struct node* new_node = (struct node*)malloc(sizeof(struct node));
			new_node->data = val;
			new_node->left = NULL;
			new_node->right = NULL;
			temp->right = new_node;
		}
		else{
			temp = temp->right;
			insert_recursive(temp,val);
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
	cout<<"\n";
}

void search(struct node *temp, int val){
	if(temp == NULL){
		cout<<"Empty tree!"<<endl;
		return;
	}
	if(temp->data == val){
		cout<<"Element present in the tree"<<endl;
		return;
	}
	else{
		if(temp->data < val){
			search(temp->right,val);
		}
		else{
			search(temp->left,val);
		}
	}
}

int main(){
	insert_recursive(root,17);
	insert_recursive(root,19);
	insert_recursive(root,8);
	insert_recursive(root,9);
	insert_recursive(root,3);
	insert_recursive(root,5);
	insert_recursive(root,11);
	cout<<"Breadth First Search: ";
	bfs();
	cout<<"\nDepth First Search  : ";
	dfs();
	cout<<"\nLeaf Nodes: ";
	leaf_nodes();
	search(root,115);
	return 0;
}
