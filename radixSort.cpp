#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getMax(vector<int>&arr){
	int max_val = arr[0];
	for(int i=1; i<arr.size(); i++){
		if(arr[i] > max_val){
			max_val = arr[i];
		}
	}
	return max_val;
}

void radixSort(vector<int>& arr, int n) {
	int limit = getMax(arr);
    	for (int exp = 1; exp <= limit; exp *= 10) { 
        	vector<stack<int> > bucket(10); //empty vector is initialised before every iteration
        	vector<int> nums;
        	for (int i = 0; i < n; i++) {
            		int pos = (arr[i] / exp) % 10; //extracts the digits from last to front: iteration basis
            		bucket[pos].push(arr[i]); //pushes the value into the required bucket
        	}
        	for (int i = 0; i < 10; i++) {
            		while (!bucket[i].empty()) {
                		nums.push_back(bucket[i].top()); //pops the value from each bucket into the vector
                		bucket[i].pop();
            		}
       		}
        	arr = nums; 
    	}
}

void print_array(vector<int>&arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main() {
    vector<int> arr;
    arr.push_back(171);
    arr.push_back(802);
    arr.push_back(4);
    arr.push_back(211);
    arr.push_back(662);
    int n = arr.size();
    cout << "Array before: ";
    print_array(arr,n);
    radixSort(arr, n);
    cout << "Array after: ";
    print_array(arr,n);
    return 0;
}

