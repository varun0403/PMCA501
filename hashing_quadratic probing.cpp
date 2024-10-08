#include <iostream>
#include <vector>
using namespace std;

class HashTable{
	private:
		int size;
		vector<int>arr;
	
	public:
		HashTable(int s){
			size = s;
			arr.resize(size);
		}
	
	void insert(int data){
		int hash_val = data % size;
		for(int i = 0; i < size; i++){
			int slot = (hash_val + (i*i)) % size;
			if(arr[slot] == 0){
				arr[slot] = data;
				return;
			}
			else if(arr[slot] == data){
				cout << "Key already exist!" << endl;
				return;
			}
		}
		cout << "No slots available in hash table" << endl;
	}
	
	void del(int data){
		int hash_val = data % size;
		for(int i=0; i<size; i++){
			int slot = (hash_val + (i*i)) % size;
			if(arr[slot] == data){
				arr[slot] = 0;
				return;
			}
		}
		cout << "Key does not exist in the hashtable!" << endl;
	}
	
	void traverse(){
		for(int i=0; i<size; i++){
			cout << "Index: " << i << ", Value: " << arr[i] << endl;
		}
		cout<<endl;
	}
};

int main(){
	HashTable h1(10);
	h1.insert(49);
	h1.insert(45);
	h1.insert(38);
	h1.insert(26);
	h1.insert(50);
	h1.insert(60);
	h1.insert(456);
	h1.del(49);
	h1.traverse();
	return 0;
}
