#include<bits/stdc++.h>
using namespace std;
const int N = 1002;
const int M = 2002;
const int inf = 1000000009;
int n=0,m=0;
struct edge{
	int x,y;
	int v;
};
edge E[M];
int father[N]={0};
bool cmp(edge a,edge b){
	return a.v<b.v;
}
void init(){
	for(int i=0;i<N;i++) father[i]=i;
}
int find(int x){
	if(father[x]==x) return x;
	return father[x]=find(father[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	father[x]=y;
}
bool same(int x,int y){
	return find(x)==find(y);
}
int Kruskal(){
	init();
	int ret=0;
	for(int i=1;i<=m;i++){
		if(!same(E[i].x,E[i].y)){
			merge(E[i].x,E[i].y);
			ret+=E[i].v;
		}
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y,c;i<=m;i++){
		cin>>E[i].x>>E[i].y>>E[i].v;
	}
	sort(E+1,E+1+m,cmp);
	cout<<Kruskal()<<endl;
	return 0;
}


/*

基于 Kruskal最小生成树 

*/ 
