#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 533;
int x[N]={0},y[N]={0};
long long pow(long long a,long long b,long long p){
    long long ret=1%mod;
    while(b){
        if(b&1) ret=ret*a%mod;
        b>>=1;a=a*a%mod;
    }
    return ret;
}
int n=0,v=0;
int main(){
    cin>>n>>v;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    long long ret=0;
    for(int i=1;i<=n;i++){
        long long k=1;
        for(int j=1;j<=n;j++) if(i!=j) k=k*(x[i]+mod-x[j])%mod;
        k=pow(k,mod-2,mod)%mod;
        for(int j=1;j<=n;j++) if(i!=j) k=k*(v+mod-x[j])%mod;
        k=k*y[i]%mod;
        ret+=k;ret%=mod;
    }
    cout<<ret<<endl;
    return 0;
}

/*

拉格朗日插值 


*/
