#include<bits/stdc++.h>
using namespace std;
bool check(int x){
	if(x==2) return 1;
	if(x==1) return 0;
	if(x%2==0) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int main(){
	int n;cin>>n;
	if(check(n)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

/*

素数 


*/
