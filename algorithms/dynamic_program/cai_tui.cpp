#include<iostream>

using namespace std;
	//lay cac mon do bo vao tui
	int w[101];			//can nang
	int v[101];			//gia tri
	int pos[101];   	//vi tri
	//-----------------------------------------CACH 1: Quy hoach dong---------------------------
	int f[101][101];   //f[i][j]   : tui co trong luong j voi w[0..i]  
	
	void dynamicProgram(int n, int m){
		//
		// f[i][j]  = max( f[i-1][j] , f[i-1][j-w[i] + v[i])    : moi vat chon 0 - 1
		// f[i][j]  = max( f[i-1][j] , f[i][j-w[i] + v[i])    : moi vat chon >=0
		// O( n*m )
		for(int i= 1; i<= n ; i++){
			for(int j=1; j<=m;j++ ){
				int x = (j- w[i] >=0 ) ? f[i-1][j-w[i]] + v[i]: 0;
				
				if( f[i-1][j] > x ){
					f[i][j]= f[i-1][j];
				}else{
					f[i][j]= x;
				}
//				cout<<f[i][j]<<"   ";
			}
//			cout<<"\n";
		}
		
		//show
		int x=n, y=m;
		cout<<f[x][y]<<"\n";
		while( y > 0 && x > 0 ){
			if(f[x][y] == f[x-1][y] ){
				x--;
			}else{
				cout<<x<<" ";
				y-=w[x];
				x--;				//vi chon 0-1 lan ( duoc chon nhieu lan thi bo lenh nay di )
			}
		}
	}

	//---------------------------------CACH 2: Tham lam--------------------------------------------------
	void sortByWeight(int n){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if( (double)v[i]/ w[i] >(double)v[j] / w[j] ){
					//swap
					int a = w[i];
					w[i]= w[j];
					w[j]=a;
					
					a= v[i];
					v[i]=v[j];
					v[j]=a;
					
					a=pos[i];
					pos[i]=pos[j];
					pos[j]=a;
				}
			}
		}
	}
	void greedy(int n ,int m){
		sortByWeight(n);
		//find  max
		int res=0;
		int sum =m;
		int i=n;
		int pick[101];
		int selectNumber=0;
		while(i>0){
			if(sum-w[i]>=0){
				sum-=w[i];
				res+=v[i]; 
				pick[selectNumber++]= pos[i];
			}
			i--;
		}	
		//show	
		cout<<res<<"\n";
		for(int i=0; i<selectNumber;  i++){
			cout<<pick[i]<<" ";
		}
	}
int main(){
	//initial
	int n,m; cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>w[i]>>v[i];
		pos[i]=i;
	}
	//handle
	dynamicProgram(n,m);
	//show output
	//cach 2 dung tham lam
	/*
	sai trong TH: khi chon >=0 lan 
	w =  1 3 4 
	v =  1 6 9  
	sai trong TH: khi chon 0-1 lan
	w = 1 6  6   8  8
	v = 1 10 11  16 18  
	*/
//	greedy(n,m);
	
	
	return 0;
}
