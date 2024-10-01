#include <iostream>
#include <malloc.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *createNode(int val) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(struct node* &temp, int val) {
    if (temp == NULL) {
        temp = createNode(val);
        return;
    }
    if (temp->data > val) {
        if (temp->left == NULL) {
            temp->left = createNode(val);
        } 
		else {
            insert(temp->left, val);
        }
    } 
	else {
        if (temp->right == NULL) {
            temp->right = createNode(val);
        } 
		else {
            insert(temp->right, val);
        }
    }
}

void del(struct node *&temp, int val){ 
	if(temp->data == val){
		if(temp->left == NULL && temp->right == NULL){ //zero children
			free(temp);
			temp = NULL;
			return;
		}
		else if(temp->left != NULL && temp->right == NULL){ //only one child: left child
			swap(temp->data,temp->left->data);
			temp->left = NULL;
			return;
		}
		else if(temp->left == NULL && temp->right != NULL){ //only one child: right child
			swap(temp->data,temp->right->data);
			temp->right = NULL;
			return;
		}
		else{ //two children
			struct node *current = temp->right;
			if(current->left == NULL){
				swap(current->data,temp->data);
				temp->right = NULL;
				return;
			}
			while(current->left->left != NULL){
				current = current->left;
			}
			swap(temp->data,current->left->data);
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

void bfs(struct node *topNode) {
    queue<node*> q;
    struct node* temp;
    vector<int> arr;
    q.push(topNode);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        arr.push_back(temp->data);
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

void dfs(struct node *topNode) {
    stack<node*> s;
    struct node* temp;
    vector<int> arr;
    s.push(topNode);
    while (!s.empty()) {
        temp = s.top();
        s.pop();
        arr.push_back(temp->data);
        if (temp->right != NULL) {
            s.push(temp->right);
        }
        if (temp->left != NULL) {
            s.push(temp->left);
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

void leaf_nodes(struct node *topNode) {
    queue<node*> q;
    struct node* temp;
    vector<int> arr;
    q.push(topNode);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->left == NULL && temp->right == NULL) {
            arr.push_back(temp->data);
        } else {
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void search(struct node* temp, int val) {
    if(temp->data == val){
    	cout << "Element present!" << endl;
    	return;
	}
	else{
		if(temp->data > val){
			if(temp->left == NULL){
				cout << "Element not available!" << endl;
			}
			else{
				search(temp->left,val);
			}
		}
		else{
			if(temp->right == NULL){
				cout << "Element not available!" << endl;
			}
			else{
				search(temp->right,val);
			}
		}
	}
}

bool completeTree(struct node *&temp){
	queue<node*>q;
	struct node *current;
	q.push(temp);
	while(q.front() != NULL){
		current = q.front();
		q.pop();
		q.push(current->left);
		q.push(current->right);
	}
	while(!q.empty()){
		if(q.front() != NULL){
			return false;
		}
		q.pop();
	}
	return true;
}

int height(struct node *root) {
    if (root == NULL) {
        return 0; 
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int main() {
	struct node *root = NULL;
    insert(root, 50);
    insert(root, 75);
    insert(root, 25);
    insert(root, 35);
    insert(root, 20);
    insert(root, 15);
    cout << "Breadth First Search: ";
    bfs(root);
    bool status = completeTree(root);
    cout << "Is the tree complete: " << status;
    return 0;
}
