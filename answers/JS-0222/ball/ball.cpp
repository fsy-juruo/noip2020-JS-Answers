#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][405],h[55],lim;
bool flag;
vector<pair<int,int> >ans;
inline int read()
{
	char c=getchar();
	int x=0,y=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
inline void write(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	int sta[10],tp=0;
	while(x)
	{
		sta[++tp]=x%10;
		x/=10;
	}
	while(tp)
		putchar(sta[tp--]+'0');
}
inline void mov(int x,int y)
{
	h[y]++;
	swap(a[x][h[x]],a[y][h[y]]);
	h[x]--;
}
void dfs()
{
	int i,j;
	for(i=1;i<=n+1;i++)
	{
		for(j=1;j<m;j++)
			if(a[i][j]!=a[i][j+1])
				break;
		if(j<m)
			break;
	}
	if(i>n)
	{
		flag=true;
		write(ans.size());
		putchar('\n');
		for(i=0;i<ans.size();i++)
		{
			write(ans[i].first);
			putchar(' ');
			write(ans[i].second);
			putchar('\n');
		}
		return;
	}
	if(ans.size()>lim)
		return;
	for(i=1;i<=n+1;i++)
		for(j=1;j<=n+1;j++)
			if(i!=j&&(ans.empty()||i!=ans.back().second||j!=ans.back().first)&&h[i]&&h[j]<m)
			{
				ans.push_back(make_pair(i,j));
				mov(i,j);
				dfs();
				if(flag)
					return;
				mov(j,i);
				ans.pop_back();
			}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int i,j;
	n=read();
	m=read();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			a[i][j]=read();
		h[i]=m;
	}
	for(lim=0;lim<=820000;lim++)
	{
		flag=false;
		dfs();
		if(flag)
			break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
