#include<bits/stdc++.h>
using namespace std;
const int N = 13;
int Map[N][N]={0};
int vis[3][N][N]={0};
bool mark=0;
int n=0,m=0;
void fill(int x,int y,int k){
	if(!k) return;
	Map[x][y]=k;
	vis[0][x][k]=1;
	vis[1][y][k]=1;
	x=x/m;y=y/m;
	vis[2][m*x+y][k]=1;
}
void rfill(int x,int y,int k){
	Map[x][y]=0;
	vis[0][x][k]=0;
	vis[1][y][k]=0;
	x=x/m;y=y/m;
	vis[2][m*x+y][k]=0;
}
void dfs(int x,int y){
	if(mark) return;
	if(x>=n){
		mark=1;
		return;
	}
	if(y>=n) dfs(x+1,0);if(mark) return;
	if(Map[x][y]) dfs(x,y+1);if(mark) return;
	for(int i=1;i<=n;i++){
		if(!vis[0][x][i]&&!vis[1][y][i]&&!vis[2][x/m*m+y/m][i]){
			fill(x,y,i);
			dfs(x,y+1);if(mark) return;
			rfill(x,y,i);
		}
	}
}
int main(){
	cin>>n;m=sqrt(n);
	if(m*m!=n) exit(0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;cin>>x;fill(i,j,x);
		}
	}
	dfs(0,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<Map[i][j]<<" ";cout<<endl; 
	}	
	return 0;
}
/*

数独暴力搜索 


*/
