#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
const int inf = 1000000009;
int tot=0;
int n=0;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int size[N]={0};
int pos=0,Min=inf;
void add(int x,int y){
	tot++;
	nex[tot]=head[x];V[tot]=y;
	head[x]=tot;
}
void dfs(int rt,int fa){
	size[rt]=1;
	int Max=0;
	for(int i=head[rt];i;i=nex[i]){
		int to=V[i];
		if(to==fa) continue;
		dfs(to,rt);
		size[rt]+=size[to];
		Max=max(Max,size[to]);
	}
	Max=max(Max,n-size[rt]);
	if(Max<Min){
		pos=rt;
		Min=Max;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		add(x,y);add(y,x);
	}
	dfs(1,0);
	cout<<pos<<endl;
	return 0;
} 


/*


树的重心 

*/
