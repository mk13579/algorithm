#include<bits/stdc++.h>
using namespace std;
const int N = 55;
const int inf = 1000000009;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int f[N]={0};
int num[N]={0};
int tot=0;
int mx=inf;
int n=0;
string h[N];
string q[N];
void add(int a,int b){
	tot++;
	nex[tot]=head[a];V[tot]=b;
	head[a]=tot;
}
int find(int rt,int fa){
	num[rt]=1;
	f[rt]=0;
	for(int i=head[rt];i;i=nex[i]){
		int to=V[i];
		if(to==fa) continue;
		find(to,rt);
		f[rt]=max(f[rt],num[to]);
		num[rt]+=num[to];
	}
	f[rt]=max(f[rt],n-num[rt]);
	if(f[rt]<mx) mx=f[rt];
}
void dfs(int rt,int fa){
	h[rt]="0";
	int t=0;
	for(int i=head[rt];i;i=nex[i]){
		int to=V[i];
		if(to==fa) continue;
		dfs(to,rt);
		q[++t]=h[to]; 
	}
	sort(q+1,q+1+t);
	for(int i=1;i<=t;i++) h[rt]+=q[i];
	h[rt]+="1";
}
string solve(){
	memset(head,0,sizeof(head));
	memset(num,0,sizeof(num));
	memset(f,0,sizeof(f));
	mx=inf;
	string ret="";
	tot=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int v;cin>>v;
		if(v){
			add(i,v);add(v,i);
		}
	}
	find(1,0);
	for(int i=1;i<=n;i++){
		if(mx==f[i]){
			dfs(i,0);
			if(h[i]>ret) ret=h[i];
		}
	}
	return ret;
}
string mk[N];
int main(){
	int T=0;cin>>T;
	for(int i=1;i<=T;i++){
		mk[i]=solve();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(mk[i]==mk[j]){
				cout<<j<<endl;
				break;
			}
		}
	}
	return 0;
} 

/*

树同构算法 

*/
