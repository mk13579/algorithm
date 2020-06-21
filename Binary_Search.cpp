#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N]={0,1,1,3,3,5};
int Binary_Search_up(int *a,int l,int r,int v){//<=v最大的一个 
	int mid=0;
	l--;
	while(l<r){
		mid=(l+r+1)/2;
		if(a[mid]<=v) l=mid;
		else r=mid-1;
	}
	return l;
}
int Binary_Search_down(int *a,int l,int r,int v){//<v最大的一个 
	int mid=0;
	l--;
	while(l<r){
		mid=(l+r+1)/2;
		if(a[mid]>=v) r=mid-1;
		else l=mid;
	}
	return l;
}
int main(){
	cout<<Binary_Search_up(a,1,5,2)<<endl; 
	cout<<Binary_Search_down(a,1,5,2)<<endl; 
	return 0;
}

/*

二分查找两种写法 


*/
