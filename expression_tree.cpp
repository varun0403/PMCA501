#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<malloc.h>
#include<string>
using namespace std;

struct node{
	char data;
	struct node *left;
	struct node *right;
};

struct node *createNode(char ch){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = ch;
	new_node->left = NULL;
	new_node->right = NULL;
}

int priority(char c){
	if(c == '^'){
		return 3;
	}
	if(c == '*' || c == '/'){
		return 2;
	}
	if(c == '+' || c == '-'){
		return 1;
	}
	return 0;
}

struct node *generateExpressionTree(string postfix){
	stack<struct node*>s;
	char left,right,leftNode_val,rightNode_val;
	for(int i=0; i<postfix.length(); i++){
		char c = postfix[i];
		if(priority(c) == 0){
			struct node *new_node = createNode(c);
			s.push(new_node);
		}
		else{
			struct node *right = s.top();
			s.pop();
			struct node *left = s.top();
			s.pop();
			struct node *parent = createNode(c);
			parent->left = left;
			parent->right = right;
			s.push(parent);
		}
	}
	return s.top();
}

void bfs(struct node *temp) {
    queue<node*> q;
    vector<char> arr;
    q.push(temp);
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
    cout << endl;
}


int main(){
	string postfix = "359+2*+";
	struct node *expTree = generateExpressionTree(postfix);
	bfs(expTree);
	return 0;
}
