#include<iostream>
#include<cstdio>
#include<cmath>
#define N 105
using namespace std;
double a[N][N]={0};
double X[N]={0};
int n=0;
bool guess(){
    for(int i=1;i<=n;i++){
        int max_index=i;
        for(int j=i;j<=n;j++) if(a[j][i]>a[max_index][i]) max_index=j;
        if(fabs(a[max_index][i])<1e-5) return 0;
        for(int j=i;j<=n+1;j++) swap(a[i][j],a[max_index][j]);
        for(int j=1;j<=n;j++) if(j!=i) for(int k=n+1;k>=i;k--) a[j][k]-=a[j][i]/a[i][i]*a[i][k];
    }
    for(int i=1;i<=n;i++) X[i]=a[i][n+1]/a[i][i];
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n+1;j++) cin>>a[i][j];
    if(!guess()) cout<<"No Solution"<<endl;
    else for(int i=1;i<=n;i++) printf("%.2f\n",X[i]);
    return 0;
}
/*

高斯消元


*/
