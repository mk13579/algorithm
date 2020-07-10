#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
const long long N = 10005;
const long long mod = 998244353; 
long long a[N]={0};
void add(int x,long long v){
	for(int i=x;i<N;i+=lowbit(i)) a[i]+=v;
}
long long sum(int x){
	long long ret=0;
	for(int i=x;i>0;i-=lowbit(i)) ret+=a[i];
	return ret;
}
long long p[N]={0};
long long fact[N]={1};
int n=0;
long long ret=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) fact[i]=i*fact[i-1]%mod;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++){
		ret+=fact[n-i]*(p[i]-1-sum(p[i]-1))%mod;
		ret%=mod;
		add(p[i],1);
	}
	ret++;
	cout<<ret%mod<<endl;
	return 0;
} 



/*


康托展开由序确定排序 


*/
