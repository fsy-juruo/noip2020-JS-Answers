#include<bits/stdc++.h>
using namespace std;
int t,ans;
string s,a,b,c;
inline int F(string g){
	bool book[300];
	int ct=0,ok;
	memset(book,1,sizeof(book));
	for(int i=0;i<g.length();++i){
		if(book[g[i]]){
			book[g[i]]=ok=0;
			for(int j=0;j<g.length();++j)if(g[i]==g[j])++ok;
			if(ok%2)++ct;
		}
	}
	return ct;
}
inline void getf(){
	if(F(a)<=F(c)){
		string k=a+b+c;
		while(k.length()<s.length())k=a+b+k;
		if(k==s)++ans;
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cin>>s;
		a="";ans=0;
		for(int i=0;i<s.length()-2;++i){
			a+=s[i];b="";
			for(int j=i+1;j<s.length()-1;++j){
				b+=s[j];c="";
				for(int k=s.length()-1;k>j;--k){
					c=s[k]+c;
					getf();
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
