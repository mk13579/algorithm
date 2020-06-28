#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1000000009;
int tot=0,head[N]={0},nex[N]={0},V[N]={0},W[N]={0};
void add(int x,int y,int c){
	tot++;
	nex[tot]=head[x];V[tot]=y;W[tot]=c;
	head[x]=tot;
}
int n=0,m=0,k=0;
int dis[N]={0};
bool vis[N]={0};
struct node{
    int to,len;
    node(int _to=0,int _len=0){
    	to=_to;len=_len;
	}
    bool operator < (const node & a) const{
        return len+dis[to]>a.len+dis[a.to];
    }
};
void Dij(int x){
	priority_queue<pair<int,int> >que;
	for(int i=0;i<=n;i++) dis[i]=inf,vis[i]=0;
	dis[x]=0;
	que.push(make_pair(0,x));
	while(que.size()){
		pair<int,int> tmp=que.top();que.pop();
		if(vis[tmp.second]) continue;
		vis[tmp.second]=1;
		for(int i=head[tmp.second];i;i=nex[i]){
			int to=V[i],w=W[i];
			if(dis[to]>dis[tmp.second]+w){
				dis[to]=dis[tmp.second]+w;
				que.push(make_pair(-dis[to],to));
			}
		}
	}
}
int A_star(int x,int y,int k){
	int num=0;
	priority_queue<node> que;
	que.push(node(x,0));
	while(que.size()){
		node tmp=que.top();que.pop();
		if(tmp.to==y) num++;
		if(num==k) return tmp.len;
		for(int i=head[tmp.to];i;i=nex[i]){
			int to=V[i],w=W[i];
			que.push(node(to,w+tmp.len));	
		}
	}
	return -1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,c;cin>>x>>y>>c;
		add(x,y,c);add(y,x,c);
	}
	Dij(n);
	cout<<A_star(1,n,k)<<endl;
	return 0;
} 

/*


利用A* 求K短路 



*/
