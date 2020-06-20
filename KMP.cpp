#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
char a[N],b[N];
int n=0,m=0;
int Next[N]={0};
void cal_next(char *p){
	int len=strlen(p+1);
	int i=1,j=0;
	Next[1]=0;
	while(i<=len){
		if(j==0||p[i]==p[j]) Next[++i]=++j;
		else j=Next[j];
	}
}
int KMP(char *a,char *b){
	int len=strlen(a+1);
	int mk=strlen(b+1);
	int ret=0,i=1,j=1;
	while(i<=len){
		if(j==0||a[i]==b[j]) i++,j++;
		else j=Next[j];
		if(j>=mk){
			ret++;j=Next[j];
		}
	}
	return ret;
}
int main(){
	cin>>a>>b;
	cal_next(b);
	cout<<KMP(a,b)<<endl;
	return 0;
}


/*

基础KMP，统计串个数 


*/
