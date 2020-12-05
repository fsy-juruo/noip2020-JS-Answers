#include<bits/stdc++.h>
using namespace std;
int n,m;
int u[100005],d[100005];
vector<int> mp[100005];
vector<int> la;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int gcd(int a,int b)
{
	int maxn=1;
	for(int i=2;i<=min(a,b);i++)
		if((a%i==0)&&(b%i==0)) maxn=i;
	return maxn;
}
void solve(int num)
{
	int g=gcd(u[num],d[num]);
	cout<<u[num]/g<<" "<<d[num]/g<<endl;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		if(k==0)
		{
			la.push_back(i);
			d[i]=1,u[i]=0;
			continue;
		}
		for(int j=1;j<=k;j++)
		{
			int a=read();
			mp[i].push_back(a);
		}
		d[i]=k,u[i]=0;
	}
	for(int i=1;i<=m;i++)
	    u[i]=d[i]=1;
	for(int i=1;i<=n;i++)
	{
		int tot=mp[i].size();
		for(int j=0;j<tot;j++)
		{
			int num=mp[i][j];
			if(u[num]==0)
			{
				u[num]=1;
				d[num]=tot*d[i];
			}
			else
			{
				int m=d[i]*tot,z=u[i];
	            int gfm=d[num]*m/gcd(d[num],m);//¹«·ÖÄ¸
	            u[num]=u[num]*gfm/d[num]+z*gfm/m;
				d[num]=gfm;
			}
		}
	}
	for(int i=0;i<la.size();i++)
		solve(la[i]);
	return 0;
}
