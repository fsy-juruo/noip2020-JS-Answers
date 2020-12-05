#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<int>q;
unsigned long long a[100010][2];
vector<int>v[100010];
int father[100010];
bool ans[100010];
bool ff[100010];
int read()
{
	int f=1,s=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		{
			f=-f;
		}
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return f*s;
}
void write(unsigned long long x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int d=read();
		for(int j=1;j<=d;j++)
		{
			int x=read();
			v[i].push_back(x);
			father[x]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		q.push(i);
		ff[i]=1;
		a[i][0]=1;
		a[i][1]=1;
	}
	while(!q.empty())
	{
		int x=q.front();
		if(!v[x].size())
		{
			ans[x]=1;
		}
		else
		{
			unsigned long long yy=a[x][1]*v[x].size();
			unsigned long long gong=__gcd(yy,a[x][0]);
			unsigned long long xx=a[x][0]/gong;
			yy=yy/gong;
			for(int i=0;i<v[x].size();i++)
			{
				father[v[x][i]]--;
				if(!ff[v[x][i]])
				{
					ff[v[x][i]]=1;
					a[v[x][i]][0]=xx;
					a[v[x][i]][1]=yy;
				}
				else
				{
					unsigned long long linx=a[v[x][i]][0];
					unsigned long long liny=a[v[x][i]][1];
					a[v[x][i]][0]=linx*yy+xx*liny;
					a[v[x][i]][1]=liny*yy;
					unsigned long long lingong=__gcd(a[v[x][i]][0],a[v[x][i]][1]);
					a[v[x][i]][0]/=lingong;
					a[v[x][i]][1]/=lingong;
				}
				if(!father[v[x][i]])
				{	
					q.push(v[x][i]);
				}
			}
		}
		q.pop();
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i])
		{
			write(a[i][0]);
			putchar(' ');
			write(a[i][1]);
			putchar('\n');
		}
	}
	return 0;
}

