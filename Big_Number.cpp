#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
class Bignumber{
private:
	vector<short> v;
	bool sign;
	void trim();
public:
	Bignumber(int val);
	Bignumber(string val);
	Bignumber(char *val);
	Bignumber();
	Bignumber operator=(const Bignumber& a);
	
	void abs();
	void display(); 

	friend Bignumber operator+(Bignumber &a,Bignumber &b);
	friend Bignumber operator-(Bignumber &a,Bignumber &b);
	friend Bignumber operator*(Bignumber &a,Bignumber &b);
	friend Bignumber operator/(Bignumber &a,Bignumber &b);
	friend Bignumber operator%(Bignumber &a,Bignumber &b);
	friend Bignumber operator^(Bignumber &a,Bignumber &b);
	
	
	friend Bignumber operator<(Bignumber &a,Bignumber &b);
	friend Bignumber operator>(Bignumber &a,Bignumber &b);
	friend Bignumber operator==(Bignumber &a,Bignumber &b);
	friend Bignumber operator!=(Bignumber &a,Bignumber &b);


    
};
void Bignumber::display(){
	if(sign==0) cout<<"-";
	for(int i=v.size()-1;i>=0;i--) cout<<v[i];
	cout<<endl;
}
void Bignumber::trim(){
	for(int i=v.size()-1;i>=0;i--) if(v[i]==0) v.pop_back();else break;
	if(v.empty()) v.push_back(0);sign=1;
}
Bignumber::Bignumber(int val){
	if(val<0){
		sign=0;
		val=-val;
	}else sign=1;
	while(val){
		v.push_back(val%10);val/=10;
	}
}
Bignumber::Bignumber(string val){
	sign=1;
	for(int i=val.size()-1;i>=0;i--){
		if(val[i]=='+'||val[i]=='-') sign=0;
		else v.push_back(val[i]-'0');
	}
}
Bignumber::Bignumber(char *val){
	int len=strlen(val);
	sign=1;
	for(int i=len-1;i>=0;i--){
		if(val[i]=='-')  sign=0;
		else v.push_back(val[i]-'0');
	}
}
Bignumber::Bignumber(){
	sign=1;
	v.push_back(0);
}
void Bignumber::abs(){
	sign=1;
}
Bignumber Bignumber::operator=(const Bignumber& a){
}
Bignumber operator+(Bignumber a,Bignumber b){
}
Bignumber operator-(Bignumber a,Bignumber b){
}
Bignumber operator*(Bignumber a,Bignumber b){
}
Bignumber operator/(Bignumber a,Bignumber b){
}
Bignumber operator%(Bignumber a,Bignumber b){
}
Bignumber operator^(Bignumber a,Bignumber b){
}
Bignumber operator<(Bignumber &a,Bignumber &b){
}
Bignumber operator>(Bignumber &a,Bignumber &b){
}
Bignumber operator==(Bignumber &a,Bignumber &b){
}
Bignumber operator!=(Bignumber &a,Bignumber &b){
}
int main(){
	return 0;
}


/*

大数运算基础版 


*/
