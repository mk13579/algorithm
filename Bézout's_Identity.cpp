#include<bits/stdc++.h>
using namespace std;
const int N = 10003;
int a[N]={0};
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int n=0,m=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ret=0;
	for(int i=1;i<=n;i++) ret=gcd(ret,a[i]);
	if(m%ret) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
} 


/*

裴蜀定理


*/
