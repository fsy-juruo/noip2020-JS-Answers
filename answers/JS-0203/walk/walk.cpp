#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
const int mod=1e9+7;
int n,k;
int c[maxn],d[maxn];
int tmp[maxn];
int tmp2[maxn];
int del[maxn];
int w[maxn];
int main()
{
	freopen("walk.in","r".stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	int P=1;
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
		P=P*w[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
	}
	memset(tmp,1,sizeof tmp);
			for(int i=1;i<=k;i++)
		{
			tmp2[i]=tmp[i];
		}
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			tmp2[c[i]]+=d[i];
			if(tmp2[c[i]]<1 || tmp2[c[i]]>w[c[i]])
			{
				ok=1;
				break;
			}
		}
		bool check=true;
		for(int i=1;i<=k;i++)
		{
			if(tmp2[i]!=tmp[i])
			{
				check=false;
			}
			del[i]=tmp2[i]-tmp[i];
			tmp2[i]=tmp[i];
		}
		if(check==true)
		{
			cout<<-1<<endl;
			return 0;
		}
		memset(tmp,1,sizeof tmp);
	if(n<=5 && k<=5)
	{
		int ans=0;
		while(P--)
		{
			bool check=false;
			while(check==false){
			
			for(int i=1;i<=n;i++)
			{
				tmp[c[i]]+=d[i];ans++;
				if(tmp[c[i]]>w[c[i]] || tmp[c[i]]<1)
				{
					check=true;
				}
				
			}
			int lc=k;
			tmp[lc]+=1; 
			while(tmp[lc]>w[lc] && lc>0)
			{
				tmp[lc]--;
				tmp[lc-1]++;
				lc--; 
			}
		}
		cout<<ans<<endl;
		return 0;
		} 
	}
	memset(tmp,1,sizeof tmp);
	int ans=0;
	while(P--)
	{
		for(int i=1;i<=k;i++)
		{
			tmp2[i]=tmp[i];
		}
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			tmp2[c[i]]+=d[i];
			if(tmp2[c[i]]<1 || tmp2[c[i]]>w[c[i]])
			{
				ans+=i;
				ok=1;
				break;
			}
		}
		if(ok) continue;
		bool check=true;
		for(int i=1;i<=k;i++)
		{
			if(tmp2[i]!=tmp[i])
			{
				check=false;
			}
			del[i]=tmp2[i]-tmp[i];
			tmp2[i]=tmp[i];
		}
		if(check==true)
		{
			cout<<-1<<endl;
			return 0;
		}
		int times=0x3f3f3f3f3f3f;
		for(int i=1;i<=k;i++)
		{
			int dis;
			if(del[i]==0) continue;
			if(del[i]>0)
			{
				dis=w[i]-tmp[i];
				times=min(times,(dis-dis%del[i])/del[i]);
			}
		}
		ans+=times*n;
		bool ok2=0;
		for(int i=1;i<=k;i++)
		{
			if(tmp[i]+times*del[i]<1 || tmp[i]+times*del[i]>w[i])
			{
				ok2=1;
				break;
			}
		}
		if(ok2) continue;
		for(int i=1;i<=k;i++)
		{
			tmp2[i]=tmp[i]+times*del[i];
		} 
					int lc=k;
			tmp[lc]+=1; 
			while(tmp[lc]>w[lc] && lc>0)
			{
				tmp[lc]--;
				tmp[lc-1]++;
				lc--; 
			}
	}
	return 0;
}
