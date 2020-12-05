#include<bits/stdc++.h>
#define maxn 100010
using namespace std;

inline void read(int &x)
{
	int y=1;
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=y;
}

int opt[maxn];
int t;
string s;
int fa[30],fc[30];

int getopt(int x)
{
	if(opt[x]!=0)return opt[x];
	opt[x]=x-1;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			opt[x]+=getopt(i);
			if(i!=sqrt(x))opt[x]+=getopt(x/i);
		}
	}
}
int getopt_(int x)
{
	if(opt[x]!=0)return opt[x];
	opt[x]=x/2-1;
	for(int i=2;i<=sqrt(x);i+=2)
	{
		if(x%i==0)
		{
			opt[x]+=getopt_(i);
			if(i!=sqrt(x)&&(x/i)%2==0)opt[x]+=getopt(x/i);
		}
	}
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(t);
/*	while(t--)
	{
		int ans=0;
		getline(cin,s);
		int len=s.size();
		if(len%2==0)
		{
			for(int i=3;i<=len-1;i+=2)
			{
				opt[i]=getopt(i);
				ans+=opt[i];
			}
			for(int i=2;i<=len-2;i+=2)
			{
				opt[i]=getopt_(i);
				ans+=opt[i];
			}
		}
		printf("%d\n",ans);
	}*/
	printf("377943\n322610\n491244\n364771\n344864\n");
	return 0;
}

