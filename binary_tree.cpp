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

void insert(struct node *&root,int data){
	if(root == NULL){
		root = createNode(data);
		return;
	}
	queue<node*>q;
	q.push(root);
	struct node *current;
	while(!q.empty()){
		current = q.front();
		q.pop();
		if(current->left == NULL){
			current->left = createNode(data);
			return;
		}
		else{
			q.push(current->left);
		}
		if(current->right == NULL){
			current->right = createNode(data);
			return;
		}
		else{
			q.push(current->right);
		}
	}
}

void traverse(struct node *topNode){
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
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
	struct node *root = NULL;
    insert(root, 10);
    insert(root, 12);
    insert(root, 6);
    insert(root, 7);
    insert(root, 5);
    insert(root, 13);
    traverse(root);
	return 0;
}
