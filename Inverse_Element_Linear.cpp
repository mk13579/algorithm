#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
long long inv[N]={0,1};
long long n,p;
int main(){
	cin>>n>>p;
	for(int i=2;i<N;i++) inv[i]=(p-p/i)*inv[p%i]%p;
	cout<<n*inv[n]%p<<endl;
	return 0;
} 


/*

逆元线性 


*/
