#include<bits/stdc++.h>

using namespace std;

template <class T>
inline void read(T &n)
{
	n=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	n*=f;
}

const int N=55,M=410;

int n,m;
int p[N][M];
bool flag;

bool check()
{
	for(int i=1;i<=n+1;++i)
		if(p[i][0]!=0||p[i][0]!=n)
			return false;
			
	for(int i=1;i<=n+1;++i)
	{
		if(p[i][0]==0)
			continue;
		for(int j=2;j<=m;++j)
			if(p[i][j]!=p[i][1])
				return false;
	}
	
	return true;
}

void dfs(int t,int lt)
{
	if(check())
	{
		flag=true;
		printf("%d\n",t);
		return;
	}
	
	for(int i=1;i<=n+1;++i)
	{
		if(i==lt)
			continue;
		if(p[i][0]<1)
			return;
		for(int j=1;j<=n+1;++j)
		{
			if(j==i||p[j][0]>m-1)
				continue;
			++p[j][0];
			p[j][p[j][0]]=p[i][p[i][0]];
			--p[i][0];
			dfs(t+1,j);
			if(flag==true)
			{
				printf("%d %d\n",i,j);
				return;
			}
			++p[i][0];
			p[i][p[i][0]]=p[j][p[j][0]];
			--p[j][0];
		}
	}
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	read(n);
	read(m);
	for(int i=1;i<=n;++i)
	{
		p[i][0]=m;
		for(int j=1;j<=m;++j)
			read(p[i][j]);
	}
	
	dfs(0,0);
	
	return 0;
}
