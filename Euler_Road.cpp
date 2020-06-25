#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int head[N]={0};
int nex[N]={0};
int V[N]={0};
int tot=0;
vector<pair<int,int> >ret;
int n=0,m=0;
void add(int x,int y){
	tot++;
	nex[tot]=head[x];V[tot]=y;
	head[x]=tot;
}
void dfs(int x){
	while(head[x]){
		int i=head[x];
		head[x]=nex[i];
		dfs(V[i]);
		ret.push_back(make_pair(x,V[i]));
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		add(a,b);
	}
	dfs(1);
	for(int i=ret.size()-1;i>=0;i--){
		cout<<ret[i].first<<" ";
	}
	cout<<ret[0].second<<endl;
	return 0;
}

/*

欧拉路 

*/
