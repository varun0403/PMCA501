#include<iostream>
#include<malloc.h>
#include<queue>
#include<stack>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createNode(int val){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void append(struct node *&root, int val){
	if(root == NULL){
		root = createNode(val);
		return;
	}
	if(root->data < val){
		if(root->right == NULL){
			root->right = createNode(val);
			return;
		}
		append(root->right,val);
	}
	else{
		if(root->left == NULL){
			root->left = createNode(val);
			return;
		}
		append(root->left,val);
	}
}

void del(struct node *&temp,int val){
	if(temp->data == val){
		if(temp->left == NULL && temp->right == NULL){
			temp = NULL;
			return;
		}
		else if(temp->left != NULL && temp->right == NULL){ 
			swap(temp->data,temp->left->data);
			temp->left = NULL;
			return;
		}
		else if(temp->left == NULL && temp->right != NULL){
			swap(temp->data,temp->right->data);
			temp->right = NULL;
			return;
		}
		else{
			struct node *current = temp->right;
			if(current->left == NULL){
				swap(current->data,temp->data);
				temp->right = NULL;
				return;
			}
			while(current->left->left != NULL){
				current = current->left;
			}
			swap(current->left->data,temp->data);
			current->left = NULL;
			return;
		}
	}
	else{
		if(temp->data > val){
			del(temp->left,val);
		}
		else{
			del(temp->right,val);
		}
	}
}

void invert(struct node *&root){
	struct node *temp = NULL;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		swap(temp->left,temp->right);
		if(temp->left != NULL){
			q.push(temp->left);
		}
		if(temp->right != NULL){
			q.push(temp->right);
		}
	}
}

int maxDepth(struct node *root) {
	if (root == NULL) {
        return 0;
    }
    int lDepth = maxDepth(root->left);
    int rDepth = maxDepth(root->right);

    return max(lDepth, rDepth) + 1;
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

void traverse_dfs(struct node *topnode){
	stack<node*>s;
	s.push(topnode);
	struct node *temp = NULL;
	while(!s.empty()){
		temp = s.top();
		cout << temp->data << " ";
		s.pop();
		if(temp->right != NULL){
			s.push(temp->right);
		}
		if(temp->left != NULL){
			s.push(temp->left);
		}
	}
	cout << endl;
}

void inorder_traverse(struct node *temp){
	if (temp == NULL) {
		return;
	}
    inorder_traverse(temp->left);
    cout << temp->data << " ";
    inorder_traverse(temp->right);
}

void preorder_traverse(struct node *temp){
	if (temp == NULL){
		return;
	}
    cout << temp->data << " ";
    preorder_traverse(temp->left);
    preorder_traverse(temp->right);
}

void postorder_traverse(struct node *temp){
	if (temp == NULL){
		return;
	}
    postorder_traverse(temp->left);
    postorder_traverse(temp->right);
    cout << temp->data << " ";
}

int main(){
	struct node *root1 = NULL;
	append(root1,10);
	append(root1,15);
	append(root1,5);
	append(root1,3);
	append(root1,7);
	append(root1,12);
	append(root1,18);
	append(root1,19);
	postorder_traverse(root1);
	return 0;
}
