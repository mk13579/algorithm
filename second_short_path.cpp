#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1000000009;
int dis1[N]={0},dis2[N]={0};
int tot=0;
int head[N]={0},nex[N]={0},V[N]={0},W[N]={0};
void add(int x,int y,int c){
	tot++;
	nex[tot]=head[x];V[tot]=y;W[tot]=c;
	head[x]=tot;
}
int n=0,m=0;
void Dij_second(int x){
	priority_queue<pair<int,int> >que;
	for(int i=0;i<=n;i++) dis1[i]=dis2[i]=inf;
	dis1[x]=0; 
	que.push(make_pair(0,x));
	while(que.size()){
		pair<int,int> tmp=que.top();que.pop();
		int v=tmp.second,d=-tmp.first;
		if(dis2[v]<d) continue;
		for(int i=head[v];i;i=nex[i]){
			int to=V[i],w=W[i];
			if(dis1[to]>d+w){
				dis2[to]=dis1[to];
				dis1[to]=d+w;
				que.push(make_pair(-dis1[to],to));
			}else if(dis2[to]>d+w){
				dis2[to]=d+w;
				que.push(make_pair(-dis2[to],to));
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,c;cin>>x>>y>>c;
		add(x,y,c);add(y,x,c);
	}
	Dij_second(1);
	cout<<dis2[n]<<endl;
	return 0;
}

/*

次短路 

*/
