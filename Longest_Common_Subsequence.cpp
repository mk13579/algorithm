#include<bits/stdc++.h>
using namespace std;
const int N = 1003;
char a[N],b[N];
int dp[N][N]={0};
int n=0,m=0;
int ret=0;
int main(){
	cin>>(a+1);cin>>(b+1);
	n=strlen(a+1);m=strlen(b+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			ret=max(ret,dp[i][j]);
		}
	}
	cout<<ret<<endl;
	return 0;
} 
/*

最长公共子序列 

*/
