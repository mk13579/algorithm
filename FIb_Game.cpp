#include<bits/stdc++.h>
using namespace std;
long long fib[50];
int main(){
	fib[0]=1;fib[1]=2;
	for(int i=2;i<45;i++) fib[i]=fib[i-1]+fib[i-2];
	int n;
	cin>>n;
	int i=0;
	for(i=0;i<45;i++) if(fib[i]==n) break;
	if(i<45)
		cout<<"Second win"<<endl;
	else
		cout<<"First win"<<endl;
	return 0;
}

/*

有一堆个数为n的石子，游戏双方轮流取石子，满足：

1)先手不能在第一次把所有的石子取完；

2)之后每次可以取的石子数介于1到对手刚取的石子数的2倍之间（包含1和对手刚取的石子数的2倍）。

约定取走最后一个石子的人为赢家，求必败态。

*/ 
