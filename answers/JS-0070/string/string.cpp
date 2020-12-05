#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<char,int> cnt;
map<char,bool> v;
string s;
int ans = 0;
LL Tot(string m) {
	cnt.clear(); v.clear();
	LL tot = 0;
	for(int i = 0; i != m.size(); ++i){
		cnt[m[i]]++;
		v[m[i]] = true;
	}
	for(int i = 0; i != m.size(); ++i) {
		if(v[m[i]]){
			if(cnt[m[i]]%2==1) tot++;
			v[m[i]] = false;
		}
	}
	return tot;
}
bool check(string a,string b,string c) {
	string now = a+b;
	while(now.size()<s.size()-c.size()) now+=now;
	now+=c;
	return (now==s);
}
void dfs(LL Long) {
	string a;
	for(int i = 0; i < Long; ++i) a+=s[i];
	for(int i = Long+1; i != s.size(); ++i) {
		string c,b;
		for(int k = i; k != s.size(); ++k) c+=s[k];
		if(Tot(a) > Tot(c)) continue;
		for(int k = Long; k < i; ++k) {
			b+=s[k];
			if(check(a,b,c)) ans++;
		}
	}
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		cin>>s;
		ans = 0;
		for(int j=1; j<=s.size()-2;++j) dfs(j);
		printf("%d\n", ans);
	}
	return 0;
}
