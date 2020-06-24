#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
double f(double x){
	return x*x;
}
double simpson(double l,double r){
	return (f(l)+f(r)+4*f((r+l)/2))*(r-l)/6;
}
double cal(double l,double r,double ans){
	double mid=(l+r)/2;
	double _l=simpson(l,mid),_r=simpson(mid,r);
	if(fabs(_l+_r-ans)<=eps) return _l+_r;
	else return cal(l,mid,_l)+cal(mid,r,_r);
}
int main(){
	double l,r;cin>>l>>r;
	cout<<cal(l,r,0)<<endl;
	return 0;
}

/*

积分 f(x) [l,r] = (r-l)*(f(l)+f(r)+4*((l+r)/2)/6) 


计算积分的辛普森公式， 通过二分的方法逼近精度 

*/
