#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
const int inf = 1e9;
int a[N]={0},b[N]={0},c[N]={0};
int t=0;
int dis[N]={0};
int n=0,m=0;
void add(int x,int y,int v){
	t++;
	a[t]=x;b[t]=y;c[t]=v;
}
bool Bellman_ford(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		bool mk=1;
		for(int j=1;j<=t;j++){
			if(dis[b[i]]>dis[a[i]]+c[i]){
				dis[b[i]]=dis[a[i]]+c[i];
				mk=0;
			}
		}
		if(i>=n&&!mk) return 1;
		if(mk) break;
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		add(a,b,c);
	}
	cout<<Bellman_ford()<<endl;
	return 0;
} 

/*

Bellman_ford解决负环问题 

*/
