#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int MOD = 76543;
int head[N]={0},nex[N]={0},V[N]={0},id[N]={0};
int tot=0;
void add(int x,int y){
	int k=x%MOD;
	tot++;
	nex[tot]=head[k];V[tot]=x;id[tot]=y;
	head[k]=tot;
}
int find(int x){
	int k=x%MOD;
	for(int i=head[k];i;i=nex[i]) if(V[i]==x) return id[i];
	return -1;
}
int BSGS(int a,int b,int p){
	if(b==1) return 0;
	int m=sqrt(p*1.0),tmp=1,x=1,j=0;
	for(int i=0;i<m;i++,tmp=tmp*a%p) add(b*tmp%p,i);
	for(int i=m;i<=p;i+=m) if((j=find(x=x*tmp%p))!=-1) return i-j; 
	return -1;
}
int main(){
	int a,b,p;
	cin>>a>>b>>p;
	cout<<BSGS(a,b,p)<<endl;
	return 0;
}


/*

BSGS算法 

*/
