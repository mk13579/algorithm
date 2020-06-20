#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int tree[8*N]={0};
int n=0,m=0;
bool cmp=0;
void update(int rt,int L,int R,int pos,int v){
	if(L==R){
		tree[rt]=v;
		return;
	}
	int mid=(L+R)>>1;
	if(pos<=mid) update(2*rt,L,mid,pos,v);
	else update(2*rt+1,mid+1,R,pos,v);
	tree[rt]=max(tree[2*rt],tree[2*rt+1]);
}
int query(int rt,int L,int R,int l,int r){
	if(l<=L&&R<=r) return tree[rt];
	int mid=(L+R)>>1;
	int vl=0,vr=0;
	if(l<=mid) vl=query(2*rt,L,mid,l,r);
	if(mid<r) vr=query(2*rt+1,mid+1,R,l,r);
	return max(vl,vr);
}
int main(){
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;update(1,1,n,i,x);
	}
	while(m--){
		cin>>cmp;
		if(cmp){
			int pos,v;cin>>pos>>v;
			update(1,1,n,pos,v);
		}else{
			int l=0,r=0;cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
	}
	return 0;
} 


/*

线段树，单点更新区间求最大


*/
