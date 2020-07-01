#include<bits/stdc++.h>
using namespace std;
const int N = 10003;
const int inf = 100000009;
int tot=0;
int head[N]={0},nex[N]={0},V[N]={0},E[N]={0},W[N]={0};
int dis[N]={0},rev[N]={0},ree[N]={0};
bool vis[N]={0};
int n=0,m=0,s=0,t=0,f=0;
void init(){
	memset(head,-1,sizeof(head));
}
void add(int x,int y,int e,int w){
	tot++;
	nex[tot]=head[x];V[tot]=y;E[tot]=e;W[tot]=w;
	head[x]=tot;
}
bool spfa(int s,int t){
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[s]=0;
	queue<int> que;que.push(s);vis[s]=1;
	while(que.size()){
		int u=que.front();que.pop();vis[u]=0;
		for(int i=head[u];~i;i=nex[i]){
			if(E[i]>0&&dis[V[i]]>dis[u]+W[i]){
				dis[V[i]]=dis[u]+W[i];
				rev[V[i]]=u;ree[V[i]]=i;
				if(!vis[V[i]]){
					vis[V[i]]=1;
					que.push(V[i]);
				}
			}
		}
	}
	return dis[t]!=inf;
}
int maxflowmin(int s,int t,int f){
	int ret=0;
	while(f>0&&spfa(s,t)){
		int d=f;
		int tmp=t;
		while(tmp!=s){
			d=min(d,E[ree[tmp]]);
			tmp=rev[tmp];
		}
		tmp=t;
		while(tmp!=s){
			E[ree[tmp]]-=d;
			E[ree[tmp]^1]+=d;
			tmp=rev[tmp];
		}
		f-=d;
		ret+=dis[t]*d;
	}
	return ret;
}
int main(){
	init(); 
	cin>>n>>m>>s>>t>>f;
	for(int i=1;i<=m;i++){
		int a,b,c,d;cin>>a>>b>>c>>d;
		add(a,b,c,d);add(b,a,0,-d);
	}
	cout<<maxflowmin(s,t,f)<<endl;
	return 0;
} 

/*

费用流 

*/
