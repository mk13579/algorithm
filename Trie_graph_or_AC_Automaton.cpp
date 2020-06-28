#include<bits/stdc++.h>
using namespace std;
const int N = 1133;
struct node{
	node * next[30];
	int v;
	node *fail;
	char z;
	node(){
		memset(next,0,sizeof(next));
		fail=NULL;
		v=0;
	}
};
node *root=NULL;
void insert(node *rt,char *s){
	node *tmp=rt;
	for(int i=0;s[i];i++){
		int y=s[i]-'a';
		if(tmp->next[y]==NULL) tmp->next[y]=new node;
		tmp=tmp->next[y];tmp->z=s[i];
	}
	tmp->v++;
}
void build(node *rt){
	queue<node *> que;
	for(int i=0;i<26;i++){
		if(rt->next[i]){
			rt->next[i]->fail=rt;que.push(rt->next[i]);
		}else{
			rt->next[i]=rt;	rt->next[i]->fail=rt;
		}
	}		
	while(que.size()){
		node *tmp=que.front();que.pop();
		for(int i=0;i<26;i++){
			if(tmp->next[i]){
				tmp->next[i]->fail=tmp->fail->next[i];
				que.push(tmp->next[i]);
			}else{
				tmp->next[i]=tmp->fail->next[i];
			} 
		}
	}
}
int query(node *rt,char *s){
	node *tmp=rt;
	int ret=0;
	for(int i=0;s[i];i++){
		int y=s[i]-'a';
		node *mk=tmp->next[y];
		while(mk->v!=-1){
			ret+=mk->v;mk->v=-1;
			mk=mk->fail; 
		}
		tmp=tmp->next[y];
	}
	return ret;
}
void Free(node *rt){
	if(rt==NULL) return;
	for(int i=0;i<26;i++) Free(rt->next[i]);
	delete rt;
}
char str[N];
int main(){
	root=new node;root->fail=root;
	int n=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str;
		insert(root,str);
	}
	build(root);
	cin>>str;
	cout<<query(root,str)<<endl;
	return 0;
} 


/*

trie图算法 & 确定形式AC自动机算法 


*/
