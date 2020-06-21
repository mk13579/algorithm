#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
bool vis[N]={0};
int prime[N]={0};
int num=0;
void make_prime(){
	memset(vis,1,sizeof(vis));
	num=0;vis[0]=vis[1]=0;
	for(int i=2;i<N;i++){
		if(vis[i]) prime[++num]=i;
		for(int j=1;j<=num&&i*prime[j]<N;j++){
			vis[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	make_prime();
	int n=0;cin>>n;
	while(n--){
		int a;
		cin>>a;
		if(vis[a]) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}

/*

线性筛素数 


*/
