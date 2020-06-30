#include<bits/stdc++.h>
using namespace std;
const int N = 103;
const long long mod = 1000000009;
long long fact[N]={1};
long long n=0,m=0;
long long pow(long long a,long long b,long long p){
	long long ret=1%p;
	while(b){
		if(b&1) ret=a*ret%p;
		b>>=1;a=a*a%p;
	}
	return ret;
}
long long C(long long n,long long m,long long p){
	if(n-m<0) return -1;
	return fact[n]*pow(fact[m],p-2,p)%p*pow(fact[n-m],p-2,p)%p;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<N;i++) fact[i]=fact[i-1]*i%mod; 
	cout<<C(n,m,mod)<<endl;
	return 0;
} 


/*

逆元求组合数 

*/
