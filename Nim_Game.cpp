#include<bits/stdc++.h>
using namespace std;
long long n=0,ret=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;cin>>x;
		ret^=x;	
	}
	if(ret) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

/*

有n堆物品，两人轮流取，每次取某堆中不少于1个，最后取完者胜。

*/ 
