#include<bits/stdc++.h>
using namespace std;
const int N = 103;
const int mod = 1000000009;
long long C[N][N]={0};
int main(){
	int n=0,m=0;cin>>n>>m;
	for(int i=0;i<N;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cout<<C[n][m]<<endl;
	return 0;
} 


/*

递推求组合数 

*/
