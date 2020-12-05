#include <bits/stdc++.h>
using namespace std;
int __t;
// -> n*lg(n)
const int maxn=10476+100;
int num[maxn],rnum[maxn],mp[28],rmp[28];
bool check(int l,const string &s,int limit) {
	if(limit%l) return 0;
	string nw=s.substr(1,l);
	string backup="";
	for(int i=1;i<=limit/l;++i) {
		backup+=nw;
	}
	return backup==s.substr(1,limit);
}
int get(string &s,int l,int now) {
	int tic=0;
	for(int i=1;i<=l-1;++i) {
		tic+=(num[i]<=now);
	}
	return tic;
}
int do_once(string &s)
{
	int n=s.size();
	s.insert(0," "); //easier to think
	memset(num,0,sizeof(num));
	memset(rnum,0,sizeof(rnum));
	memset(mp,0,sizeof(mp));
	memset(rmp,0,sizeof(rmp));// init the array
	for(int i=1; i<=n; ++i) {
		++mp[s[i]-'a'];
		num[i]=num[i-1];
		if(mp[s[i]-'a']%2) {
			++num[i];
		} else {
			--num[i];
		}
		//cout<<num[i]<<" ";
	}//pre process;
	for(int i=n; i>=1; --i) {
		++rmp[s[i]-'a'];
		rnum[i]=rnum[i+1];
		if(rmp[s[i]-'a']%2) {
			++rnum[i];
		} else {
			--rnum[i];
		}
		//cout<<rnum[i]<<" ";
	}
	int ans=0;
	for(int i=n; i>=1; --i) {
		int now=rnum[i];
		for(int j=1; j<=i-2; ++j) {
			ans+=(num[j]<=now);
			for(int l=2;l<=j;++l) {
				if(check(l,s,j+1)) {
					//cout<<"()"<<j+1<<endl;
					for(int k=1;k<=(j+1)/l-1;++k) {
					//	cout<<"**"<<k*l<<endl;
						ans+=get(s,k*l,now);
					} 
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//cout<<how("mmmmllllmmmmllll",0);
	//cout<<check(9,"08888888888888888",16);
	scanf("%d",&__t);
	while(__t--) {
		string s;
		cin>>s;
		do_once(s);
	}
}
