#include<bits/stdc++.h>
using namespace std;
long long w=0;
long long pow1(long long a,long long b,long long p){
    long long ret=1%p;
    while(b){
        if(b&1) ret=ret*a%p;
        a=a*a%p;b>>=1;
    }
    return ret;
}
pair<long long,long long> mul(pair<long long,long long> a,pair<long long,long long> b,long long p){
    pair<long long,long long> ret;
    ret.first=(a.first*b.first%p+a.second*b.second%p*w%p)%p;
    ret.second=(a.first*b.second%p+a.second*b.first%p)%p;
    return ret;
}
pair<long long,long long> pow2(pair<long long,long long> a,long long b,long long p){
    pair<long long,long long> ret=make_pair(1,0);
    while(b){
        if(b&1) ret=mul(ret,a,p);
        b>>=1;a=mul(a,a,p);
    }
    return ret;
}
long long n,p;
int main(){
    cin>>n>>p;
    if(pow1(n,(p-1)/2,p)==p-1) cout<<-1<<endl;
    else{
        long long x=0;
        while(1){
            x=rand()%p;
            w=(x*x%p-n)%p;w+=p;w%=p;
            if(pow1(w,(p-1)/2,p)==p-1) break; 
        }
        pair<long long,long long> ret=make_pair(x,1);
        long long ans1=pow2(ret,(p+1)/2,p);
        long long ans2=(p-ans1)%p;ans2+=p;ans2%=p;
        if(ans1>ans2) swap(ans1,ans2);
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}


/*

二次剩余


*/
