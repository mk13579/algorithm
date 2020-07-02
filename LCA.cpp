#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int tot=0;
int head[N]={0},nex[N]={0},V[N]={0};
int fa[N][23]={0};
int d[N]={0};
int lg[N]={0};
int n=0,m=0;
void add(int x,int y){
    tot++;
    nex[tot]=head[x];V[tot]=y;
    head[x]=tot;
}
void dfs(int rt,int f){
    d[rt]=d[f]+1;
    fa[rt][0]=f;
    for(int i=1;(1<<i)<=d[rt];i++) fa[rt][i]=fa[fa[rt][i-1]][i-1];
    for(int i=head[rt];i;i=nex[i]){
        int to=V[i];
        dfs(to,rt);
    }
}
int lca(int a,int b){
    if(d[a]<d[b]) swap(a,b);
    while(d[a]>d[b]) a=fa[a][lg[d[a]-d[b]]];
    if(a==b) return a;
    for(int i=lg[d[a]];i>=0;i--) if(fa[a][i]!=fa[b][i]) a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        add(a,b);
    }
    dfs(1,0);
    while(m--){
        int x,y;cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
    return 0;
}


/*


倍增法求公共祖先


*/
