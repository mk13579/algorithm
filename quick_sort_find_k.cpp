#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int a[N]={0};
int n=0,k=0;
int Sort(int *a,int l,int r,int k=0){
	if(r<=l) return a[l];
	int v=a[(l+r)>>1];
	int ll=l,rr=r;
	while(ll<=rr){
		while(a[ll]<v) ll++;
		while(a[rr]>v) rr--;
		if(ll<=rr) swap(a[ll++],a[rr--]);
	}
	int posl=rr-l+1,posr=ll-l;
	if(posl>=k) return Sort(a,l,rr,k);
	else if(k>posr) return Sort(a,ll,r,k-posr);
	else return a[(ll+rr)>>1];
}
int main(){
	cin>>n>>k;for(int i=1;i<=n;i++) cin>>a[i];
	cout<<Sort(a,1,n,k)<<endl;
	return 0;
} 


/*

快排找第K小 

*/
