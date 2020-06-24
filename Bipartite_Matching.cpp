#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int tot=0;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
bool vis[N]={0};
int fa[N]={0};
int n=0,m=0;
void add(int x,int y){
	tot++;
	nex[tot]=head[x];V[tot]=y;
	head[x]=tot;
}
bool find(int x){
	for(int i=head[x];i;i=nex[i]){
		int to=V[i];
		if(!vis[to]){
			vis[to]=1;
			if(!fa[to]||find(fa[to])){
				fa[to]=x;
				return 1;
			}
		}
	}
	return 0;
}
int match(){
	int ret=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(find(i)) ret++;
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		add(x,y+n);
	}
	cout<<match()<<endl;
	return 0;
}

/*

基于匈牙利算法的二分匹配 

*/
