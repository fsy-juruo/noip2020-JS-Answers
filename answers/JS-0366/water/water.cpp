#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(;  isdigit(c); c = getchar()) x = (x << 3) + (x << 1) +  c - '0';
	x *= f;
}
struct node{
	unsigned long long fz, fm;
}ans[100005];
int d[100005], f[100005];
bool h[100005];
vector <int> a[100005];
queue <int> q;

node yue(node x)
{
	if(x.fz == 1 || x.fm == 1) return x;
	unsigned long long g, a = x.fm, b = x.fz;
	while(b != 0)
	{
		g = a % b;
		a = b;
		b = g;	
	}
	x.fz /= a;
	x.fm /= a;
	return x;
}
void hb(int po, node t)
{
	if(ans[po].fm == 0) 
	{
		ans[po] = t;
		return;
	}
	ans[po].fz = ans[po].fz * t.fm + t.fz * ans[po].fm;
	ans[po].fm = ans[po].fm * t.fm;
	ans[po] = yue(ans[po]);
	return;
}
int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n, m, tot = 0, ini;
	read(n), read(m);
	for(int i = 1; i <= n; i++)
	{
		read(d[i]);
		if(d[i] == 0) {f[++tot] = i; h[i] = 1;}
		a[i].push_back(0);
		for(int j = 1; j <= d[i]; j++)
		{
			read(ini);
			a[i].push_back(ini);
		}
	}
	for(int i = 1; i <= m; i++)
	{
		q.push(i);
		ans[i].fz = ans[i].fm = 1;
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			node t;
			t.fz = ans[x].fz;
			t.fm = ans[x].fm * d[x];
			if(t.fm == 0) continue;
			t = yue(t);
			for(int i = 1; i <= d[x]; i++)
			{
				hb(a[x][i], t);
				if(h[a[x][i]] != 1) q.push(a[x][i]);
			}
			ans[x].fm = ans[x].fz = 0;
		}
	}
	for(int i = 1; i <= tot; i++)
	{
		cout << ans[f[i]].fz << " " << ans[f[i]].fm << endl;
	}
 	return 0;
}
