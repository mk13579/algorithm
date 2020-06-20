#include<bits/stdc++.h>
using namespace std;
const int N = 103;
const int inf = 1000000009;
int dp[N][N]={0};
int n=0,m=0;
void init(){
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j]=inf;
	for(int i=1;i<=n;i++) dp[i][i]=0;
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	init();
	for(int i=1,x,y,c;i<=m;i++){
		cin>>x>>y>>c;
		dp[x][y]=dp[y][x]=c;
	}
	floyd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 


/*

最短路的动态规划解法 


*/
