#include<iostream>
using namespace std;

void linear_search(int arr[], int len, int key){
  	for(int i=0;i<len;i++){
    		if(arr[i] == key){
      			cout<<"\nKey found at index "<<i;
      			return;
    		}
  	}
  	cout<<"\nKey not found!";
}

void recursive_linear_search(int arr[], int len, int key){
  	if(arr[len-1] == key){
    		cout<<"\nKey found at index "<<len-1;
    		return;
  	}
  	else{
    		if(len < 0){
    			  cout<<"\nKey not found!";
    		}
  		  else{
  			    return recursive_linear_search(arr,len-1,key);
  		  }
    }
}

void binary_search(int arr[], int len, int key){
  	int low = 0,high=len;
  	int mid = (low + high)/2;
  	if(arr[mid] == key){
  		  cout<<"\nKey found at index "<<mid;
  	}
  	else{
    		if(arr[mid] > key){
      			for(int i=0; i<mid-1; i++){
        				if(arr[i] == key){
          					cout<<"\nKey found at index "<<i;
          					return;
        				}
      			}
    		}
    		else{
      			for(int i=mid+1; i<high; i++){
        				if(arr[i] == key){
        					  cout<<"\nKey found at index "<<i;
        					  return;
        				}
      			}
    		}
  	}
}

int main(){
  	int n,i,key;
  	cout<<"Enter size of array: ";
  	cin>>n;
  	int arr[n];
  	for(i=0;i<n;i++){
  		  cout<<"Enter value of arr["<<i<<"]: ";
  		  cin>>arr[i];
  	}
  	cout<<"\nEnter search value: ";
  	cin>>key;
  	binary_search(arr,n,key);
  	return 0;
}
