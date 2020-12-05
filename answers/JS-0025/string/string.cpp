#include<bits/stdc++.h>
using namespace std;
vector<int> vec[40000];
bool vis[1100010];
int pre[1100010],suf[1100010],sum[1010];

void getfac(int m)
{
	for(int i=1;i<=sqrt(m);i++) 
	{
		if(m%i==0) 
		{
			vec[m].push_back(i);
			if(m/i!=i) vec[m].push_back(m/i);
		}
	}
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	int t;
	cin>>t;
	for(int i=1;i<=35000;i++) getfac(i);
	while(t--)
	{
		cin>>s;
		if(s.size()<=2)
		{
			cout<<0<<endl;
			continue;
		}
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=s.size();i++)
		{
			vis[s[i-1]]^=1;
			if(vis[s[i-1]]==0) pre[i]=pre[i-1]-1;
			else pre[i]=pre[i-1]+1;
		}
		memset(vis,0,sizeof(vis));
		for(int i=s.size();i>=1;i--)
		{
			vis[s[i-1]]^=1;
			if(vis[s[i-1]]==0) suf[i]=suf[i+1]-1;
			else suf[i]=suf[i+1]+1;
		}
		unsigned long long ans=0;
		if(s.size()<=2000)
		{
			for(int i=2;i<=s.size()-1;i++)
			{
				memset(sum,0,sizeof(sum));
				for(int j=1;j<=i;j++) 
				if(pre[j]<=suf[i+1]) sum[j]=sum[j-1]+1;
				else sum[j]=sum[j-1];
			
				for(int j=0;j<vec[i].size();j++)
				{
					int flag=1;
					int v=vec[i][j];
					for(int k=1;k<=i-v;k++)
					if(s[k-1]!=s[k-1+v])
					{
						flag=0;
						break;
					}
					if(flag) ans+=sum[v-1];
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i=2;i<=s.size()-1;i++)
			{
				int y=s.size()-i;
				if(y%2)
				{
					for(int j=0;j<vec[i].size();j++)
					ans+=vec[i][j]-1;
				}
				else
				{
					for(int j=0;j<vec[i].size();j++)
					ans+=(vec[i][j]-1)/2;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
