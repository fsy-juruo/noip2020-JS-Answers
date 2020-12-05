#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[2000000],b[2000000],c,ans,vis[2000000],T,cnt[2000000],tot,g[200000],g1[200000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while (T--)
	{
		ans=0;
		s="";
		cin>>s;
		//getline(cin,s);
		memset(vis,0,sizeof(vis));
		c=0;
		for (int i=0;i<s.size();i++)
		{
			if (vis[s[i]]%2==0)
			{
				c++;
				vis[s[i]]++;
			}
			else {
				c--;
				vis[s[i]]++;
			}
			a[i]=c;
		}
		memset(vis,0,sizeof(vis));
		c=0;
		for (int i=s.size()-1;i>=0;i--)
		{
			if (vis[s[i]]%2==0)
			{
				c++;
				vis[s[i]]++;
			}
			else {
				c--;
				vis[s[i]]++;
			}
			b[i]=c;
		}
		//ÅÐÑ­»·½Ú
	//	string st="";
		memset(cnt,0,sizeof(cnt));
		
		for (int i=1;i<=s.size();)
		{
			int j=i+1,k=0;
			for (;j<s.size()-1;)
			{
				if (s[j]==s[k])
				{
					j++,k++;
					if (k>i)
					{
						cnt[i]++;
						k=0;
					}
				}
				else{
					break;
				}
			}
			i++;
		}
		tot=0;
		for (int i=1;i<=s.size();i++)
		{
			if (cnt[i]!=0)
			g[++tot]=i+1,g1[tot]=cnt[i];
		}
		
		for (int i=s.size()-1;i>=2;i--)
		{
			for (int j=0;j<i-1;j++)
			if (a[j]<=b[i])
			{
				for (int k=1;k<=tot;k++)
				if (g[k]>j+1&&i%g[k]==0&&i/g[k]<=g1[k]+1&&i/g[k]>1)ans++;
			//	for (int k=j+1;k<=s.size()/2;k++)
			//	if (cnt[k]!=0&&(i)%(k+1)==0&&(i)/(k+1)<=cnt[k]+1&&i/(k+1)>1)ans++;
				ans++;	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

