#include<bits/stdc++.h>
using namespace std;
long long pow(long long a,long long b,long long p){
	long long ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;b>>=1;
	}
	return ret;
}
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	long long d=exgcd(b,a%b,x,y);
	long long tmp=y;
	y=x-(a/b)*y;
	x=tmp;
	return d;
}
long long a,b,p,x,y;
int main(){
	cin>>a>>b>>p;
	bool mk=0;cin>>mk;
	if(mk) cout<<pow(a,p-2,p)<<endl;
	else{
		exgcd(a,p,x,y);
		x%=p;x+=p;x%=p;
		cout<<x<<endl;
	}
	return 0;
}

/*

求逆元两种方法 

*/
