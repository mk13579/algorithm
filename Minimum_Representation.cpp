#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
char s[N];
int n=0;
int Min_re(char *s){
	int i=1,j=2;
	int k=0;
	while(i<=n&&j<=n&&k<=n){
		int t=s[i+k]-s[j+k];
		if(!t) k++;
		else{
			if(t>0) i+=k+1;
			else j+=k+1;
			if(i==j) j++;
			k=0;
		} 
	}
	return min(i,j);
}
int main(){
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=n+1;i<=2*n;i++) s[i]=s[i-n];
	s[2*n+1]='\0';
	int mk=Min_re(s);
	for(int i=0;i<n;i++) cout<<s[mk+i];cout<<endl;
	return 0;
}

/*

最小表示法 

*/
