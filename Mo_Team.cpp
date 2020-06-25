#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
struct node{
	int l,r,id;
	int a,b;
};
node a[N];
int n=0,m=0;
int s[N]={0};
int c[N]={0};
int pos[N]={0};
int ans=0;
bool cmp1(node a,node b){
	if(pos[a.l]==pos[b.l]) return a.r<b.r;
	return a.l<b.r;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
void update(int x,int v){
	ans-=c[s[x]]*c[s[x]];
	c[s[x]]+=v;
	ans+=c[s[x]]*c[s[x]];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	int block=sqrt(n);
	for(int i=1;i<=n;i++) pos[i]=(i-1)/block+1;
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r;a[i].id=i;
	}
	sort(a+1,a+m,cmp1);
	for(int i=1,r=0,l=1;i<=m;i++){
		for(;r<a[i].r;r++) update(r+1,1);
		for(;r>a[i].r;r--) update(r,-1);
		for(;l<a[i].l;l++) update(l,-1);
		for(;l>a[i].l;l--) update(l-1,1);
		a[i].a=ans-(a[i].r-a[i].l+1);
        a[i].b=(a[i].r-a[i].l+1)*1LL*(a[i].r-a[i].l);
		int g=__gcd(a[i].a,a[i].b);
        a[i].a/=g;
        a[i].b/=g;
	}
	sort(a+1,a+m,cmp2);
	for(int i=1;i<=m;i++) cout<<a[i].a<<"/"<<a[i].b<<endl;
	return 0;
} 

/*

莫队算法 

*/
