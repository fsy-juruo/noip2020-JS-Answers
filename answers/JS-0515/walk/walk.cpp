#include<bits/stdc++.h>
using namespace std;
const int md=1000000007;
template<typename T>void Read(T &cn)
{
	char ch;
	int f=0;
	cn=0;
	while(!isdigit(ch=getchar()))if(ch=='-')f=1;
	if(f){cn=cn*10+48-ch;while(isdigit(ch=getchar()))cn=cn*10+48-ch;}
	else {cn=cn*10+ch-48;while(isdigit(ch=getchar()))cn=cn*10+ch-48;}
}
int n,k,w[21],c[100010],d[100010],wi[21],dw[21],p,f;
int pd(int kk)
{
	if(p>n&&f==0)return -1;
	for(int i=1;i<=kk;i++)
	{
		if(wi[i]>w[i]||wi[i]<1)
		return 0;
	}
	return 1;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	Read(n);
	Read(k);
	for(int i=1;i<=k;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		Read(c[i]);
		Read(d[i]);
		dw[c[i]]+=d[i];
	}
	c[0]=c[n];
	d[0]=d[n];
	for(int i=1;i<=n;i++)if(dw[i]!=0)f=1;
	if(k==1)
	{
		long long ans=0;
		for(int i=1;i<=w[1];i++)
		{
			wi[1]=i;
			p=0;
			while(++p)
			{
				wi[c[p%n]]+=d[p%n];
				ans++;
				ans%=md;
				if(pd(1)==0)break;
				if(pd(1)==-1)
				{
					cout<<-1;
					return 0;
				}
			}
		}
		cout<<ans<<endl;
	}
	if(k==2)
	{
		long long ans=0;
		for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++)
		{
			wi[1]=i;
			wi[2]=j;
			p=0;
			while(++p)
			{
				wi[c[p%n]]+=d[p%n];
				ans++;
				ans%=md;
				if(pd(2)==0)break;
				if(pd(2)==-1)
				{
					cout<<-1;
					return 0;
				}
			}
		}
		cout<<ans<<endl;
	}
	if(k==3)
	{
		long long ans=0;
		for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++)
		for(int l=1;l<=w[3];l++)
		{
			wi[1]=i;
			wi[2]=j;
			wi[3]=l;
			p=0;
			while(++p)
			{
				wi[c[p%n]]+=d[p%n];
				ans++;
				ans%=md;
				if(pd(3)==0)break;
				if(pd(3)==-1)
				{
					cout<<-1;
					return 0;
				}
			}
		}
		cout<<ans<<endl;
	}
	if(k==4)
	{
		long long ans=0;
		for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++)
		for(int l=1;l<=w[3];l++)
		for(int ii=1;ii<=w[4];ii++)
		{
			wi[1]=i;
			wi[2]=j;
			wi[3]=l;
			wi[4]=ii;
			p=0;
			while(++p)
			{
				wi[c[p%n]]+=d[p%n];
				ans++;
				ans%=md;
				if(pd(4)==0)break;
				if(pd(4)==-1)
				{
					cout<<-1;
					return 0;
				}
			}
		}
		cout<<ans<<endl;
	}
	if(k==5)
	{
		long long ans=0;
		for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++)
		for(int l=1;l<=w[3];l++)
		for(int ii=1;ii<=w[4];ii++)
		for(int jj=1;jj<=w[5];jj++)
		{
			wi[1]=i;
			wi[2]=j;
			wi[3]=l;
			wi[4]=ii;
			wi[5]=jj;
			p=0;
			while(++p)
			{
				wi[c[p%n]]+=d[p%n];
				ans++;
				ans%=md;
				if(pd(5)==0)break;
				if(pd(5)==-1)
				{
					cout<<-1;
					return 0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


