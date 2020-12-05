# include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5,K = 12;

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

int n,k;
long long w[K],w2[K];

int c[N],d[N];

int cnt = 0;
const int mod = 1e9 + 7;
int Delta[K];

int q[N];

bool check(void)
{
	for(int i = 1; i <= k; i++) 
	{
		if(w2[i] <= 0 || w2[i] > w[i]) return 0;
	}
	return 1;
}

void solve2(void)
{
	for(int i = 1; i <= k; i++) 
	{
		Delta[i] = w2[i] - q[i];
	}
	int minl = INT_MAX;
	for(int i = 1; i <= k; i++)
	{
		if(Delta[i] == 0) continue;
		int k;
		if(Delta[i] < 0) 
		{
			int D = -Delta[i];
			k = (q[i] - 1) / D;
		}
		else
		{
			k = (w[i] - q[i]) / Delta[i];
		}
		minl = min(minl,k);
	}
	cnt = (cnt + n * (minl - 1)) % mod;
	for(int i = 1; i <= k; i++)
	{
		if(Delta[i] < 0)
		{
			int D = -Delta[i];
			w2[i] -= D * minl;
		}
		else w2[i] += Delta[i] * minl;
	}
	int i = 0;
	while(1)
	{
		w2[c[i]] += d[i];
		if(check())
		{
			++i,++cnt;
			cnt = (cnt % mod);
		}
		else break;
	}
	return;
}

void solve(void)
{
	int i = 0;
	for(int i = 1; i <= k; i++) 
	{
		w2[i] = q[i];
//		printf("q[%d] = %d\n",i,q[i]);
	}
	int _cnt = cnt;
	while(1)	
	{
		w2[c[i]] += d[i];
		if(check()) 
		{
			++i,++cnt;
			if(i > n) 
			{
				i = 1;
				bool flag = 1;
				for(int j = 1; j <= k; j++)
				{
					if(w2[j] != q[j])  
					{
						flag = 0;
						break;
					}
				}
				if(flag)
				{
					printf("-1\n");
					exit(0);
				}
			}
			cnt = (cnt % mod);
		}
		else break;
	}
//	printf("Delta = %d\n",cnt - _cnt);
	return;
}

void dfs(int dep)
{
	if(dep > k) 
	{
		solve();
		return;
	}
	for(int i = 1; i <= w[dep]; i++) 
	{
		q[dep] = i;
		dfs(dep + 1);
		q[dep] = 0;
	}
	return;
}

int main(void)
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n),read(k);
	for(int i = 1; i <= k; i++)
	{
		read(w[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		read(c[i]),read(d[i]);
	}
	dfs(1);
	printf("%d\n",cnt % mod);
	return 0;
}

