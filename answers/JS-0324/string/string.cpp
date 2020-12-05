#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> ps;
int T,ans;
string s;
map<pair<ps,string>,bool>v;
int cnt(string s)
{
	int a[26]={},ss=0;
	for(register int i=0;s[i];i++)a[s[i]-'a']++;
	for(register int i=0;i<26;i++)ss+=a[i]&1;
	return ss;
}
bool check(int len,int cnt)
{
	if(cnt==1)return true;
	string lst;
	for(int i=1;i<=cnt*len;i+=len)
	{
		string t=s.substr(i,cnt);
		if(i!=1&&lst!=t)return false;
		lst=t;
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(register int i=0;i<T;++i)
	{
		cin>>s;
		int len=s.size();
		s=' '+s;
		ans=0;
		v.clear();
		for(register int j=3;j<=len;++j)
		{
			string sc=s.substr(j);
			for(register int k=1;k*k<=j;++k)
			{
				if((j-1)%k==0)
				{
					if(check(k,(j-1)/k))
					{
						for(register int la=1;la<k;la++)
						{
							string sa=s.substr(1,la),sb=s.substr(la+1,k-la);
							pair<ps,string> a;
							a.first.first=sa, a.first.second=sb, a.second=sc;
							if(v[a])continue;
							if(cnt(sa)<=cnt(sc))
							{
								ans++;
								v[a]=true;
							}
						}
					}
					if(k*k!=j-1&&check((j-1)/k,k))
					{
						for(register int la=1;la<(j-1)/k;la++)
						{
							string sa=s.substr(1,la),sb=s.substr(la+1,(j-1)/k-la);
							pair<ps,string> a;
							a.first.first=sa, a.first.second=sb, a.second=sc;
							if(v[a])continue;
							if(cnt(sa)<=cnt(sc))
							{
								ans++;
								v[a]=true;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
