#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const double eps= 1e-7;
double ansx=0,ansy=0,answ=0;
struct node{
    double x,y,w;
    node(double a=0,double b=0,double c=0){
        x=a;y=b;w=c;
    }
};
node a[N];
int n=0;
double cal(double x,double y){
    double rt=0.0;
    for(int i=1;i<=n;i++){
        rt+=sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y))*a[i].w;
    }
    return rt;
}
void sa(double x,double y){
    double T=2000.0;
    while(T>eps){
        double X=x+(rand()<<1-RAND_MAX)*T;
        double Y=y+(rand()<<1-RAND_MAX)*T;
        double now = cal(X,Y);
        double Delta=now-answ;
        if(Delta<0){
            ansx=X;ansy=Y;answ=now;
            x=X;y=Y;
        }else if(exp(-Delta/T)*RAND_MAX>rand()) x=X,y=Y;
        T*=0.98;
    }
}
double sumx=0,sumy=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].w;
        sumx+=a[i].x;sumy+=a[i].y;
    }
    ansx=sumx/n;ansy=sumy/n;answ=cal(ansx,ansy);
    for(int i=0;i<10;i++) sa(ansx,ansy);
    cout<<ansx<<" "<<ansy<<endl;

    return 0;
}

/*


模拟退火，系统中能量最低. 


*/
