#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp1[6][6][6][6][6][3+2];
int dp2[12][12][12][100+10];
int t,n,k,ans,jsq,s_az,s_af;
bool pan;
int ci[20],di[20],w[20];
int dfs(int a,int b,int c,int d,int e,int st)
{
	int a1=a,b1=b,c1=c,d1=d,e1=e;
	if(dp1[a][b][c][d][e][st]) return dp1[a][b][c][d][e][st];
	for(int i=st;i<=2*n;i++)
	{
		t++;
		jsq++;
		if(i>n) i=1;
		if(ci[i]==1) a+=di[i];
		if(ci[i]==2) b+=di[i];
		if(ci[i]==3) c+=di[i];
		if(ci[i]==4) d+=di[i];
		if(ci[i]==5) e+=di[i];
		if(jsq>=90000000)
		{
			pan=true;
			return 0;
		}
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
		if(a>w[1] || a<1 || b>w[2] || b<1 || c>w[3] || c<1 || d>w[4] || d<1 || e>w[5] || e<1)
		{
			dp1[a1][b1][c1][d1][e1][st]=t;
			break;
		}
	}
	return t;
}
int dfs2(int a,int b,int c,int st)
{
	int a1=a,b1=b,c1=c;
	if(dp2[a][b][c][st]) return dp2[a][b][c][st];
	for(int i=st;i<=2*n;i++)
	{
		t++;
		jsq++;
		if(i>n) i=1;
		if(ci[i]==1) a+=di[i];
		if(ci[i]==2) b+=di[i];
		if(ci[i]==3) c+=di[i];
		if(jsq>=90000000)
		{
			pan=true;
			return 0;
		}
		cout<<a<<" "<<b<<" "<<c<<"\n";
		if(a>w[1] || a<1 || b>w[2] || b<1 || c>w[3] || c<1)
		{
			dp2[a1][b1][c1][st]=t;
			break;
		}
	}
	return t;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++) cin>>w[i];
	for(int i=1;i<=n;i++) cin>>ci[i]>>di[i];
	if(k==5)
	{
		for(int a=1;a<=w[1];a++)
		{
			for(int b=1;b<=w[2];b++)
			{
				for(int c=1;c<=w[3];c++)
				{
					for(int d=1;d<=w[4];d++)
					{
						for(int e=1;e<=w[5];e++)
						{
							t=0;
							ans+=dfs(a,b,c,d,e,1);
							if(pan==true)
							{
								cout<<"-1"<<"\n";
								return 0;
							}
							ans%=mod;
						}
					}
				}
			}
		}
		cout<<ans%mod<<"\n";
		return 0;
	}
	if(k==3)
	{
		for(int a=1;a<=w[1];a++)
		{
			for(int b=1;b<=w[2];b++)
			{
				for(int c=1;c<=w[3];c++)
				{
					t=0;
					ans+=dfs2(a,b,c,1);
					if(pan==true)
					{
						cout<<"-1"<<"\n";
						return 0;
					}
					ans%=mod;
				}
			}
		}
		cout<<ans%mod<<"\n";
		return 0;
	}
	if(k==1)
	{
		int sum=0,tot=0;
		for(int i=1;i<=n;i++) sum+=di[i];
		if(sum>0)
		{
			for(int a=1;a<=w[1];a++)
			{
				ans+=(w[1]-a)/sum*n;
				ans%=mod;
			}
			cout<<ans<<' ';
			for(int s=1;s<=n;s++)
			{
				tot=0;
				for(int i=1;i<=2*n;i++)
				{
					if(i==n+1) i=1;
					tot+=di[i];
					if(s+tot==w[1]+1)
					{
						ans+=tot;
						ans%=mod;
						break;
					}
				}
			}
			cout<<ans%mod<<"\n";
			return 0;
		}
		if(sum==0)
		{
			cout<<"-1"<<"\n";
			return 0;
		}
	}
	return 0;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

*/

/*
3 5
2 1 1 1 1
1 1
1 -1
2 1

*/

/*
3 3
10 10 10
1 1
1 -1
2 1

*/

/*
2 1
5
1 1
1 1

*/
