#include<iostream>
#include<queue>
using namespace std;

int main(){
	int arr[6] = {4,8,6,9,1,1},i,j,count,freq[6]={0,0,0,0,0,0};
	queue<int>q;
	for(i=0;i<6;i++){
		count = 0;
		for(j=i+1;j<6;j++){
			if(arr[i] <= arr[j]){
				count++;
				freq[i] = count;
				break;
			}
			else{
				if(q.empty()){
					q.push(arr[j]);
					count++;
				}
				else{
					if(arr[j] > q.back()){
						q.push(arr[j]);
						count++;
					}
				}
			}
		}
		while(!q.empty()){
			q.pop();
		}
		freq[i] = count;
	}
	for(i=0;i<6;i++){
		cout<<freq[i]<<" ";
	}
	return 0;
}
