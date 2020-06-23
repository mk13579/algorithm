#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[N]={0};
int b[N]={0};
int n=0;
int merge(int *a,int l,int r){
	int ret=0;
	int mid=(l+r)>>1;
	int i=l,j=mid+1;
	int t=l;
	while(i<=mid&&j<=r){
		if(a[i]>a[j]){
			b[t++]=a[j++];
			ret+=mid-i+1;
		}else b[t++]=a[i++];
	}
	while(i<=mid) b[t++]=a[i++];
	while(j<=r) b[t++]=a[j++];
	for(int i=l;i<=r;i++) a[i]=b[i];
	return ret;
}
int merge_sort(int *a,int l,int r){
	if(l==r) return 0;
	int mid=(l+r)>>1;
	int ret=0;
	ret+=merge_sort(a,l,mid);
	ret+=merge_sort(a,mid+1,r);
	ret+=merge(a,l,r);
	return ret;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<merge_sort(a,1,n)<<endl;
	return 0;
} 


/*

归并排序求逆序数 

*/
