#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = high;
    int left = low;
    int right = high - 1;

    while (left <= right) {
        if (arr[left] <= arr[pivot]){
            left++;
        }
        else{
        	if(arr[right] > arr[pivot]){
        		right--;
			}
			else{
				swap(arr[left],arr[right]);
			}
		}
	}
    swap(arr[left], arr[pivot]);
    return left; //return pos of pivot
}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high); //partition the array
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void print_arr(int arr[], int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array before sorting: ";
    print_arr(arr,size);
    quickSort(arr, 0, size - 1);
    cout<<"\nArray after sorting: ";
    print_arr(arr, size);      
    return 0;
}

