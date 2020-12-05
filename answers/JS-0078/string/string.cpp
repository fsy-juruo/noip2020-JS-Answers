#include<bits/stdc++.h>
using namespace std;
int ans,cnt[26];
string s;
int F(int l,int r)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=l;i<=r;i++) cnt[s[i]-'a']++;
	int res=0;
	for(int i=0;i<26;i++) if(cnt[i]%2==1) res++;
	return res;
}
bool check(int a,int b,int c,int n)
{
	if(c%(b+1)!=0) return 0;
	if(F(0,a)>F(c,n-1)) return 0;
	for(int i=b+1;i<=c-1;i++)
		if(s[i]!=s[i-b-1]) return 0;
	return 1;
}
int calc(int c,int n)
{
	int res=0;
	for(int a=0;a<=c-2;a++)
		for(int b=a+1;b<=c-1;b++) if(check(a,b,c,n)) res++;
	return res;
}
void solve()
{
	cin>>s;
	int n=s.size();
	int ans=0;
	for(int c=n-1;c>=2;c--) ans+=calc(c,n);
	cout<<ans<<endl;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
