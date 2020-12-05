#include <bits/stdc++.h>
using namespace std;
int t;
unsigned long long ans;
string sub(string tp,int beg,int end){
	string rt;
	for(int i = beg;i <= end;i ++)rt += tp[i];
	return rt;
}
int f(string x){
	int c[26];
	register int rt = 0;
	for(register int i = 0;i < 26;++i)c[i] = 0;
	for(register int i = 0;i < x.size();++ i){
		c[x[i] - 'a']++;
	}
	for(register int i = 0;i < 26;++ i){
		if(c[i] % 2)rt ++;
	}
	return rt;
}
string app(string s1,string s2,int st){
	string rt;
	for(register int i = 1;i <= st;++i){
		rt += s1 + s2;
	}
	return rt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(register int i = 1;i <= t;++ i){
		string str;
		cin >> str;
		for(register int j = 2;j < str.size();++j){
			string ab;
			string a,b,c;
			ab = sub(str,0,j - 1);
			c = sub(str,j,str.size() - 1);
			for(register int st = 1;st <= ab.size() >> 1;++st){
				for(register int k = 1;k < ab.size() / st;++k){
					a = sub(ab,0,k - 1);
					b = sub(ab,k,ab.size() / st - 1);
					if(app(a,b,st) == ab && f(a) <= f(c)){
						//cout << a << " " << b << " " << c << endl;
						ans ++;
					}
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
