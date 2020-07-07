#include<bits/stdc++.h>
using namespace std;
int ok(int n,int k){
    if(n==1) return 0;
    return (ok(n-1,k)+k+1)%n;
}
int main(){
    int n=0,k=0;
    cin>>n>>k;
    cout<<ok(n,k)+1<<endl;
    return 0;
}

/*

约瑟夫问题最后一个人编号


*/
