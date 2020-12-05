#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,x[N],d[N],add[N],y[N],X[N],ans;
int check()
{
	int res=0;
	for(int i=0;i<m;i++)
		X[i]=y[i];
	while(true)
	{
		for(int i=0;i<n;i++)
		{
			res++;
			X[d[i]]+=add[i];
			if(X[d[i]]<=0||X[d[i]]>x[d[i]])
				return res;
		}
		bool ok=true;
		for(int i=0;i<m;i++)
		{
			if(X[i]!=y[i])
			{
				ok=false;
			}
		}
		if(ok)
		{
			cout<<"-1\n";
			exit(0);
		}
	}
	return 0;
}
void dfs(int qwq)
{
	if(qwq==m)
	{
		ans+=check();
		return;
	}
	for(int i=1;i<=x[qwq];i++)
	{
		y[qwq]=i;
		dfs(qwq+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>x[i];
	for(int i=0;i<n;i++)
	{
		cin>>d[i]>>add[i];
		d[i]--;
	}
	if(m>=10)
	{
		cout<<"-1\n";
		return 0;
	}
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}
