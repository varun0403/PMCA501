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

struct node* root = NULL;

struct node* createNode(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_iter(int val) {
    struct node* new_node = createNode(val);
    if (root == NULL) {
        root = new_node;
        return;
    }
    struct node* current = root;
    while (true) {
        if (val < current->data) {
            if (current->left == NULL) {
                current->left = new_node;
                return;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = new_node;
                return;
            }
            current = current->right;
        }
    }
}

void insert(struct node* temp, int val) {
    if (root == NULL) {
        root = createNode(val);
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

void del(struct node *&temp, int val){ //need to write code to del leaf nodes
	if(temp->data == val){
		if(temp->left != NULL && temp->right == NULL){
			free(temp);
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
				cout << "---"<<current->data<<"------"<<temp->data;
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

void bfs() {
    queue<node*> q;
    struct node* temp;
    vector<int> arr;
    q.push(root);
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

void dfs() {
    stack<node*> s;
    struct node* temp;
    vector<int> arr;
    s.push(root);
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

void leaf_nodes() {
    queue<node*> q;
    struct node* temp;
    vector<int> arr;
    q.push(root);
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

int main() {
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 17);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 9);
    insert(root, 11);
    insert(root, 13);
    insert(root, 16);
    insert(root, 18);
    insert(root, 1);
    cout << "Breadth First Search: ";
    bfs();
    del(root,5);
    cout << "\nBreadth First Search: ";
    bfs();
    return 0;
}
