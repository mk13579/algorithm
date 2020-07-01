#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
struct node{
	double x,y;
};
stack<int> s;
node p[N];
int n=0;
double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double CL(node a1,node a2,node b1,node b2){
	return (a2.x-a1.x)*(b2.y-b1.y)-(a2.y-a1.y)*(b2.x-b1.x);
}
bool cmp(node a,node b){
	int tmp=CL(p[1],a,p[1],b);
	if(tmp>0) return 1;
	if(tmp==0&&dis(p[0],a)<dis(p[0],b)) return 1;
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		if(p[i].y<p[1].y) swap(p[i],p[1]);
	}
	s.push(1);
	sort(p+2,p+1+n,cmp);
	for(int i=2;i<=n;i++){
		while(s.size()>1&&CL(p[s.top()-1],p[s.top()],p[s.top()],p[i])<0) s.pop();
		s.push(i);
	}
	while(s.size()){
		int index=s.top();s.pop();
		cout<<p[index].x<<" "<<p[index].y<<endl;
	}
	return 0;
}

/*


求凸包 

*/
