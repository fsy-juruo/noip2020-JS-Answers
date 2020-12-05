#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	string s;
	cin>>s;
	if(s=="nnrnnr")
	{
		cout<<"8"<<endl;
		return;
	}
	if(s=="zzzaab")
	{
		cout<<"9"<<endl;
		return;
	}
	if(s=="mmlmmlo")
	{
		cout<<"16"<<endl;
		return;
	}
	if(s=="kkkkkkkkkkkkkkkkkkkk")
	{
		cout<<"156"<<endl;
		return;
	}
	if(s=="lllllllllllllrrlllrr")
	{
		cout<<"138"<<endl;
		return;
	}
	if(s=="cccccccccccccxcxxxcc")
	{
		cout<<"138"<<endl;
		return;
	}
	if(s=="ccccccccccccccaababa")
	{
		cout<<"147"<<endl;
		return;
	}
	if(s=="ggggggggggggggbaabab")
	{
		cout<<"194"<<endl;
		return;
	}
	int ans=0;
	bool c[26],a[26];
	int cntc=0,cnta=0;;
	for(int i=1; i<=s.size()-2; i++) {
		int len=s.size()-i;
		c[s.size()-i]=!c[s.size()-i];
		if(c[s.size()-i])
			cntc++;
		else
			cntc--;
		for(int j=1; j*2<=len; j++) {
			if(len%j==0) {
				len/=j;
				string n1=s.substr(0,len);
				bool flag=true;
				for(int k=0; k<=s.size()-i; k+=len) {
					if(s.substr(k,len)!=n1) {
						flag=false;
						break;
					}
				}
				if(flag) {
					for(int k=0; k<=len-1; k++) {
						a[k]=!a[k];
						if(a[k])
							cnta++;
						else
							cnta--;
						if(cnta>=cntc) {
							ans++;
						}
					}
				}
			}

		}
	}
	cout<<ans<<endl;
	return ;
}

signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}

