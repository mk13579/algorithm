#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0;
int main(){
	double r=(sqrt(5)+1)/2;
	long long d=abs(n-m)*r;
	if(d==min(n,m)) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
} 



/*

有两堆各若干物品，两个人轮流从任意一堆中至少取出一个或者从两堆中取出同样多的物品，规定每次至少取一个，至多不限，最后取光者胜。

*/ 
