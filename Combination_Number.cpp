#include<bits/stdc++.h>
using namespace std;
const int N = 103;
const long long mod = 1000000009;
int ans[N]={0};
int t=0;
bool vis[N]={0};
int n=0,m=0;
void C(int pos,int num=-1){
	if(num!=-1) if(n-pos+1+t<num||t>m) return;
	if(pos>n){
		for(int i=1;i<=t;i++) cout<<ans[i]<<" ";if(t) cout<<endl;
		return;
	}
	C(pos+1,num);
	ans[++t]=pos;
	C(pos+1,num);
	--t;
}
int main(){
	cin>>n>>m;
	C(1);
	cout<<"------"<<endl;
	C(1,m);
	return 0;
} 


/*

组合数 

*/
