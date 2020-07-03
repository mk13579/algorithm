#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int base = 131;
long long H[N]={0};
char s[N];
long long Hash(char *s){
	long long ret=0;
	for(int i=0;s[i];i++) ret=ret*base+s[i];
	return ret&(0x7fffffff); 
}
int main(){
	int n=0;cin>>n;
	int ret=1;
	for(int i=1;i<=n;i++){
		cin>>s;
		H[i]=Hash(s);
	}
	sort(s+1,s+1+n);
	for(int i=2;i<=n;i++){
		if(H[i]!=H[i-1]) ret++;
	}
	cout<<ret<<endl;
	return 0;
}

/*

字符串hash 


*/
