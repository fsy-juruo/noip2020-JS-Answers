#include<bits/stdc++.h>
using namespace std;
struct ins{
	template<typename T>void read(T &n)
	{
		n=0;char c=getchar();bool f=1;
		while(!isdigit(c)){if(c=='-')f=0;c=getchar();}
		while(isdigit(c)){n=n*10+c-'0';c=getchar();}
		if(f==0)n=-n;
	}
	template<typename T>ins operator >>(T &n)
	{
		this->read(n);
		return *this;
	}
}yin;
int f[101][11][11][11][11][11];
const int maxn=1e5+10;
int w[maxn],opt[maxn],d[maxn];
int d1[maxn];
int n;
int dfs(int kk,int a,int b,int c,int d,int e)
{
	if(a<=0)return 0;
	if(b<=0)return 0;
	if(c<=0)return 0;
	if(d<=0)return 0;
	if(a>w[1])return 0;
	if(e<=0)return 0;
	if(b>w[2])return 0;
	if(c>w[3])return 0;
	if(d>w[4])return 0;
	if(e>w[5])return 0;
	if(f[kk][a][b][c][d][e])return f[kk][a][b][c][d][e];
	int k=kk,aa=a,bb=b,cc=c,dd=d,ee=e;
	++kk;
	if(kk>n)kk=1;
	if(opt[kk]==1)a+=d1[kk];
	if(opt[kk]==2)b+=d1[kk];
	if(opt[kk]==3)c+=d1[kk];
	if(opt[kk]==4)d+=d1[kk];
	if(opt[kk]==5)e+=d1[kk];
	f[k][aa][bb][cc][dd][ee]=dfs(kk,a,b,c,d,e)+1;
//	cout<<f[k][aa][bb][cc][dd][ee]<<endl;
	return f[k][aa][bb][cc][dd][ee];
}
int k;
int c[maxn];
long long ans;
const long long mod=1e9+7;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	yin>>n>>k;
	for(int i=1;i<=k;i++)yin>>w[i];
	bool ff=1;
	for(int i=1;i<=n;i++)
	{
		yin>>opt[i]>>d1[i];
		c[opt[i]]+=d[i];
		if(abs(c[opt[i]])>w[i])ff=1;
	}
	bool fff=1;
	for(int i=1;i<=k;i++)
	{
		if(c[i]!=0)
		{
			fff=0;break;
		}
	}
	if(fff&&!ff)
	{
		printf("-1\n");
		return 0;
	}
	if(n<=100)
	{
		if(k<1)w[1]=1;
		if(k<2)w[2]=1;
		if(k<3)w[3]=1;
		if(k<4)
			w[4]=1;
		if(k<5)
			w[5]=1;
		for(int i=1;i<=w[1];i++)
		{
			for(int j=1;j<=w[2];j++)
			{
				for(int k=1;k<=w[3];k++)
				{
					for(int l=1;l<=w[4];l++)
					{
						for(int ll=1;ll<=w[5];ll++)
						{
							dfs(0,i,j,k,l,ll);
							ans+=f[0][i][j][k][l][ll];
							if(ans>=mod)ans-=mod;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}

