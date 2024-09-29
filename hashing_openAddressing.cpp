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
		if(arr[hash_val] == 0){
			arr[hash_val] = data;
			return;
		}
		else{
			int start = hash_val;
			int end = (hash_val + 1) % size;
			while(start != end){
				if(arr[end] == 0){
					arr[end] = data;
					return;
				}
				else{
					end = (end + 1) % size;		
				}
			}
			cout<<"No slots in hashtable to insert "<<endl;
		}
	}
	
	void del(int data){
		int hash_val = data % size;
		if(arr[hash_val] == data){
			arr[hash_val] = 0;
			return;
		}
		else{
			int start = hash_val;
			int end = (hash_val + 1) % size;
			while(start != end){
				if(arr[end] == data){
					arr[end] = 0;
					return;
				}
				else{
					end = (end + 1) % size;		
				}
			}
			cout<<"Data not present in the hashtable"<<endl;
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
