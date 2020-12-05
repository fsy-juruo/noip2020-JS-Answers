#include <bits/stdc++.h>
using namespace std;
int MAXN=1e9+7,n,k,w[100010],xs[10],c[100010],p[100010],ma[100010],mi[100010],ans=0,d[100010];
int fp[2000000];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;i++)
	  {
	  	cin>>w[i];
		}
	for (int i=1;i<=n;i++)
	  {
	  	cin>>c[i]>>d[i];
	  	p[c[i]]+=d[i];
	  }
	int f=1;
	for (int i=1;i<=k;i++)
	  {
	  	if (p[i]!=0)
	  	{
	  		f=0;break;
		  }
	  }
	if (f==1)
	{
		for (int i=n;i>=1;i++)
		  {
		  	p[c[i]]-=d[i];
		  	ma[c[i]]=max(p[c[i]],ma[c[i]]);
		  	mi[c[i]]=min(p[c[i]],mi[c[i]]);
		  }
		int q=0;
		for (int i=1;i<=k;i++)
		  {
		  	if (ma[i]-mi[i]+1>w[i])
		  	{
		  		q=1;
		  		break;
			  }
		  }
		if (q==0)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	if (k==1)
	{
		for (int i=1234567-n;i<=1234567+n;i++)
		  fp[i]=n*2+1;
		int l=0,r=0,o=0;
		for (int i=1;i<=n;i++)
		  {
		  	o+=d[i];
		  	{
		  		if (o>r)
		  		{
		  			r=o;
		  			fp[r+1234567]=i;
				  }
				if (o<l)
				{
					l=o;
					fp[l+1234567]=i;
				}
			  }
		  }
		for (int i=1;i<=w[1];i++)
		{
			int y=i;
			if (y+r>w[1]||y+l<1)
			ans=(ans+min(fp[w[1]-y+1234567+1],fp[1234567-y]))%MAXN;
			else
			{
			if (o>0)
			{
				int d1=(w[1]-y-r)/o+1;
				ans=(ans+n*d1)%MAXN;
				y=y+o*d1;
				ans=(ans+min(fp[w[1]-y+1234567+1],fp[1234567-y]))%MAXN;
			}
			if (o<0)
			{
				int d1=(1-y-l)/o+1;
				ans=(ans+n*d1)%MAXN;
				y=y+o*d1;
				ans=(ans+min(fp[w[1]-y+1234567+1],fp[1234567-y]))%MAXN;
			}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if (k==2)
	{
		for (int i=1;i<=w[1];i++)
		  for (int j=1;j<=w[2];j++)	{
		xs[1]=i;xs[2]=j;
		int o=0;
		while (1)
		{
			ans=(ans+1)%MAXN;
			o=(o+1)%n;
			if (o==0)
			o=n;
			xs[c[o]]+=d[o];
			if (xs[c[o]]<1||xs[c[o]]>w[c[o]])
			break;
		}}
		cout<<ans<<endl;
	}
	if (k==3)
	{
		for (int i=1;i<=w[1];i++)
		  for (int j=1;j<=w[2];j++)
		  	for (int k=1;k<=w[3];k++)	{
		xs[1]=i;xs[2]=j;xs[3]=k;int o=0;
		while (1)
		{
			ans=(ans+1)%MAXN;
			o=(o+1)%n;
			if (o==0)
			o=n;
			xs[c[o]]+=d[o];
			if (xs[c[o]]<1||xs[c[o]]>w[c[o]])
			break;
		}}
		cout<<ans<<endl;
	}
	if (k==4)
	{
		for (int i=1;i<=w[1];i++)
		  for (int j=1;j<=w[2];j++)
		  	for (int k=1;k<=w[3];k++)
			  for (int l=1;l<=w[4];l++)	{
		xs[1]=i;xs[2]=j;xs[3]=k;xs[4]=l;int o=0;
		while (1)
		{
			ans=(ans+1)%MAXN;
			o=(o+1)%n;
			if (o==0)
			o=n;
			xs[c[o]]+=d[o];
			if (xs[c[o]]<1||xs[c[o]]>w[c[o]])
			break;
		}}
		cout<<ans<<endl;
	}
	if (k==5)
	{
		for (int i=1;i<=w[1];i++)
		  for (int j=1;j<=w[2];j++)
		  	for (int k=1;k<=w[3];k++)
			  for (int l=1;l<=w[4];l++)
			    for (int t=1;t<w[5];t++)	{
		xs[1]=i;
		xs[2]=j;
		xs[3]=k;
		xs[4]=l;
		xs[5]=t;
		int o=0;
		while (1)
		{
			ans=(ans+1)%MAXN;
			o=(o+1)%n;
			if (o==0)
			o=n;
			xs[c[o]]+=d[o];
			if (xs[c[o]]<1||xs[c[o]]>w[c[o]])
			break;
		}}
		cout<<ans<<endl;
	}
	return 0;
}

