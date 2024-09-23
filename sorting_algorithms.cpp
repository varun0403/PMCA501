#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n){
	int i,j,temp;
	for(i=0; i<n; i++){
		for(j=0; j<n-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void selection_sort(int arr[], int n){
	int i,j,min_index,temp;
	for(i=0; i<n; i++){
		min_index = i;
		for(j=i+1; j<n; j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		if (i != min_index){
			temp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = temp;
		}
	}
}

void insertion_sort(int arr[], int n){
	for(int i=1;i<n;i++){
		int key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}


void print_array(int arr[],int n){
	for(int i=0;i<n-1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<arr[n-1]<<endl;
}

int main(){
	int size;
	cout<<"Enter size of array: ";
	cin>>size;
	int arr[size];
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}
	insertion_sort(arr,size);
	print_array(arr,size);
	return 0;
}
