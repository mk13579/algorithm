#include<bits/stdc++.h>
using namespace std;
int Add(int x,int y){
	return x+y;
}
int Sub(int x,int y){
	return x-y;
}
int Mul(int x,int y){
	return x*y;
}
int Div(int x,int y){
	if(y==0) return -10000;
	return x/y;
}
int (*op[4])(int,int)={Add,Sub,Mul,Div};
bool mk(int a,int b,int c,int d){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
                int ret = op[k](op[j](op[i](a, b), c) , d);
                if(ret == 24) return true;
                ret = op[k](op[j](a, op[i](b, c)) , d);
                if(ret == 24) return true;
                ret = op[k](a, op[j](op[i](b, c) , d));
                if(ret == 24) return true;
                   ret = op[k](op[i](a, b), op[j](c, d));
                if(ret == 24) return true;
                ret = op[k](a, op[j](b, op[i](c, d)));
                if(ret == 24) return true;
			}
		}
	}
}
int main(){
	int a=0,b=0,c=0,d=0;
	cin>>a>>b>>c>>d;
	cout<<mk(a,b,c,d)<<endl;
	return 0;
}


/*


24点问题 

*/
