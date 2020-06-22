#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
const double inf = 1000000009;
const double eps= 1e-5;
double a[N];
int n=0;
double f(double x){
    double tmp=1.0;
    double ret=0;
    for(int i=0;i<=n;i++){
        ret+=a[i]*tmp;
        tmp*=x;
    }
    return ret;
}
int main(){
    cin>>n;
    for(int i=0;i<=n;i++) cin>>a[i];
    double l=-inf,r=inf;
    double midl=0,midr=0;
    while(fabs(r-l)>eps){
        midl=(l+r)/2,midr=(midl+r)/2;
        if(f(midl)<f(midr)) l=midl;
        else r=midr;
    }
    cout<<l<<endl;
    return 0;
}

/*

三分法找谷顶


*/
