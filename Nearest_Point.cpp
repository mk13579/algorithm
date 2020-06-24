#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const double inf = 1000000009;
int n=0;
struct node{
	double x,y;
};
node point[N];
int tmp[N]={0};
bool cmpx(const node &a,const node &b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmpy(int x,int y){
	return point[x].y<point[y].y;
}
double dis(const node &a,const node &b){
	double x = (a.x - b.x) * (a.x - b.x);
    double y = (a.y - b.y) * (a.y - b.y);
    return sqrt(x + y);
}
double merge(const node *a,int l,int r){
	int mid=(l+r)>>1;
	int t=0;
	double d=inf;
	if(l==r) return d;
	else if(l+1==r) return dis(a[l],a[r]);
	d=min(merge(a,l,mid),merge(a,mid+1,r));
	for(int i=l;i<=r;i++) if(fabs(a[i].x-a[mid].x)<d) tmp[++t]=i;
	sort(tmp+1,tmp+t,cmpy);
	for(int i=1;i<=t;i++){
		for(int j=i+1;j<=t;j++){
			if(fabs(point[tmp[i]].y-point[tmp[j]].y)>d) break;
			d=min(d,dis(point[tmp[i]],point[tmp[j]]));
		}
	}
	return d;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>point[i].x>>point[i].y;
	sort(point+1,point+1+n,cmpx);
	cout<<merge(point,1,n)<<endl;
	return 0;
} 


/*

平面分治最近点 


*/ 
