#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1000000009;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int W[N]={0};
bool vis[N]={0};
int dis[N]={0};
int sum=0,pos=0;
int n=0;
int tot=0;
void add(int x,int y,int c){
	tot++;
	nex[tot]=head[x];V[tot]=y;W[tot]=c;
	head[x]=tot;
}
void bfs(int x){
	for(int i=0;i<=n;i++) dis[i]=inf,vis[i]=0;
	queue<int> que;
	que.push(x);dis[x]=0;
	sum=0;pos=x;
	while(que.size()){
		int y=que.front();que.pop();
		if(vis[y]) continue;
		vis[y]=1;
		for(int i=head[y];i;i=nex[i]){
			int to=V[i],w=W[i];
			if(!vis[to]){
				dis[to]=dis[y]+w;
				que.push(to);
				if(dis[to]>sum){
					sum=dis[to];
					pos=to;
				}
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y,c;cin>>x>>y;
		add(x,y,c);add(y,x,c);
	}
	bfs(1);
	bfs(pos);
	cout<<sum<<endl;
	return 0;
}


/*


树直径 

*/
