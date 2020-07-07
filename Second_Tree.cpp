#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int inf = 1000000009;
int cost[N][N]={0};
int pre[N]={0};
bool vis[N]={0};
bool used[N][N]={0};
int dis[N]={0};
int Max[N][N]={0};
int n=0,m=0;
int ret=0;
int Prim(){
    int sum=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++) dis[i]=inf;
    dis[1]=0;
    while(1){
        int v=-1;
        for(int i=1;i<=n;i++) if(!vis[i]&&(v==-1||dis[v]>dis[i])) v=i;
        if(v==-1) break;
        vis[v]=1;used[v][pre[v]]=used[pre[v]][v]=1;
        sum+=dis[v];
        for(int i=1;i<=n;i++){
            if(vis[i]) Max[v][i]=Max[i][v]=max(Max[i][pre[v]],dis[v]);
            if(!vis[i]&&dis[i]>cost[v][i]){
                dis[i]=cost[v][i];
                pre[i]=v;
            }
        }
    }
    return sum;
}
int second_Prim(int sum){
    int ret=inf;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(!used[i][j]) ret=min(ret,sum-Max[i][j]+cost[i][j]);
    return ret;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cost[i][j]=inf;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        cost[a][b]=cost[b][a]=c;
    }
    ret=Prim();
    ret=second_Prim(ret);
    cout<<ret<<endl;
    return 0;
}

/*

次小生成树


*/
