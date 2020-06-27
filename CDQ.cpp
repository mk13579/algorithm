#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 100010
using namespace std;
int n,k,ans[maxn]={0},d[maxn]={0};
struct node{
    int x,y,z;
    bool b;
    int *ans;
    inline void get(){
        scanf("%d%d%d",&x,&y,&z);
        return;
    }
    bool operator==(const node &a) const{
        return x==a.x&&y==a.y&&z==a.z;
    }
}a[maxn],b[maxn],c[maxn];
inline bool cmp(const node &a, const node &b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y)||(a.x==b.x&&a.y==b.y&&a.z<b.z);
}
void merge2(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    merge2(l,mid);
    merge2(mid+1,r);
    for(int i=l,j=l,k=mid+1,cnt=0;i<=r;++i){
        if((k>r||b[j].z<=b[k].z)&&j<=mid) c[i]=b[j++],cnt+=c[i].b;
        else{
            c[i]=b[k++];
            if(!c[i].b)*c[i].ans+=cnt;
        }
    }
    for(int i=l;i<=r;++i)b[i]=c[i];
}
void merge1(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    merge1(l,mid);
    merge1(mid+1,r);
    for(int i=l,j=l,k=mid+1;i<=r;++i){
        if((k>r||a[j].y<=a[k].y)&&j<=mid) b[i]=a[j++],b[i].b=1;
        else b[i]=a[k++],b[i].b=0;
    }
    for(int i=l;i<=r;++i)a[i]=b[i];
    merge2(l,r);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) a[i].get(),a[i].ans=&ans[i],ans[i]=0;
    sort(a+1,a+n+1,cmp);
    for(int i=n-1;i;--i) if(a[i]==a[i+1]) *a[i].ans=*a[i+1].ans+1;
    merge1(1,n);
    for(int i=1;i<=n;++i) ++d[ans[i]];
    for(int i=0;i<n;++i) printf("%d\n",d[i]);
    return 0;
}
/*


CDQ分治


*/ 
