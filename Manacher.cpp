#include<bits/stdc++.h>
using namespace std;
const int N =1000100;
int n,hw[N],ans;
char a[N],s[N<<1];
void manacher(){
    int maxright=0,mid;
    for(int i=1;i<n;i++){
        if(i<maxright) hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        else hw[i]=1;
        for(;s[i+hw[i]]==s[i-hw[i]];++hw[i]);
        if(hw[i]+i>maxright){
            maxright=hw[i]+i;
            mid=i;
        }
    }
}
void init(){
    s[0]=s[1]='#';
    for(int i=0;i<n;i++){
        s[i*2+2]=a[i];
        s[i*2+3]='#';
    }
    n=n*2+2;
    s[n]=0;
}
int main(){
    cin>>a;
    n=strlen(a);
    init();
    manacher();
    ans=1;
    for(int i=0;i<n;i++) ans=max(ans,hw[i]);
	cout<<ans-1<<endl;
    return 0;
}

/*

O(n)的最长回文串算法

*/
