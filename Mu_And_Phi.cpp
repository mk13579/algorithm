#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int mu[N]={0},phi[N]={0},Prime[N]={0},prime[N]={0}; 
int cnt=0;
void init() {
    Prime[1]=mu[1]=phi[1]=1;
    int cnt=0;
    for (int i=2;i<N;++i) {
        if (!Prime[i]) prime[++cnt]=i,mu[i]=-1,phi[i]=i-1;
        for (int j=1;j<=cnt&&i*prime[j]<N;++j) {
            Prime[i*prime[j]]=1;
            if (i%prime[j]) mu[i*prime[j]]=-mu[i],phi[i*prime[j]]=phi[i]*phi[prime[j]];
            else { mu[i*prime[j]]=0,phi[i*prime[j]]=phi[i]*prime[j]; break; }
        }
    }
}
int Phi(int x){
	int ret=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			ret*=(i-1);
			ret/=i;
		}
		while(x%i==0) x/=i;
	}
}
int Mu(int x){
	int ret=0;
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
			if(x%(i*i)==0) return 0;
			x/=i;
			ret++;
		}
	}
	if(ret&1) return -1;
	else return 1;
}
int main(){
	init();
	return 0;
}


/*

莫比乌斯和欧拉函数 

*/ 
