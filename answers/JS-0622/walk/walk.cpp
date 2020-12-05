#include<bits/stdc++.h>

using namespace std;
int n,k,w[15],c[500005],d[500005],j[15],now[15],tmp,res,ans;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
	scanf("%d",&w[i]);
	for (int i=1;i<=n;i++)
	scanf("%d%d",&c[i],&d[i]);
	if (k==1)
	{
		for (j[1]=1;j[1]<=w[1];j[1]++)
		{
			res=0;
			tmp=0;
			now[1]=j[1];
			while (1)
			{
				tmp++;
				if (tmp>n)
				tmp=1;
				now[c[tmp]]+=d[tmp];
				res++;
				if (now[c[tmp]]<=0||now[c[tmp]]>w[c[tmp]])
				break;
				if (tmp==n&&now[1]==j[1])
				{
					cout<<-1;
					return 0;
				}
			}
			//cout<<res<<endl;
			ans+=res;
		}
		cout<<ans;
		return 0;
	}
	if (k==2)
	{
		for (j[1]=1;j[1]<=w[1];j[1]++)
		for (j[2]=1;j[2]<=w[2];j[2]++)
		{
			res=0;
			tmp=0;
			now[1]=j[1];
			now[2]=j[2];
			while (1)
			{
				tmp++;
				if (tmp>n)
				tmp=1;
				now[c[tmp]]+=d[tmp];
				res++;
				if (now[c[tmp]]<=0||now[c[tmp]]>w[c[tmp]])
				break;
				if (tmp==n&&now[1]==j[1]&&now[2]==j[2])
				{
					cout<<-1;
					return 0;
				}
			}
			//cout<<res<<endl;
			ans+=res;
		}
		cout<<ans;
		return 0;
	}
	if (k==3)
	{
		for (j[1]=1;j[1]<=w[1];j[1]++)
		for (j[2]=1;j[2]<=w[2];j[2]++)
		for (j[3]=1;j[3]<=w[3];j[3]++)
		{
			res=0;
			tmp=0;
			now[1]=j[1];
			now[2]=j[2];
			now[3]=j[3];
			while (1)
			{
				tmp++;
				if (tmp>n)
				tmp=1;
				now[c[tmp]]+=d[tmp];
				res++;
				if (now[c[tmp]]<=0||now[c[tmp]]>w[c[tmp]])
				break;
				if (tmp==n&&now[1]==j[1]&&now[2]==j[2]&&now[3]==j[3])
				{
					cout<<-1;
					return 0;
				}
			}
			//cout<<res<<endl;
			ans+=res;
		}
		cout<<ans;
		return 0;
	}
	if (k==4)
	{
		for (j[1]=1;j[1]<=w[1];j[1]++)
		for (j[2]=1;j[2]<=w[2];j[2]++)
		for (j[3]=1;j[3]<=w[3];j[3]++)
		for (j[4]=1;j[4]<=w[4];j[4]++)
		{
			res=0;
			tmp=0;
			now[1]=j[1];
			now[2]=j[2];
			now[3]=j[3];
			now[4]=j[4];
			while (1)
			{
				tmp++;
				if (tmp>n)
				tmp=1;
				now[c[tmp]]+=d[tmp];
				res++;
				if (now[c[tmp]]<=0||now[c[tmp]]>w[c[tmp]])
				break;
				if (tmp==n&&now[1]==j[1]&&now[2]==j[2]&&now[3]==j[3]&&now[4]==j[4])
				{
					cout<<-1;
					return 0;
				}
			}
			//cout<<res<<endl;
			ans+=res;
		}
		cout<<ans;
		return 0;
	}
	if (k==4)
	{
		for (j[1]=1;j[1]<=w[1];j[1]++)
		for (j[2]=1;j[2]<=w[2];j[2]++)
		for (j[3]=1;j[3]<=w[3];j[3]++)
		for (j[4]=1;j[4]<=w[4];j[4]++)
		for (j[5]=1;j[5]<=w[5];j[5]++)
		{
			res=0;
			tmp=0;
			now[1]=j[1];
			now[2]=j[2];
			now[3]=j[3];
			now[4]=j[4];
			now[5]=j[5];
			while (1)
			{
				tmp++;
				if (tmp>n)
				tmp=1;
				now[c[tmp]]+=d[tmp];
				res++;
				if (now[c[tmp]]<=0||now[c[tmp]]>w[c[tmp]])
				break;
				if (tmp==n&&now[1]==j[1]&&now[2]==j[2]&&now[3]==j[3]&&now[4]==j[4]&&now[5]==j[5])
				{
					cout<<-1;
					return 0;
				}
			}
			//cout<<res<<endl;
			ans+=res;
		}
		cout<<ans;
		return 0;
	}
	else cout<<"-1";
	return 0;
}
