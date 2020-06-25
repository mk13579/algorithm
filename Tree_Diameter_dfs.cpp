#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1000000009;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int W[N]={0};
int d[N]={0};
int f[N]={0};
int n=0;
int tot=0;
int ret=0;
void add(int x,int y,int c){
	tot++;
	nex[tot]=head[x];V[tot]=y;W[tot]=c;
	head[x]=tot;
}
void dfs(int rt,int fa){
	for(int i=head[rt];i;i=nex[i]){
		int to=V[i],w=W[i];
		if(to==fa) continue;
		dfs(to,rt);
		f[rt]=max(f[rt],d[rt]+d[to]+w);
		d[rt]=max(d[rt],d[to]+w);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y,c;cin>>x>>y;
		add(x,y,c);add(y,x,c);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) ret=max(ret,f[i]);
	cout<<ret<<endl;
	return 0;
}


/*


树直径 

*/
