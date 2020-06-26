#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N]={0},b[N]={0};
int c[N]={0};
int n=0,m=0;
void DFT(int *a,int *b,int *c){
	memset(c,0,sizeof(c));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			c[i+j]+=a[i]*b[j];
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++) cin>>a[i];
	for(int i=0;i<=m;i++) cin>>b[i];
	DFT(a,b,c);
	for(int i=0;i<=n+m;i++) cout<<c[i]<<" ";cout<<endl;
	return 0;
} 


/*

传统离散DFT变换 


*/
