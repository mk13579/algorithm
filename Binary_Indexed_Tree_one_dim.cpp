#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
const int N = 1005;
int a[N]={0};
void add(int x,int v){
	for(int i=x;i<N;i+=lowbit(i)) a[i]+=v;
}
int sum(int x){
	int ret=0;
	for(int i=x;i>0;i-=lowbit(i)) ret+=a[i];
	return ret;
}
int main(){
	int n=0;cin>>n;
	for(int i=1,x=0;i<=n;i++){
		cin>>x;add(x,1);
	}
	cout<<sum(10)<<endl;
	return 0;
}


/*

Ò»Î¬Ê÷×´Êý×é 


*/
