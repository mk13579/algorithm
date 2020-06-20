#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
const int N = 1005;
const int M = 1005;
int a[N][M]={0};
void add(int x,int y,int v){
	for(int i=x;i<N;i+=lowbit(i))
		for(int j=y;j<M;j+=lowbit(j)) a[i][j]+=v;
}
int _sum(int x,int y){
	int ret=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j)) ret+=a[i][j];
	return ret;
}
int sum(int x1,int y1,int x2,int y2){
	return _sum(x2,y2)+_sum(x1-1,y1-1)-_sum(x2,y1-1)-_sum(x1-1,y2);
}
int main(){
	int n=0;cin>>n;
	for(int i=1,x=0,y=0;i<=n;i++){
		cin>>x>>y;add(x,y,1);
	}
	cout<<sum(1,1,10,10)<<endl;
	return 0;
}


/*

¶þÎ¬Ê÷×´Êý×é 


*/
