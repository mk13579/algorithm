#include<bits/stdc++.h>
using namespace std;
const int N = 10003;
int t=0;
int prime[N]={0};
void div(long long x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			prime[++t]=i;
			while(x%i==0) x/=i;
		}
	}
	if(x>1) prime[++t]=x;
}
long long pow(long long a,long long b,long long p){
	long long ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;b>>=1;
	}
	return ret;
}
long long find(long long p){
	t=0;
	div(p-1);
	for(int i=2;;i++){
		bool mark=1;
		for(int j=1;j<=t&&mark;j++){
			if(pow(i,(p-1)/prime[j],p)==1) mark=0;
		}
		if(mark) return i;
	}
	return -1;
}
int main(){
	long long p=0;
	cin>>p;
	cout<<find(p)<<endl;
	return 0;
} 

/*

求原根 


*/
