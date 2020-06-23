#include<bits/stdc++.h>
#define N 100005
using namespace std;
const int maxn=1e6,P=998244353,G=3,inv_G=332748118;
long long a[maxn],b[maxn];
#define inv(x) fastpow(x,P-2)
long long fastpow(long long a,long long b){
	long long ret=1%P;
	while(b){
		if(b&1) ret=ret*a%P;
		b>>=1;a=a*a%P;
	}
	return ret;
}
void NNT(int len,long long *a,int o){
    if(len==1) return;
    long long l[(len>>1)+3],r[(len>>1)+3];
    for(int i=0;i<=len;i+=2) l[i>>1]=a[i],r[i>>1]=a[i+1];
    NNT(len>>1,l,o);NNT(len>>1,r,o);
    long long wn=fastpow(o==1?G:inv_G,(P-1)/len),w0=1LL;
    for(int i=0;i<(len>>1);i++,w0=w0*wn%P){
        a[i]=(l[i]+w0*r[i])%P;
        a[i+(len>>1)]=((l[i]-w0*r[i])%P+P)%P;
    }
}
int n=0,m=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>a[i];
    for(int i=0;i<=m;i++) cin>>b[i];
    int len=1;
    for(;len<=n+m;len<<=1);
    NNT(len,a,1);NNT(len,b,1);
    for(int i=0;i<=len;i++) a[i]=a[i]*b[i]%P;
    NNT(len,a,-1);
    long long inv=inv(len);
    for(int i=0;i<=n+m;i++) cout<<inv*a[i]%P<<" ";cout<<endl;
    return 0;
}


/*

NNT快速数论变化 


*/
