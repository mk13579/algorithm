#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 200005;
const int inf = 1000000009;
int head[N]={0};
int nex[M]={0};
int V[M]={0};
int W[M]={0};
int dis[N]={0};
bool vis[N]={0};
int tot=0;
priority_queue<pair<int,int> > que;
int n=0,m=0;
void init(){
    tot=0;
    memset(head,0,sizeof(head));
    memset(nex,0,sizeof(nex));
    memset(V,0,sizeof(V));
    memset(W,0,sizeof(W));
}
void add(int x,int y,int c){
    tot++;
    nex[tot]=head[x];W[tot]=c;V[tot]=y;
    head[x]=tot;
}
void Dijkstra(int x){
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
bool bi=true;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    init();
    for(int i=1,a,b,c;i<=m;i++){
        cin>>a>>b>>c;add(a,b,c);
        if(bi) add(b,a,c);
    }
    Dijkstra(1);
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<endl;
    return 0;
}


/*
优先队列优化的DIJkstra
O(nlogn)


*/
