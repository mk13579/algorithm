#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1000000009;
int n=0;
int ans[N]={0};
int t=0;
struct node{
	int v;
	char id;
	node *next[2];
	node(){
		v=id=0;
		next[0]=next[1]=NULL;
	}
	friend bool operator < (const node a,const node b);
};
bool operator < (const node a,const node b){
	return a.v>b.v;
}
priority_queue<pair<int,node*> > que;
void Free(node *rt){
	if(rt==NULL) return;
	Free(rt->next[0]);Free(rt->next[1]);
	delete rt;
}
void print(node *root){
	if(root->next[0]){
		ans[++t]=0;
		print(root->next[0]);
		t--;
	}
	if(root->next[1]){
		ans[++t]=1;
		print(root->next[1]);
		t--;
	}
	if(root->next[0]==NULL&&root->next[1]==NULL){
		cout<<(root->id)<<":";
		for(int i=1;i<=t;i++) cout<<ans[i];
		cout<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char id;cin>>id>>x; 
		node *tmp=new node;
		tmp->v=x;tmp->id=id;
		que.push(make_pair(-x,tmp));
	}
	while(que.size()>1){
		pair<int,node*> ll=que.top();que.pop();
		pair<int,node*> rr=que.top();que.pop();
		node *l=ll.second,*r=rr.second;
		node *tmp=new node;
		tmp->v=l->v+r->v;
		tmp->next[0]=l;
		tmp->next[1]=r;
		que.push(make_pair(-(tmp->v),tmp));
	}
	pair<int,node*> tmp=que.top();que.pop();
	node *root=tmp.second;
	cout<<(root->v)<<endl;
	print(root);
	Free(root);
	return 0;
} 

/*

最优二叉树 


*/
