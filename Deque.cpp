#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int q[N]={0};
int a[N]={0};
int n=0;
int k=0;
int l=0,r=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		while(l!=r&&a[q[r]]>=a[i]) r--;
		if(l==r||a[i]>=a[q[r]]) q[++r]=i;
		while(l!=r&&q[l+1]<i-k+1) ++l;
		if(i>=k) cout<<a[q[l+1]]<<endl; 
	}
	return 0;
} 

/*

K区间最小，滑动窗口,基于双端队列 


*/
