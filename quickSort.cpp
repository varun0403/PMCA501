#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
	int pivot = high;
	int left = 0, right = high - 1;
	int mid = (high - low) / 2 + low;
	swap(arr[mid],arr[pivot]);
	
	while(left <= right){
		if(arr[left] <= arr[pivot]){
			left++;
		}
		else if(arr[right] > arr[pivot]){
			right--;
		}
		else{
			swap(arr[left],arr[right]);
		}
	}
	swap(arr[left],arr[pivot]);
	return left;
}

int quickSort(int arr[],int low,int high){
	if(low < high){
		int pi = partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}

void print_arr(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
	int nums[] = {5,4,3,2,1};
	int low = 0;
	int high = sizeof(nums)/sizeof(nums[0]);
	quickSort(nums,low,high-1);
	print_arr(nums,high);
	return 0;
}
