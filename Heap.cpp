#include<bits/stdc++.h>
using namespace std;
int heap[1005]={0};
int sz=0;
void push(int x){
	int i=sz++;
	while(i>0){
		int p=(i-1)/2;
		if(heap[p]<=x) break;
		heap[i]=heap[p];
		i=p;
	}
	heap[i]=x;
}
int pop(){
	int ret=heap[0];
	int x=heap[--sz];
	int i=0;
	while(2*i+1<sz){
		int a=i*2+1,b=i*2+2;
		if(b<sz&&heap[b]<heap[a]) a=b;
		if(heap[a]>=x) break;
		heap[i]=heap[a];
		i=a;
	}
	heap[i]=x;
	return ret;
}
int top(){
	if(sz) return head[0];
	else return -1;
}
int main(){
	return 0;
} 

/*

手写小根堆

*/
