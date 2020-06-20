#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int tree[8*N]={0};
int lazy[8*N]={0};
void push(int rt,int L,int R){
	int mid=(L+R)>>1;
	lazy[2*rt]+=lazy[rt];lazy[2*rt+1]+=lazy[rt];
	tree[2*rt]+=lazy[rt]*(mid-L+1);tree[2*rt+1]+=lazy[rt]*(R-mid);
	lazy[rt]=0;
}
int n=0,m=0;
bool cmp=0;
void update(int rt,int L,int R,int l,int r,int v){
	push(rt,L,R);
	if(l<=L&&R<=r){
		tree[rt]+=v*(R-L+1);
		lazy[rt]+=v;
		return;
	}
	int mid=(L+R)>>1;
	if(r<=mid) update(2*rt,L,mid,l,r,v);
	else if(mid<l) update(2*rt+1,mid+1,R,l,r,v);
	else{
		update(2*rt,L,mid,l,mid,v);
		update(2*rt+1,mid+1,R,mid+1,r,v);
	}
	tree[rt]=tree[2*rt]+tree[2*rt+1];
}
int query(int rt,int L,int R,int l,int r){
	push(rt,L,R);
	if(l<=L&&R<=r) return tree[rt];
	int mid=(L+R)>>1;
	int vl=0,vr=0;
	if(r<=mid) return query(2*rt,L,mid,l,r);
	else if(mid<l) return query(2*rt+1,mid+1,R,l,r);
	else return query(2*rt,L,mid,l,mid)+query(2*rt+1,mid+1,R,mid+1,r);
}
int main(){
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;update(1,1,n,i,i,x);
	}
	while(m--){
		cin>>cmp;
		if(cmp){
			int l,r,v;cin>>l>>r>>v;
			update(1,1,n,l,r,v);
		}else{
			int l=0,r=0;cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
	}
	return 0;
} 


/*

线段树区间修改，区间求和 

*/
