#include<iostream>
#include<stack>
using namespace std;

int main(){
	int arr[6] = {4,8,6,9,1,1},i,j,count,freq[6]={0,0,0,0,0,0};
	stack<int>s;
	for(i=0;i<6;i++){
		count = 0;
		for(j=i+1;j<6;j++){
			if(arr[i] <= arr[j]){
				count++;
				freq[i] = count;
				break;
			}
			else{
				if(s.empty()){
					s.push(arr[j]);
					count++;
				}
				else{
					if(arr[j] > s.top()){
						s.push(arr[j]);
						count++;
					}
				}
			}
		}
		while(!s.empty()){
			s.pop();
		}
		freq[i] = count;
	}
	for(i=0;i<6;i++){
		cout<<freq[i]<<" ";
	}
	return 0;
}
