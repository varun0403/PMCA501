#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void radixSort(vector<int>& arr, int n) {
    for (int exp = 1; exp <= 100; exp *= 10) { 
        vector<stack<int> > bucket(10); 
        vector<int> te;
        for (int i = 0; i < n; i++) {
            int pos = (arr[i] / exp) % 10;
            bucket[pos].push(arr[i]);
        }
        for (int i = 0; i < 10; i++) {
            while (!bucket[i].empty()) {
                te.push_back(bucket[i].top());
                bucket[i].pop();
            }
        }
        arr = te;
        te.clear(); 
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr;
    arr.push_back(170);
    arr.push_back(802);
    arr.push_back(244);
    arr.push_back(211);
    arr.push_back(662);
    int n = arr.size();
    cout << "Array before: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Array after: ";
    radixSort(arr, n);

    return 0;
}
