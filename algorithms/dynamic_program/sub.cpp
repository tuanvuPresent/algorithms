#include<iostream>

using namespace std;
int arr[100001];
int main(){
	//initial
	int n; cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	//handle
	int min=arr[1];
	int res=0;
	for(int i=2; i<=n; i++){
		min= (min<arr[i-1])? min: arr[i-1];
		res=(res>arr[i]-min)? res: arr[i]-min ;
	}
	//show output
	cout<<res;
	
	return 0;
}
