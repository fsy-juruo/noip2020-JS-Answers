#include<bits/stdc++.h>
using namespace std;

void fre() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}

typedef long long ll;

inline ll read() {
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
inline void write(ll x) {
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}

ll cou(string x) {
	ll cnt=0;
	map<char,ll>mp;
	ll len=x.length();
	for(ll i=0; i<len; i++) {
		mp[x[i]]++;
	}
	for(map<char,ll>::iterator it=mp.begin(); it!=mp.end(); it++) {
		if(it->second%2==1)cnt++;
	}
	return cnt;
}

signed main() {
	fre();

	ll t;
	cin>>t;
	while(t--) {
		ll cnt=0;
		string x;
		cin>>x;
		ll len=x.length();
		for(ll i=1; i<len; i++)
			for(ll j=i+1; j<len; j++) {
				string a=x.substr(0,i),b=x.substr(i,j-i);
				string ss=x.substr(0,j);
				ll ptr=0;
				while(ss==x.substr(ptr,j)&&ptr+j<len) {
					string c=x.substr(ptr+j,len-ptr-j);
					if(cou(a)<=cou(c)) {
						cnt++;
					}
					ptr+=j;
				}
			}
		cout<<cnt<<endl;
	}

	return 0;
}
