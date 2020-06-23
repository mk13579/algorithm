#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
const int inf = 1e9;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int W[N]={0};
int tot=0;
int dis[N]={0};
int cnt[N]={0};
bool vis[N]={0};
int n=0,m=0;
void add(int x,int y,int c){
	tot++;
	nex[tot]=head[x];V[tot]=y;W[tot]=c;
	head[x]=tot;
}
void init(){
	tot=0;
	memset(head,0,sizeof(head));
	memset(nex,0,sizeof(nex));
	memset(V,0,sizeof(V));
	memset(W,0,sizeof(W));
}
bool spfa(){
	for(int i=1;i<=n;i++){
		dis[i]=inf;vis[i]=0;cnt[i]=0;
	}
	queue<int> que;
	que.push(1);
	dis[1]=0;
	vis[1]=1;
	while(que.size()){
		int v=que.front();que.pop();
		vis[v]=0;
		if(cnt[v]>=n) return 1;
		for(int i=head[v];i;i=nex[i]){
			int to=V[i],w=W[i];
			if(dis[to]>dis[v]+w){
				dis[to]=dis[v]+w;
				cnt[to]++;
				if(cnt[to]>=n) return 1;
				if(!vis[to]){
					vis[to]=1;
					que.push(to);
				}
			}
		}
	}
	return 0;
}
int main(){
	init();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		add(a,b,c);
	}
	cout<<spfa()<<endl;
	return 0;
} 


/*

spfa解决负环问题

*/
