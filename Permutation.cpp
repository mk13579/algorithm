#include<bits/stdc++.h>
using namespace std;
const int N = 103;
const long long mod = 1000000009;
bool vis[N]={0}; 
long long n=0,m=0;
int ans[N]={0};
void A(int pos){
	if(pos>m){
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[pos]=i;
			A(pos+1);
			vis[i]=0;
		}
	}
}
int main(){
	cin>>n>>m;
	A(1);
	return 0;
} 


/*

全排列 

*/
