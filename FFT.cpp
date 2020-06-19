#include<bits/stdc++.h>
#define N 100005
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-6;
struct complexx{
    double x,y;
    complexx(double xx=0,double yy=0){x=xx;y=yy;};
};
complexx operator + (complexx a,complexx b){return complexx(a.x+b.x,a.y+b.y);}
complexx operator - (complexx a,complexx b){return complexx(a.x-b.x,a.y-b.y);}
complexx operator * (complexx a,complexx b){return complexx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
void fft(int len,complexx *a,int o){
    if(len==1) return;
    complexx l[(len>>1)+3],r[(len>>1)+3];
    for(int i=0;i<=len;i+=2) l[i>>1]=a[i],r[i>>1]=a[i+1];
    fft(len>>1,l,o);fft(len>>1,r,o);
    complexx wn=complexx(cos(2*pi/len),o*sin(2*pi/len)),w0=complexx(1,0);
    for(int i=0;i<(len>>1);i++,w0=w0*wn){
        a[i]=l[i]+w0*r[i];
        a[i+(len>>1)]=l[i]-w0*r[i];
    }
}
complexx a[N],b[N];
int n=0,m=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>a[i].x;
    for(int i=0;i<=m;i++) cin>>b[i].x;
    int len=1;
    for(;len<=n+m;len<<=1);
    fft(len,a,1);fft(len,b,1);
    for(int i=0;i<=len;i++) a[i]=a[i]*b[i];
    fft(len,a,-1);
    for(int i=0;i<=n+m;i++) cout<<setiosflags(ios::fixed)<<setprecision(0)<<a[i].x/len+eps<<" ";
    return 0;
}


/*
多项式乘法
输入：a,b多项式次数，系数
输出：乘后的结果
*/