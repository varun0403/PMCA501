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
	for(i=0;i<n;i++){
		  cout<<arr[i]<<" ";
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
    		temp = arr[min_index];
    		arr[min_index] = arr[i];
    		arr[i] = temp;
  	}
  	for(i=0;i<n;i++){
  		  cout<<arr[i]<<" ";
  	}
}

void isSorted(int arr[], int n){
	int i,j;
	for(i=0;i<n-1;i++){
		  if(arr[i] > arr[i+1]){
			    cout<<"Not sorted!"<<endl;
			    return;
		  }
	}
	cout<<"Sorted!"<<endl;
}

int main(){
	int size;
	cout<<"Enter size of array: ";
	cin>>size;
	int arr[size];
	for(int i=0; i<size; i++){
		  cin>>arr[i];
	}
	isSorted(arr,size);
	return 0;
}
