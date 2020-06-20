#include<bits/stdc++.h>
using namespace std;
struct node{
	node * next[30];
	int v;
	node(){
		memset(next,0,sizeof(next));
		v=0;
	}
};
void insert(node *rt,char *str){
	node *tmp=rt;
	for(int i=0;str[i];i++){
		int y=str[i]-'a';
		if(tmp->next[y]==NULL) tmp->next[y]=new node;
		tmp=tmp->next[y];
	}
	tmp->v++;
}
int find(node *rt,char *str){
	node *tmp=rt;
	for(int i=0;str[i];i++){
		int y=str[i]-'a';
		if(tmp->next[y]==NULL) return 0;
		tmp=tmp->next[y];
	}
	return tmp->v;
}
void Free(node *rt){
	if(rt==NULL) return;
	for(int i=0;i<30;i++) Free(rt->next[i]);
	delete rt;
}
node *root=new node;
int n=0;
char str[123];
bool cmd;
int main(){
	cin>>n;
	while(n--){
		cin>>cmd>>str;
		if(cmd) cout<<find(root,str)<<endl;
		else insert(root,str);
	}
	Free(root);
	return 0;
} 

/*

字典树，实现插入和查找操作 


*/
