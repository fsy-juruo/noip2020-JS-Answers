#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][405],top[55];
struct pt
{
	int x,y;
	pt(int a=0,int b=0):x(a),y(b){}
};
vector<pt>ans;
inline bool ok()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			if(a[i][j]!=a[i][j+1])
				return false;
	return true;
}
inline int get(int pos)
{
	int s=1;
	while(a[pos][s+1]==a[pos][1])
		++s;
	return s;
}
inline void trans(int x,int y)
{
	ans.push_back(pt(x,y));
	int d=a[x][top[x]];
	assert(x!=y);
	assert(top[x]!=0);
	assert(top[y]<=m-1);
	a[x][top[x]]=0;
	--top[x];
	a[y][++top[y]]=d;
}
bool cant[55];
int TOT=0;
inline int where()
{
	for(int i=1;i<=n+1;++i)
		if(top[i]==0)
			return i;
	return 1;
}
inline void solve(int x,int y,int what)
{
//	out();
	int pos=where();
	for(int i=1;i<=n+1;++i)
	{
		if(i==pos||cant[i])
			continue;
		while(a[i][top[i]]==what)
			trans(i,pos);
	}
//	out();
//	system("pause");
	int now=top[x]-y;
	if(top[pos]==0)
	{
		while(now)
		{
			trans(x,pos);
			--now;
		}
		int g=0;
		for(int i=1;i<=n+1;++i)
		{
			if(i==x||i==pos||cant[i])
				continue;
			g=i;
			while(top[pos]!=m-1)
				trans(i,pos);
			break;
		}
		trans(x,pos);
		while(top[x]!=0&&top[g]!=m)
			trans(x,g);
		return;
	}
	while(now&&top[pos]!=m)
	{
		trans(x,pos);
		--now;
	}
	if(top[pos]!=m)
	{
		for(int i=1;i<=n+1;++i)
		{
			if(i==pos||i==x||cant[i])
				continue;
			if(top[i])
			{
				trans(i,pos);
				break;
			}
		}
	}
//	out();
	for(int i=1;i<=n+1;++i)
	{
		if(i==pos||i==x||cant[i])
			continue;
		while(now&&top[i]!=m)
		{
			trans(x,i);
			--now;
		}
	}
//	out();
	for(int i=1;i<=n+1;++i)
	{
		if(i==pos||i==x||cant[i])
			continue;
		if(top[i]!=m)
		{
			while(top[i]!=m-1)
				trans(pos,i);
			trans(x,i);
			break;
		}
	}
//	out();
	for(int i=1;i<=n+1;++i)
	{
		if(i==pos||cant[i])
			continue;
		while(top[pos]!=0&&top[i]!=m)
			trans(pos,i);
	}
//	out();
}
inline void Move(int what)
{
	again:;
	for(int i=1;i<=n+1;++i)
	{
		bool f=0;
		for(int j=m;j>=1;--j)
		{
			if(a[i][j]==what&&f)
			{
				solve(i,j,what);
				goto again;
			}
			else if(a[i][j]!=what)
				f=1;
		}
	}
	int pos=where();
	for(int i=1;i<=n+1;++i)
	{
		if(i==pos||cant[i])
			continue;
		while(a[i][top[i]]==what)
			trans(i,pos);
	}
	cant[pos]=1;
	for(int i=1;i<=n+1;++i)
	{
		if(i==pos||cant[i])
			continue;
		for(int j=i+1;j<=n+1;++j)
			while(top[i]!=0&&top[j]!=m)
				trans(i,j);
		break;
	}
}
inline void solve()
{
	for(int i=1;i<=n;++i)
		Move(i);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();++i)
		cout<<ans[i].x<<" "<<ans[i].y<<endl;
//	out();
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	for(int i=1;i<=n;++i)
		top[i]=m;
	solve();
	return 0;
}

