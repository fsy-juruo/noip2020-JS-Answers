#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int n,k,tot[500010],ans,w[1000010];
pair<int,int>step[500010];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch^'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=k;++i)
	w[i]=read();
	for(int i=1;i<=n;++i)
	{
		int c,d;
		c=read();
		d=read();
		step[i]=make_pair(c,d);
		tot[c]+=d;
	}
	bool f=false;
	for(int i=1;i<=n;++i)
	{
		if(tot[i])f=true;
	}
	if(f==false)
	{
		printf("-1");
		return 0;
	}
	if(k==5)
	{
		for(int a1=1;a1<=w[1];++a1)
		for(int a2=1;a2<=w[2];++a2)
		for(int a3=1;a3<=w[3];++a3)
		for(int a4=1;a4<=w[4];++a4)
		for(int a5=1;a5<=w[5];++a5)
		{
			int b1=a1,b2=a2,b3=a3,b4=a4,b5=a5,tot=0;
			while(b1>=1&&b1<=w[1]&&b2>=1&&b2<=w[2]&&b3>=1&&b3<=w[3]&&b4>=1&&b4<=w[4]&&b5>=1&&b5<=w[5])
			{
				int pos=step[tot%n+1].first;
				if(pos==1)b1+=step[tot%n+1].second;
				if(pos==2)b2+=step[tot%n+1].second;
				if(pos==3)b3+=step[tot%n+1].second;
				if(pos==4)b4+=step[tot%n+1].second;
				if(pos==5)b5+=step[tot%n+1].second;
				tot++;
			}
			ans=(ans+tot)%p;
		}
	}
	if(k==3)
	{
		for(int a1=1;a1<=w[1];++a1)
		for(int a2=1;a2<=w[2];++a2)
		for(int a3=1;a3<=w[3];++a3)
		{
			int b1=a1,b2=a2,b3=a3,tot=0;
			while(b1>=1&&b1<=w[1]&&b2>=1&&b2<=w[2]&&b3>=1&&b3<=w[3])
			{
				int pos=step[tot%n+1].first;
				if(pos==1)b1+=step[tot%n+1].second;
				if(pos==2)b2+=step[tot%n+1].second;
				if(pos==3)b3+=step[tot%n+1].second;
				tot++;
			}
			ans=(ans+tot)%p;
		}
	}
	if(k==2)
	{
		for(int a1=1;a1<=w[1];++a1)
		for(int a2=1;a2<=w[2];++a2)
		{
			int b1=a1,b2=a2,tot=0;
			while(b1>=1&&b1<=w[1]&&b2>=1&&b2<=w[2])
			{
				int pos=step[tot%n+1].first;
				if(pos==1)b1+=step[tot%n+1].second;
				if(pos==2)b2+=step[tot%n+1].second;
				tot++;
			}
			ans=(ans+tot)%p;
		}
	}
	if(k==1)
	{
		for(int a1=1;a1<=w[1];++a1)
		{
			int b1=a1,tot=0;
			while(b1>=1&&b1<=w[1])
			{
				int pos=step[tot%n+1].first;
				if(pos==1)b1+=step[tot%n+1].second;
				tot++;
			}
			ans=(ans+tot)%p;
		}
	}
	printf("%d",ans);
	return 0;
}
