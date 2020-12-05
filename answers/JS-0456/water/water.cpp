#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b)
{
	if(a<b)
	{
		int x=a;
		a=b;
		b=x;
	}
	if(a%b==0)
	{
		return b;
	}
	gcd(a%b,b);
}

struct node
{
	int d;
	int a[10];
	int p,q;
}s[100005];

void dfs(int x)
{
	if(s[x].d==0)
		return;
	s[x].q*=s[x].d;	
	for(int i=1;i<=s[x].d;i++)
	{
		int w=s[x].a[i];
		s[w].p=(s[x].q*s[w].p+s[w].q*s[x].p)/gcd(s[x].q,s[w].q);
		s[w].q=s[x].q*s[w].q/gcd(s[x].q,s[w].q);
		dfs(w);		
	}
	if(s[x].d)
	{
		s[x].q=1;
		s[x].p=0;
	}
	return ;
}

signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		s[i].q=1;
		cin>>s[i].d;
		for(int j=1;j<=s[i].d;j++)
		{
			cin>>s[i].a[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		s[i].p=s[i].q=1;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i].q&&s[i].p)
		{
			int x=gcd(s[i].q,s[i].p);
			s[i].q/=x;
			s[i].p/=x;
			cout<<s[i].p<<' '<<s[i].q<<endl;
		}
	}
	return 0;
}


