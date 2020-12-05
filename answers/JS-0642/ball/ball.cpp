#include<bits/stdc++.h>
#define ll long long
#define str string
#define dou double
#define ull unsigned long long
#define fi first
#define se second
using namespace std;

const int maxn=60;
const int maxm=410;
int n,m;
int a[maxn][maxm];
int len[maxn];
int awa;
int st[820010][2];
int point;
bool get_ans;

bool check()
{
	bool p=false;
	for(int i=1;i<=n+1;i++)
	{
		if(len[i]==0)
		{
			p=true;
		}
		for(int q=2;q<=len[i];q++)
		{
			if(a[i][q]!=a[i][q-1])
			{
				return false;
			}
		}
	}
	if(p)
	{
		return true;
	}
	return false;
}

bool check2(int x)
{
	if(len[x]==0)
	{
		return false;
	}
	for(int i=len[x]-1;i>=1;i--)
	{
		if(a[x][i]!=a[x][i+1])
		{
			return false;
		}
	}
	return true;
}

void dfs(int now,int deep)
{
//	cout<<now<<" "<<deep<<endl;
	if(get_ans)
	{
		return ;
	}
	if(len[now]<=1)
	{
		return ;
	}
	if(check())
	{
		get_ans=true;
		return ;
	}
	if(deep>820000)
	{
		return ;
	}
	for(int i=1;i<=n+1;i++)
	{
		if(i==now)
		{
			continue;
		}
		if(len[i]>=m)
		{
			continue;
		}
		int o=0;
		if(check2(i))
		{
			if(a[now][len[now]]==a[i][len[i]])
			{
				st[++point][0]=now;
				st[point][1]=i;
				o=a[now][len[now]];
				a[i][++len[i]]=a[now][len[now]--];
			}
			continue;
		}
		else
		{
			st[++point][0]=now;
			st[point][1]=i;
			o=a[now][len[now]];
			a[i][++len[i]]=a[now][len[now]--];
		}
		bool fl=false;
		if(check2(now))
		{
			fl=true;
		}
		for(int q=1;q<=n+1;q++)
		{
			if(fl&&q==now)
			{
				continue;
			}
			if(q==i)
			{
				continue;
			}
			if(check2(q))
			{
				continue;
			}
			dfs(q,deep+1);
			if(get_ans)
			{
				break;
			}
		}
		if(get_ans||fl)
		{
			break;
		}
		a[now][++len[now]]=o;
		len[i]--;
		point--;
	}
}

bool qwqc()
{
	for(int i=1;i<=n;i++)
	{
		if(!check2(i))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int q=1;q<=m;q++)
		{
			scanf("%d",&a[i][q]);
		}
		len[i]=m;
	}
	for(int i=1;i<=n+1;i++)
	{
		if(check2(i))
		{
			continue;
		}
		dfs(i,1);
		if(get_ans)
		{
			break;
		}
	}
	printf("%d\n",point);
	for(int i=1;i<=point;i++)
	{
		printf("%d %d\n",st[i][0],st[i][1]);
	}
	return 0;
}

