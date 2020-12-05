#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void input(int &x)
{
	char c = getchar();
	int y = 1;
	while(c<'0'||c>'9'){
		if(c=='-') y = -1;
		c = getchar();
	}
	x = 0;
	while(c>='0'&&c<='9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x = x * y;
}
int n;
string s;
ll find(string ss)
{
	ll ord[27];
	memset(ord,0,sizeof(ord));
	for(ll i=0;i<ss.size();++i){
		ord[ss[i]-'a']++;
	}
	ll cnt=0;
	for(int i=0;i<27;++i){
		if(ord[i]%2) cnt++; 
	}
	return cnt;
}
ll div(string aa,string cc)
{
	int whb = 0;
	for(int i=0;i<aa.size();i++){
		string zsp = aa.substr(0,i);
		if(find(zsp)<=find(cc)) whb++;
	}
	return whb;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	input(n);
	for(int t=1;t<=n;++t){
		cin >> s;
		ll cnt= 0;
		int k = s.size();
		ll num = (k-1) * (k-2) / 2;
		for(register int i=1;i<k-1;++i){
			for(register int j=i+1;j<k;++j){
				string a = s.substr(0,i);
				string b = s.substr(i,j-i);
				string c = s.substr(j);
				if(a==b&&a.size()!=1){
					cnt += div(a,c) - 1;
				}
				if(find(a)>find(c)) continue;
				else{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
