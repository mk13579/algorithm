#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int tot=0;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int DNF[N]={0},LOW[N]={0};
int index=0;
int t=0;
stack<int> s;
int father[N]={0};
void init(){
	tot=0;
	memset(head,0,sizeof(head));
	memset(nex,0,sizeof(nex));
	memset(V,0,sizeof(V));
}
void add(int x,int y){
	tot++;
	nex[tot]=head[x];V[tot]=y;
	head[x]=tot;
}
void tarjan(int rt){
	DNF[rt]=LOW[rt]=++index;
	s.push(rt);
	for(int i=head[rt];i;i=nex[i]){
		int to=V[i];
		if(!DNF[to]){
			tarjan(to);
			LOW[rt]=min(LOW[rt],LOW[to]);
		}else LOW[rt]=min(LOW[rt],LOW[to]);
	}
	if(DNF[rt]==LOW[rt]){
		++t;
		while(s.size()&&s.top()!=rt){
			father[s.top()]=t;s.pop();
		}
		if(s.size()){
			father[rt]=t;s.pop();
		}
	}
}
int n=0,m=0;
int main(){
	cin>>n>>m;
	init();
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		add(a,b);
	}
	for(int i=1;i<=n;i++) if(!DNF[i]) tarjan(i);
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<father[i]<<endl;
	}
	return 0;
} 

/*

tarjan算法缩点

*/
