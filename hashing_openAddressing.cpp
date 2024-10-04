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
		int temp = hash_val;
		while(true){
			if(arr[hash_val] == 0){
				arr[hash_val] = data;
				return;
			}
			else{
				hash_val = (hash_val + 1) % size;
				if(hash_val == temp){
					cout << "No slots available." << endl;
					return;
				} 
			}
		}
	}
	
	void del(int data){
		int hash_val = data % size;
		int temp = hash_val;
		while(true){
			if(arr[hash_val] == data){
				arr[hash_val] = 0;
				return;
			}
			else{
				hash_val = (hash_val + 1) % size;
				if(hash_val == temp){
					cout << "Search element not present in the hashtable" << endl;
					return;
				}
			}
		}
	}
	
	void traverse(){
		for(int i=0; i<size; i++){
			cout << arr[i] << " ";
		}
		cout<<endl;
	}
};

int main(){
	HashTable h1(5);
	h1.insert(5);
	h1.insert(15);
	h1.insert(30);
	h1.insert(35);
	h1.insert(45);
	h1.del(353);
	h1.traverse();
	return 0;
}
