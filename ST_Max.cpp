#include<cstdio>
#include<iostream>
#include<cmath>
#define N 100005
using namespace std;
int dp[N][20]={0};
int query(int l,int r){
    int len=log2(r-l+1);
    return max(dp[l][len],dp[r-(1<<len)+1][len]);
}
int main(){
    int n=0,m=0;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&dp[i][0]);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            dp[j][i]=max(dp[j][i-1],dp[min(j+(1<<(i-1)),n)][i-1]);
        }
    }
    while(m--){
        int l=0,r=0;scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}


/*

ST表 


*/
