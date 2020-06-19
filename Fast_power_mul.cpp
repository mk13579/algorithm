#include<bits/stdc++.h>
using namespace std;
long long pow(long long a,long long b,long long p){
    long long ret=1%p;
    a%=p;
    while(b){
        if(b&1) ret=ret*a%p;
        a=a*a%p;b>>=1;
    }
    return ret;
}
long long mul(long long a,long long b,long long p){
    long long sum=0;
    while(b){
        if(b&1) sum=(sum+a)%p;
        a=(a+a)%p;b>>=1;
    }
    return sum;
}
int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    cout<<pow(a,b,p)<<endl;
    cout<<mul(a,b,p)<<endl;
    return 0;
}

/*

快速计算幂次和乘法

*/