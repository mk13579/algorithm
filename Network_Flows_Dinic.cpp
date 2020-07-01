#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
const int inf = 1000000009;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int W[N]={0};
int d[N]={0};
int cur[N]={0};
int tot=0;
int n=0,m=0;
int s=0,t=0;
void add(int x,int y,int c){
    tot++;
    nex[tot]=head[x];V[tot]=y;W[tot]=c;
    head[x]=tot;
}
void init(){
    memset(head,-1,sizeof(head));
}
bool bfs(int s,int t){
    memset(d,-1,sizeof(d));
    d[s]=0;
    queue<int> que;
    que.push(s);
    while(que.size()){
        int u=que.front();que.pop();
        for(int i=head[u];~i;i=nex[i]){
            int to=V[i],w=W[i];
            if(w>0&&d[to]<0){
                d[to]=d[u]+1;
                que.push(to);
            }
        }
    }
    return d[t]!=-1;
}
int dfs(int u,int t,int f){
    if(u==t) return f;
    int ret=0;
    for(int &i=cur[u];~i;i=nex[i]){
        int to=V[i],w=W[i],v=0;
        if(w>0&&d[to]==d[u]+1&&(v=dfs(to,t,min(f,w)))){
            W[i]-=v;W[i^1]+=v;
            f-=v;ret+=v;
            if(f<=0) break;
        }
    }
    return ret;
}
int Dinic(int s,int t){
    int ret=0;
    while(bfs(s,t)){
        for(int i=1;i<=n;i++) cur[i]=head[i];
        ret+=dfs(s,t,inf);
    }
    return ret;
}
int main(){
    init();
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        add(a,b,c);add(b,a,0);
    }
    cout<<Dinic(s,t)<<endl;
    return 0;
}


/*


网络流_Dinic


*/
