# include <bits/stdc++.h>
using namespace std;

const int N = 52,M = 402;

template <typename T> void read(T &x)
{
	int w = 1;
	x = 0;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= w;
	return;
}

int n,m;

int MAX;

int a[N][M];
int top[N];

struct node
{
	int from,to;
	node(){}
	node(int u,int v) : from(u),to(v) {}
};

node opt[820003];

int tot = 0;

bool check(void)
{
	int cnt = 0;
	for(int i = 1; i <= n + 1; i++)
	{
		if(top[i] != m) 
		{
			if(top[i] != 0) return false;
			else cnt++;
		}
	}
	if(cnt > 1) return false;
	for(int i = 1; i <= n + 1; i++)
	{
		bool flag = 0;
		if(top[i] > 1)
		{
			for(int j = 2; j <= top[i]; j++)
			{
				if(a[i][j] != a[i][j - 1]) 
				{
					flag = 1;
					break;
				}
			}
		}
		if(flag) return 0;
	}
	return 1;
}

void print(void)
{
	printf("%d\n",tot);
	for(int i = 1; i <= tot; i++)
	{
		printf("%d %d\n",opt[i].from,opt[i].to);
	}
	return;
}

void dfs(int dep)
{
	if(dep > 15)
	{
		return;
	}
	if(dep > 820000) 
	{
		return;
	}
	if(check())
	{
		print();
		exit(0);
	}
	for(int i = 1; i <= n + 1; i++)
	{
		for(int j = 1; j <= n + 1; j++)
		{
			if(i == j || (tot > 0 && opt[tot].from == j && opt[tot].to == i))
			{
				continue;
			}
			if(top[i] == 0 || top[j] == m) continue;
			opt[++tot] = node(i,j);
			int aitopi = a[i][top[i]];
			a[j][++top[j]] = a[i][top[i]];
			--top[i];
			dfs(dep + 1);
			a[i][++top[i]] = aitopi;
			a[j][top[j]--] = 0;
			opt[tot--] = node(0,0);
		}
	}
}

int main(void)
{	
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n),read(m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) 
		{
			read(a[i][j]);
		}
		top[i] = m;
	}
	MAX = n * 5;
	dfs(1);
	return 0;
}
