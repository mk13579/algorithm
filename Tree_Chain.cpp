#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int tot=0,head[N]={0},V[N]={0},W[N]={0},size[N]={0},son[N]={0},nex[N]={0},depth[N]={0},top[N]={0},vfa[N]={0};
int n=0,cnt=0,id[N]={0},a[N]={0};
const int inf = 1000000009;
void add(int x,int y){
    tot++;
    nex[tot]=head[x];V[tot]=y;
    head[x]=tot;
}
void update(int rt,int l,int r,int pos,int v){
    if(l==r){
        a[rt]+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(2*rt,l,mid,pos,v);
    else update(2*rt+1,mid+1,r,pos,v);
    a[rt]=a[2*rt]+a[2*rt+1];
}
int query(int rt,int l,int r,int L,int R){
    if(L<=l&&r<=R) return a[rt];
    int ret=0;
    int mid=(l+r)>>1;
    if(L<=mid) ret+=query(2*rt,l,mid,L,R);
    if(R>mid) ret+=query(2*rt+1,mid+1,r,L,R);
    return ret;
}
void Treeupdate(int rt,int v){
    update(1,1,n,id[rt],v);
}
int Treequery(int a,int b){
    int ret=0;
    while(top[a]!=top[b]){
        if(depth[top[a]]<depth[top[b]]) swap(a,b);
        ret+=query(1,1,n,id[top[a]],id[a]);
        a=vfa[top[a]];
    }
    if(depth[a]>depth[b]) swap(a,b);
    ret+=query(1,1,n,id[a],id[b]);
    return ret;
}
void dfs1(int rt,int fa){
    depth[rt]=depth[fa]+1;
    size[rt]=1;
    vfa[rt]=fa;
    for(int i=head[rt];i;i=nex[i]){
        int to=V[i];
        if(to==fa) continue;
        dfs1(to,rt);
        size[rt]+=size[to];
        if(size[son[rt]]<size[to]) son[rt]=to;
    }
}
void dfs2(int rt,int fa){
    id[rt]=++cnt;
    Treeupdate(rt,W[rt]);
    top[rt]=fa;
    if(son[rt]) dfs2(son[rt],fa);
    for(int i=head[rt];i;i=nex[i]) if(!id[V[i]]) dfs2(V[i],V[i]);
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        add(a,b);add(b,a);
    }
    for(int i=1;i<=n;i++) cin>>W[i];
    dfs1(1,0);
    dfs2(1,1);
    int m=0;cin>>m;
    while(m--){
        bool cmd=0;cin>>cmd;
        if(cmd){
            int x,v;cin>>x>>v;
            Treeupdate(x,v);
        }else{
            int a,b;cin>>a>>b;
            cout<<Treequery(a,b)<<endl;
        }
    }
    return 0;
}


/*

树链剖分算法


*/
