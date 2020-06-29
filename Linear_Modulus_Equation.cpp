#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N]={0},m[N]={0};
int n=0;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	long long d=exgcd(b,a%b,x,y);
	long long tmp=y;
	y=x-(a/b)*y;
	x=tmp;
	return d;
}
long long A=0,M=0,x=0,y=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>m[i];
	A=a[1],M=m[1];
	for(int i=2;i<=n;i++){
		long long d=exgcd(M,m[i],x,y);
		if((A-a[i])%d) exit(0);
		x=x*(A-a[i])/d;
		x=(x%(m[i]/d)+(m[i]/d))%(m[i]/d);
		//cout<<x<<endl;
		A=A-M*x;M=M*m[i]/d;A%=M;A+=M;A%=M;
	}
	cout<<A<<endl;
	return 0;
} 
/*


模线性方程组 

*/
