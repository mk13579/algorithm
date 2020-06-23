#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int tot=0;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int DNF[N]={0},LOW[N]={0};
bool vis[N]={0};
int index=0;
int root=0;
void init(){
	tot=0;
	root=1;
	memset(head,0,sizeof(head));
	memset(nex,0,sizeof(nex));
	memset(V,0,sizeof(V));
	memset(vis,0,sizeof(vis));
}
void add(int x,int y){
	tot++;
	nex[tot]=head[x];V[tot]=y;
	head[x]=tot;
}
void tarjan(int rt){
	DNF[rt]=LOW[rt]=++index;
	int son=0;
	for(int i=head[rt];i;i=nex[i]){
		int to=V[i];
		if(!DNF[to]){
			son++;
			tarjan(to);
			LOW[rt]=min(LOW[rt],LOW[to]);
			if(rt==root&&son>1||rt!=root&&DNF[rt]<=LOW[to]) vis[rt]=1;
		}else LOW[rt]=min(LOW[rt],LOW[to]);
	}
}
int n=0,m=0;
int main(){
	cin>>n>>m;
	init();
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		add(a,b);add(b,a);
	}
	for(int i=1;i<=n;i++) if(!DNF[i]) tarjan(i);
	for(int i=1;i<=n;i++){
		if(vis[i]) cout<<i<<" ";
	}
	cout<<endl;
	return 0;
} 


/*

targan实现割点 

*/
