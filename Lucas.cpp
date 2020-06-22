#include<bits/stdc++.h>
using namespace std;
const long long N = 100005;
long long fact[N]={1};
long long pow(long a,long b,long p){
	long long ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		b>>=1;a=a*a%p;
	}
	return ret;
}
void init(long long p){
	for(int i=1;i<N;i++) fact[i]=fact[i-1]*i%p;
}
long long C(long long n,long long m,long long p){
	if(n<m) return 0;
	return fact[n]*pow(fact[m],p-2,p)%p*pow(fact[n-m],p-2,p)%p;
}
long long Lucas(long long n,long long m,long long p){
	if(!m) return 1;
	return C(n%p,m%p,p)*Lucas(n/p,m/p,p)%p;
}
int main(){
	int T=0;cin>>T;
	while(T--){
		long long n=0,m=0,p=0;
		cin>>n>>m>>p;
		init(p);
		cout<<C(n,m,p)<<endl;
		cout<<Lucas(n,m,p)<<endl;
	}
	return 0;
} 

/*

卢卡斯定理

*/
