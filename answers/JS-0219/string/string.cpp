#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mxn=1050000;
string s;
int len;
int nx[mxn];
int cnt[32],all[32];
int cnto[mxn];
//int pri[100005],t=0;
//int num[mxn];
void Get()
{
	nx[0]=0;
	int j=0;
	for(int i=1;i<len;i++)
	{
		while(j>0 && s[j]!=s[i]) j=nx[j-1];
		if(s[j]==s[i]) j++;
		nx[i]=j;
	}
}
/*
void shai()
{
	for(int i=2;i<mxn;i++)
	{
		if(num[i]==0)
		{
			pri[t++]=i;
			for(int j=0;j<t && i*pri[j]<mxn;j++)
				num[i*pri[j]]=pri[j];
		}
		else
		{
			for(int j=0;j<t && num[i]>=pri[j] && i*pri[j]<mxn;j++)
			{
				num[i*pri[j]]=pri[j];
			}
		}
	}
}
*/
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	//shai();
	int T;
	cin>>T;
	while(T--)
	{
		memset(all,0,sizeof(all));
		memset(cnt,0,sizeof(cnt));
		memset(cnto,0,sizeof(cnto));
		memset(nx,0,sizeof(nx));
		cin>>s;
		len=s.size();
		if(len<=2)
		{
			cout<<0<<endl;
			continue;
		}
		Get();
		ll ans=0;
		/*
		if(len-nx[len-1]==1) 
		{
			for(int i=1;len-i>=2;i++)
			{
				if(i%2==1)
					ans+=len-i-1;
				else
					ans+=(len-i-1)/2;
				cout<<ans<<endl;
			}
			continue;
		}
		*/
		all[s[0]-'a']++;
		cnto[0]=1;
		for(int i=1;i<len;i++)
		{
			all[s[i]-'a']++;
			if(all[s[i]-'a']%2==1) cnto[i]=cnto[i-1]+1;
			else cnto[i]=cnto[i-1]-1;
		}
		int cb=0;
		for(int i=len-1;i>1;i--)
		{
			int ch=s[i]-'a';
			cnt[ch]++;
			if(cnt[ch]%2==1) cb++;
			else cb--;
			//cout<<cb<<endl;
			int k=i-nx[i-1];
			int ls=0,ct=0;
			if(i%k!=0 || i/k==1)
			{
				for(int j=0;j<i-1;j++)
				{
					if(cnto[j]<=cb) 
					{
						//cout<<j<<endl;
						ans++;
					}
				}
				//cout<<i<<" "<<ans<<endl;
				continue;
			}
			for(int j=1;j<i/k;j++)
			{
				if((i/k)%j==0)
				{
					//cout<<j<<endl;
					for(int p=ls;p<j*k-1;p++)
					{
						if(cnto[p]<=cb) ct++;
					}
					//cout<<ct<<endl;
					ls=j*k-1;
					ans+=ct;
				}
			}
			for(int p=ls;p<i-1;p++)
			{
				if(cnto[p]<=cb) ct++;
			}
			ans+=ct;
			//cout<<i<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/


