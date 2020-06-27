#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0;
int main(){
	cin>>n>>m;
	if(n%(1+m)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
} 



/*

一堆n个物品，两个人轮流从中取出1~m个，最后取光者胜

*/ 
