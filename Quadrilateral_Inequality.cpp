#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int inf = 1000000009;
int a[N]={0};
int n=0;
int dp[N][N]={0};
int w[N][N]={0};
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=inf;
    for(int i=1;i<=n;i++){
        cin>>a[i];a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        w[i][i]=i;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            for(int k=w[i][j-1];k<=w[i+1][j];k++){
                if(dp[i][j]>dp[i][k]+dp[k+1][j]+a[j]-a[i-1]){
                    dp[i][j]=dp[i][k]+dp[k+1][j]+a[j]-a[i-1];
                    w[i][j]=k;
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}


/*


四边形不等式优化石子归并问题


*/
