#include <bits/stdc++.h>
#define int long long
#define inf 2000000007
using namespace std;
const int mod=1e9+7;

int read()
{
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return s*w;
}

int n,k,ans=0;
int w[15],a[15][1000005],minv[15][500005],minpos[15],maxv[15][500005],maxpos[15],lis[15];
int jj[15];

struct node{int u,v;}tmp[500005];

int Binary_sear_minv(int rt,int x)
{
	int l=1,r=n,last=0;
	while (l<=r)
	{
		int mid=(l+r)>>1; 
		if (x+minv[rt][mid]<=0)  last=mid,r=mid-1;
		else l=mid+1;
	}
	return last;
}

int Binary_sear_maxv(int rt,int x)//1 2
{
	int l=1,r=n,last=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (x+maxv[rt][mid]>w[rt])  last=mid,r=mid-1;
		else l=mid+1;
	}
	return last;
}

int ducati_div(int xx,int yy)
{
	if (xx%yy==0)  return xx/yy;
	else return (xx/yy)+1;
}

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=k;i++)  w[i]=read();
	for (int i=1;i<=n;i++)  tmp[i].u=read(),tmp[i].v=read();
	for (int i=1;i<=k;i++)  minv[i][0]=inf,maxv[i][0]=-inf;
	for (int i=1;i<=n;i++)
	{
		int rt=tmp[i].u;
		lis[rt]+=tmp[i].v;
		if (lis[rt]<minv[rt][i-1])
		{
			minv[rt][i]=lis[rt];
			minpos[rt]=i;
		}
		else minv[rt][i]=minv[rt][i-1];
		if (lis[rt]>maxv[rt][i-1])
		{
			maxv[rt][i]=lis[rt];
			maxpos[rt]=i;
		}
		else maxv[rt][i]=maxv[rt][i-1];
		for (int j=1;j<=k;j++)
		  if (j!=rt)
		  {
		  	  minv[j][i]=minv[j][i-1];
		  	  minpos[j]=minpos[j];
		  	  maxv[j][i]=maxv[j][i-1];
		  	  maxpos[j]=maxpos[j];
		  }
	}
	for (int i=1;i<=k;i++)
	{
		int f=lis[i];
		int tmp_minv=minv[i][n],tmp_maxv=maxv[i][n];
		for (int j=1;j<=w[i];j++)
		{
			int turn=0,tmp_pos=0;
			if (f>=0)
			{
				if (j+tmp_minv<=0)  tmp_pos=Binary_sear_minv(i,j);
				else tmp_pos=inf;
			}
			else
			{
				if (j+tmp_minv<=0)  turn=0;
				else turn=ducati_div((j+tmp_minv),abs(f));
				tmp_pos=Binary_sear_minv(i,j-turn*abs(f));
			}
			a[i][j]=turn*n+tmp_pos;
			
			if (f<=0)
			{
				if (j+tmp_maxv>w[i])  tmp_pos=Binary_sear_maxv(i,j);
				else tmp_pos=inf;
			}
			else
			{
				if (j+tmp_maxv>w[i])  turn=0;
				else
				{
					turn=ducati_div(w[i]+1-j-tmp_maxv,f);	
				}
				tmp_pos=Binary_sear_maxv(i,j+turn*f);
			}
			a[i][j]=min(a[i][j],turn*n+tmp_pos);
		}
	}
	for (int i=1;i<=k;i++)  sort(a[i]+1,a[i]+w[i]+1);
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=k;j++)  jj[j]=1;
		for (int j=1;j<=w[i];j++)
		{
			for (int tmp=1;tmp<=k;tmp++)
			{
				while (jj[tmp]<=w[tmp])
				{
					if (tmp<i&&a[tmp][jj[tmp]]<=a[i][j])  jj[tmp]++;
					else if (tmp>i&&a[tmp][jj[tmp]]<a[i][j])  jj[tmp]++;
					else break;
				}
			}
			int res=1;
			for (int tmp=1;tmp<=k;tmp++)
			{
				if (tmp!=i)  res=(res*(w[tmp]-jj[tmp]+1))%mod;
			}
			ans=(ans+res*a[i][j]%mod)%mod;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
