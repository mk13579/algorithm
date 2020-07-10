#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}
long long pow(long long a,long long b){
	long long ret=1;
	while(b){
		if(b&1) ret=ret*a;
		b>>=1;a=a*a;
	}
	return ret;
}
long long n=0;
int main(){
	cin>>n;
	long long ret=0;
	for(int i=1;i<=n;i++) ret+=pow(3,gcd(n,i));
	if(n&1)	ret+=n*pow(3,(n+1)/2);
	else ret+=(n/2)*(pow(3,n/2)+pow(3,(n+2)/2));
	ret/=(2*n);
	cout<<ret<<endl;
	return 0;
} 

/*

n长度 3种珠子拼成项链可翻转旋转问多少个

Polya定理 


*/
