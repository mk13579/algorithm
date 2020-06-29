#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
long long a[N],m[N];
int n;
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
long long inv(long long a,long long b){
	long long x=0,y=0;
	long long d=exgcd(a,b,x,y);
	if(d!=1) return -1;
	x=(x%b+b)%b;
	return x; 
}
long long M = 1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>m[i];
	for(int i=1;i<=n;i++) M*=m[i];
	long long ret=0;
	for(int i=1;i<=n;i++){
		long long Mi=M/m[i];
		long long ni=inv(Mi,m[i]);
		ret+=a[i]*Mi*ni%M;ret%=M;
	}
	cout<<ret<<endl;
	return 0;
} 
/*


孙子剩余定理 


*/
