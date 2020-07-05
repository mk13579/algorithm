#include<bits/stdc++.h>
using namespace std;
long long pow(long long a,long long b,long long p){
	long long ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		b>>=1;a=a*a%p;
	}
	return ret;
}
long long mul(long long a,long long b,long long p){
	long long ret=0;
	while(b){
		if(b&1) ret=(a+ret)%p;
		b>>=1;a=(a+a)%p;
	}
	return ret;
}
bool Miller_Rabin(long long n,int num){
	if(n==2) return 1;
	if(n%2==0||n==1) return 0;
	long long s=0,d=n-1;
	while(!(d&1)) s++,d>>=1;
	srand((unsigned)time(NULL));
	for(int i=1;i<=num;i++){
		long long a=rand()%(n-3)+2;
		long long x=pow(a,d,n);
		long long y=0;
		for(int j=0;j<s;j++){
			y=mul(x,x,n);
			if(y==1&&x!=1&&x!=n-1) return 0;
			x=y;
		}
		if(y!=1) return 0;
	}
	return 1;
}
long long n=0;
int main(){
	cin>>n;
	if(Miller_Rabin(n,50)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}


/*


大素数概率检测方法 



*/
