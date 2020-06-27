#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
struct node{
	int id;
	int v;
	bool mk;
	int x,y,z;
	node(int _x=0,int _y=0,int _z=0){
		x=_x;y=_y;z=_z;
		mk=0;
	}
	bool operator == (node a){
		return x==a.x&&y==a.y&&z==a.z;
	}
}a[N],b[N],c[N];
int n=0;
bool cmp(node a,node b){
	if(a.x==b.x){
		if(a.y==b.y) return a.z<b.z;
		return a.y<b.y;
	}
	return a.x<b.x;
}
bool cmp1(node a,node b){
	return a.id<b.id;
}
void merge2(node *b,int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	merge2(b,l,mid);
	merge2(b,mid+1,r);
	int i=l,j=mid+1;
	int t=l;
	int sum=0;
	while(i<=mid&&j<=r){
		if(b[i].z<=b[j].z){
			c[t]=b[i++];sum+=c[t].mk;t++;
		}else{
			c[t]=b[j++];c[t].v+=sum;t++;
		}
	}
	while(i<=mid){
		c[t]=b[i++];sum+=c[t].mk;t++;
	}
	while(j<=r){
		c[t]=b[j++];c[t].v+=sum;t++;
	}
	for(int i=l;i<=r;i++) b[i]=c[i];
}
void merge1(node *a,int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	merge1(a,l,mid);
	merge1(a,mid+1,r);
	int i=l,j=mid+1;
	int t=l;
	while(i<=mid&&j<=r){
		if(a[i].y<=a[j].y){
			b[t]=a[i++];b[t].mk=1;t++;	
		}else{
			b[t]=a[j++];b[t].mk=0;t++;
		}
	}
	while(i<=mid){
		b[t]=a[i++];b[t].mk=1;t++;
	}
	while(j<=r){
		b[t]=a[j++];b[t].mk=0;t++;
	}
	for(int i=l;i<=r;i++) a[i]=b[i];
	merge2(b,l,r);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;a[i].v=0;a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=n-1;i>=1;i--) if(a[i]==a[i+1]) a[i].v=a[i+1].v+1;
	merge1(a,1,n);
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n;i++) cout<<c[i].v<<endl;
	return 0;
} 

/*

三维偏序的CDQ 


*/
