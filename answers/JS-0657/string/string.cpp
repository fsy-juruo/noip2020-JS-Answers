#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
string s;
string c,a,t,t2;
int letter[30];
inline int count(string str){
	int sum=0;
	for(int i=0;i<28;i++)letter[i]=0;
	for(int i=0;i<str.size();i++)
		letter[str[i]-'a']++;
	for(int i=0;i<26;i++)
		if(letter[i]&1)
			sum++;
	return sum;
}
inline bool check(){
	string str="";
	while(str.size()<t.size())str+=t2;
	return (str==t); 
}
inline string cut(int a1,int a2){
	string str="";
	for(int i=a1;i<a2;i++)
		str+=s[i];
	return str;
}
inline string cut2(int a1,int a2){
	string str="";
	for(int i=a1;i<a2;i++)
		str+=t[i];
	return str;
}
inline void solve2(){
	for(int i=1;i<t2.size();i++){
		a=cut2(0,i);
		if(count(a)<=count(c))
			ans++;//,cout<<a<<' '<<c<<'\n';
	}
}
inline void solve1(){
	for(int i=2;i*2<=t.size();i++){
		if((t.size()%i)!=0)continue;
		t2=cut2(0,i);//Ã¶¾ÙAB
		if(!check())continue;
		solve2();
	}
	t2=t;
	solve2();
}
inline void solve(){
	ans=0;
	cin>>s;//cout<<"|*"<<s.size()<<"*|\n"; 
	for(int i=2;i<s.size();i++){
		c=cut(i,s.size());//Ã¶¾ÙC 
		t=cut(0,i);
		solve1(); 
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}

