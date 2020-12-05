#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
ll n,m,ans;
ll a[55][405],cnt[55],num[55][405];
struct node
{
	ll g,p;
};
vector<node> q[55];
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;cnt[i]=m,i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=read();
			q[a[i][j]].push_back((node){i,j});
			num[i][a[i][j]]++;
		}
	}
		
	
}
