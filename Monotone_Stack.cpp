#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
stack<int> st;
int a[N]={0};
int l[N]={0},r[N]={0};
int n=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		while(st.size()&&a[st.top()]>a[i]){
			r[st.top()]=i-1;st.pop();
		}
		if(st.empty()||a[st.top()]<=a[i]) st.push(i);
	}
	while(st.size()){
		r[st.top()]=n;
		st.pop();
	}
	
	for(int i=n;i>=1;i--){
		while(st.size()&&a[st.top()]>a[i]){
			l[st.top()]=i+1;st.pop();
		}
		if(st.empty()||a[st.top()]<=a[i]) st.push(i);
	}
	while(st.size()){
		l[st.top()]=1;
		st.pop();
	}
	
	for(int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<endl;
	return 0;
} 


/*


单调队列应用，以i为最小左右扩多少 

*/
