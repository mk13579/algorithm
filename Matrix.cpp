#include<bits/stdc++.h>
using namespace std;
const int N = 51;
const int M = 51;
class Matrix{
private:
    int v[N][M];
public:
    int n,m;
    Matrix(int _n,int _m){
        n=_n;m=_m;
        memset(v,0,sizeof(v));
    }
    int get(int x,int y){
        return v[x][y];
    }
    void set(int x,int y,int c){
        v[x][y]=c;
    }
    void Z_(){
        memset(v,0,sizeof(v));
    }
    void E_(){
        if(n!=m) return;
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++) set(i,i,1);
    }
    void display(){
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
	}
    friend Matrix operator * (Matrix &a,Matrix &b);
    friend Matrix operator ^ (Matrix a,int b);
    friend Matrix operator + (Matrix &a, Matrix &b);
    friend Matrix operator - (Matrix &a, Matrix &b);
};
Matrix operator * (Matrix &a,Matrix &b){
    Matrix tmp(a.n,b.m);
    for(int i=1;i<=tmp.n;i++){
        for(int j=1;j<=tmp.m;j++){
            int sum=0;
            for(int k=1;k<=a.m;k++){
                sum+=a.get(i,k)*b.get(k,j);
            }
            tmp.set(i,j,sum);
        }
    }
    return tmp;
}
Matrix operator ^ (Matrix a,int b){
    if(a.n!=a.m) exit(0);
    Matrix ret(a.n,a.n);ret.E_();
    while(b){
        if(b&1) ret=ret*a;
        a=a*a;b>>=1;
    }
    return ret;
}
Matrix operator + (Matrix &a, Matrix &b){
    if(a.n!=b.n||a.m!=b.m) exit(0);
    Matrix ret(a.n,a.m);
    for(int i=1;i<=a.n;i++){
        for(int j=1;j<=a.m;j++){
            ret.set(i,j,a.get(i,j)+b.get(i,j));
        }
    }
    return ret;
}
Matrix operator - (Matrix &a, Matrix &b){
    if(a.n!=b.n||a.m!=b.m) exit(0);
    Matrix ret(a.n,a.m);
    for(int i=1;i<=a.n;i++){
        for(int j=1;j<=a.m;j++){
            ret.set(i,j,a.get(i,j)-b.get(i,j));
        }
    }
    return ret;
}
int main(){
	Matrix mk(2,2);
	mk.E_();
	mk.set(1,1,1);
	mk.set(1,2,1);
	mk.set(2,1,1);
	mk.set(2,2,1);
	Matrix c331=mk+mk;c331.display();
	Matrix c332=mk-mk;c332.display();
	Matrix c333=mk*mk;c333.display();
	Matrix c334=mk^4;c334.display();
    return 0;
}

/*

矩阵类,包含基础矩阵操作

*/
