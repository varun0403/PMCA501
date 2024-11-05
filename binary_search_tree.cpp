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

vector<int> bfs(struct node *topNode) {
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
    return arr;
}

vector<int> dfs(struct node *topNode) {
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
    return arr;
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

void search(struct node *temp, int val) {
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

struct node *find(struct node *temp, int val){
	if(temp->data == val){
    	return temp;
	}
	else{
		if(temp->data > val){
			if(temp->left == NULL){
				return NULL;
			}
			else{
				find(temp->left,val);
			}
		}
		else{
			if(temp->right == NULL){
				return NULL;
			}
			else{
				find(temp->right,val);
			}
		}
	}
}

bool completeTree(struct node *temp){
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

bool fullTree(struct node *temp){
	queue<node*>q;
	struct node *current;
	q.push(temp);
	while(!q.empty()){
		current = q.front();
		q.pop();
		if((current->left != NULL && current->right == NULL) || (current->left == NULL && current->right != NULL)){
			return false;
		}
		if (current->left != NULL) {
	            q.push(current->left);
	        }
	        if (current->right != NULL) {
	            q.push(current->right);
	        }
	}
	return true;
}

void mirror(struct node *&temp){
	queue<node*>q;
	struct node *current;
	q.push(temp);
	while(!q.empty()){
		current = q.front();
		q.pop();
		swap(current->left,current->right);
		if(current->left != NULL) {
	            q.push(current->left);
	        }
	        if(current->right != NULL) {
	            q.push(current->right);
	        }
	}
}

int min(struct node *root){
	struct node *temp = root;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp->data;
}

int max(struct node *root){
	struct node *temp = root;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp->data;
}

vector<int>path(struct node *root,int start,int end){
	vector<int>arr;
	struct node *start_node = find(root,start);
	if(start_node != NULL){
		struct node *p1 = start_node;
		while(p1!=NULL){
			if(p1->data == end){
				arr.push_back(p1->data);
				return arr;
			}
			else{
				if(p1->data > end){
					if(p1->left == NULL){
						cout << "Destination does not exist!" << endl;
						return arr;
					}
					else{
						arr.push_back(p1->data);
						p1 = p1->left;
					}
				}
				else{
					if(p1->data < end){
						if(p1->right == NULL){
							cout << "Destination does not exist!" << endl;
							return arr;
						}
						else{
							arr.push_back(p1->data);
							p1 = p1->right;
						}
					}
				}
			}
		}
	}
	else{
		cout << "Couldn't find source!" << endl;
	}
}

void traverse(vector<int>&arr,int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	struct node *root = NULL;
    insert(root, 10);
    insert(root, 12);
    insert(root, 6);
    insert(root, 7);
    insert(root, 5);
    insert(root, 13);
    insert(root, 8);
    vector<int>arr1 = path(root,8,8);
    traverse(arr1,arr1.size());
    return 0;
}
