#include<iostream>

using namespace std;

long long matrix[16][16]={0};

int temp [16][16]={0};
int visit [16][16]={0};
long long res=0;
	
void cmp(){
	for(int i=1; i<=15; i++){
		for(int j=1; j<=15; j++ ){
			visit[i][j]=temp[i][j];
		}
	}
}
	
void backtrack(int x, int y,int row,int col){
	if(x==row && y==col){
		if(res<matrix[row][col]){
			res=matrix[row][col];
			cmp();
		}
	}
	if(x<row){
		temp [x+1][y]=1;
		matrix[x+1][y]+=matrix[x][y];
		backtrack(x+1 , y , row, col);
		matrix[x+1][y]-=matrix[x][y];
		temp [x+1][y]=0;
	}
	if(y<col){
		temp [x][y+1]=1;
		matrix[x][y+1]+=matrix[x][y];
		backtrack( x, y+1 , row, col);
		matrix[x][y+1]-=matrix[x][y];
		temp [x][y+1]=0;
	}
}
	
	
void dynamicProgram(int row, int col){
	long long F[101][101]={0};
	for(int i=1 ; i<=row; i++){
		for(int j=1; j<=col; j++){
			F[i][j] =max(F[i-1][j], F[i][j-1]) * 2 + matrix[i][j] ;
			
			cout<<F[i][j]<<" ";
		}
		cout<<"\n";
	}
		//show
//		for(int i=1 ; i<= row; i++){
//			for(int j=1; j<= col; j++){
//				cout<<F[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		cout<<F[row][col]<<"\n";
		
		//truy vet
//		int x=1,y=1;
//		int dx[30]={0};
//		int dy[30]={0};
//		int pos= row+col-1;
//		while(1){
//			cout<<x<<" "<<y<<"\n";
//			if(x==row&&y==col) break;
//			if(F[x][y+1] + matrix[x][y] == F[x][y] )  {
//				y++;
//			}else{
//				x++;
//			}
//		}	
	}
	
int main(){
	//initial
	int row; cin>>row;
	int col= row;
	
	for(int i=1; i<=row; i++){
		for(int j=1; j<=col; j++ ){
			cin>>matrix[i][j];
		}
	}
	//quy hoach dong
	dynamicProgram(row,col);
//	backtrack
//	int x=1;
//	int y=1;
//	backtrack(x,y,row,col);
//	cout<<res<<endl;
//			
//	//show step
//	visit[row][col]=1;
//	visit[1][1] =1;
//	int cnt= row+col-1; 	
//			
//	while(cnt>0){
//		cout<<x<<" "<<y<<endl;
//		if(x<row&& visit[x+1][y]==1){
//			x++;
//		}else{
//			y++;
//		}
//		cnt--;
//	}
	
	return 0;
}
