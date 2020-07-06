#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int sum[N]={0},g[N]={0},f[N]={0},dp[N]={0};
int n=0,L=0;
int q[N]={0};
int l=0,r=-1;
double xie(int j1,int j2){
    return 1.0*(dp[j2]+g[j2]-dp[j1]-g[j1])/(f[j2]-f[j1]);
}
int main(){
    cin>>n>>L;
    for(int i=1;i<=n;i++){
        cin>>sum[i];sum[i]+=sum[i-1];
        f[i]=sum[i]+i;
        g[i]=(f[i]+L+1)*(f[i]+L+1);
    }
    g[0]=(L+1)*(L+1);
    for(int i=1;i<=n;i++){
        while(l<r&&xie(q[l],q[l+1])<=2*f[i]) l++;
        dp[i]=dp[q[l]]+(f[i]-f[q[l]]-1-L)*(f[i]-f[q[l]]-1-L);
        while(l<r&&xie(q[r],i)<xie(q[r-1],q[r])) r--;
        q[++r]=i;
    }
    cout<<dp[n]<<endl;
    return 0;
}
/*


斜率优化DP，NOI玩具例题


*/
