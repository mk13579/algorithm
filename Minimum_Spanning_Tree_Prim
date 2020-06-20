#include<bits/stdc++.h>
using namespace std;
const int N = 1002;
const int M = 2002;
const int inf = 1000000009;
int tot=0;
int head[N]={0};
int nex[M]={0};
int V[M]={0};
int W[M]={0};
int dis[N]={0};
bool vis[N]={0};
priority_queue<pair<int,int> >que;
int n=0,m=0;
void init(){
	memset(head,0,sizeof(head));
	memset(nex,0,sizeof(nex));
	memset(V,0,sizeof(V));
	memset(W,0,sizeof(W));
	tot=0;
}
void add(int x,int y,int c){
	tot++;
	nex[tot]=head[x];V[tot]=y;W[tot]=c;
	head[x]=tot;
}
int Prime(){
	int ret=0;
	for(int i=0;i<=n;i++) dis[i]=inf;
	memset(vis,0,sizeof(vis));
	que.push(make_pair(0,1));
	dis[1]=0;
	while(que.size()){
		pair<int,int> tmp=que.top();que.pop();
		if(vis[tmp.second]) continue;
		vis[tmp.second]=1;
		ret+=dis[tmp.second];
		for(int i=head[tmp.second];i;i=nex[i]){
			int to=V[i],w=W[i];
			if(dis[to]>w){
				dis[to]=w;
				que.push(make_pair(-dis[to],to));
			}
		}
	}
	return ret;
}
int main(){
	cin>>n>>m;
	init();
	for(int i=1,x,y,c;i<=m;i++){
		cin>>x>>y>>c;add(x,y,c);add(y,x,c);
	}
	cout<<Prime()<<endl;
	return 0;
}


/*

基于 Prime最小生成树 

*/ 
