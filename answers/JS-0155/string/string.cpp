#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
string s;

inline bool check(string a,string c){
	map<char,int> sa,sc;
	set<char> ca,cc;
	int ta=0,tc=0;
	register int i;
	for(i=0;i<a.size();++i){
		++sa[a[i]];
		ca.insert(a[i]);
	}
	for(i=0;i<c.size();++i){
		++sc[c[i]];
		cc.insert(c[i]);
	}
	for(set<char>::iterator it=ca.begin();it!=ca.end();++it){
		char ch=*it;
		if(sa[ch]%2) ++ta;
	}
	for(set<char>::iterator it=cc.begin();it!=cc.end();++it){
		char ch=*it;
		if(sc[ch]%2) ++tc;
	}
	return ta<=tc;
}

inline int solva(string s){
	register int i;
	int ans=s.size()-1;
	
	string a,b;
	for(i=0;i<s.size();++i){
		a=s.substr(0,i+1);
		b=s.substr(i+1);
		if(a==b) ans+=solva(a);
	}
	
	return ans;
}

inline int solve(string s){
	register int i,j;
	int ans=0;
	
	string a,b,c;
	for(i=0;i<s.size();++i){
		for(j=i+1;j<s.size();++j){
			a=s.substr(0,i+1);
			b=s.substr(i+1,j-i);
			c=s.substr(j+1);
			if(check(a,c)&&a.size()&&b.size()&&c.size()){
				//cout<<a<<' '<<b<<' '<<c<<'\n';
				++ans;
				if(a.size()>1&&b.size()>1&&a==b){
					ans+=solva(a);
				}
			}
		}
	}
	
	return ans;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	register int i;
	
	for(i=1;i<=n;++i){
		cin>>s;
		cout<<solve(s)<<'\n';
	}
	
	return 0;
}
