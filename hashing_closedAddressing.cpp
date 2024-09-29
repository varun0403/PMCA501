#include<iostream>
#include<vector>
#include<malloc.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *createNode(int val){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = val;
	new_node->next = NULL;
}

class HashTable{
	private:
		int size;
		vector<node*>arr;
	
	public:
		HashTable(int s){
			size = s;
			arr.resize(size,NULL);
		}
	
	void insert(int data){
		struct node *new_node = createNode(data);
		int hash_val = data % size;
		if(arr[hash_val] == NULL){
			arr[hash_val] = new_node;
		}
		else{
			struct node *temp = arr[hash_val];
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}
	
	void del(int data){
		int hash_val = data % size;
		if(arr[hash_val] == NULL){
			cout<<"Element not present in the hashtable!" <<endl;
		}
		else{
			struct node *temp = arr[hash_val];
			if(temp->data == data){
				arr[hash_val] = temp->next;
			}
			else{
				while(temp->next != NULL){
					if(temp->next->data == data){
						temp->next = temp->next->next;
						return;
					}
				}
			}
		}
	}
	
	void traverse(){
		for(int i=0; i<size; i++){
			if(arr[i] != NULL){
				cout << i << " : ";
				struct node *temp = arr[i];
				if(temp->next == NULL){
					cout << temp->data;
				}
				else{
					while(temp->next != NULL){
						cout << temp->data << " -> ";
						temp = temp->next;
					}
					cout << temp->data;
				}
			}
			else{
				cout << i << " : NULL";
			}
			cout << endl;
		}
	}
};

int main(){
	HashTable h1(10);
	h1.insert(23);
	h1.insert(27);
	h1.insert(25);
	h1.insert(93);
	h1.insert(1);
	h1.insert(30);
	h1.insert(45);
	h1.insert(40);
	h1.insert(50);
	h1.del(40);
	h1.traverse();
	return 0;
}
