#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9 + 7;
template <typename T> inline void rd(T &x)
{
	x = 0; int f = 1; char ch = 0;
	for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - 48;
	x *= f;
}
template <typename T> inline void wrote(T x)
{
	if(x < 0) {putchar('-'); wrote(-x); return;}
	if(x < 10){putchar(x + 48); return;}
	wrote(x / 10); putchar(x % 10 + 48);
}
template <typename T> inline void writeln(T x)
{
	wrote(x); puts("");
}

const int N = 5e5 + 5;
ll ans;
int n,c[N],d[N],w[N],k;
vector <int> qq;

bool cmp(vector <int> qq, vector <int> qqq)
{
	bool ret = 1;
	for(int i = 1; i < qq.size(); ++i) if(qq[i] != qqq[i]) ret = 0;
	return ret;
}

void walk()
{
	ll cnt = 0;
	vector <int> q = qq;
	for(int i = 1; ;)
	{
		q[c[i]] += d[i]; ++cnt; cnt = cnt % P;
		if(cnt == n + 1)
		{
			vector <int> qqq = q;
			if(cmp(qqq,qq))
			{
				puts("-1");
				exit(0);
			}
		}
		if(q[c[i]] > w[c[i]] || q[c[i]] <= 0)
		{
			ans += cnt; ans %= P;
			return;
		}
		if(i == n) i = 1; else ++i;
	}
}

void dfs(int j)
{
	if(j > k)
	{
		walk();
		return;
	}
	for(int i = 1; i <= w[j]; ++i)
	{
		qq.push_back(i);
		dfs(j + 1);
		qq.pop_back();
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	rd(n); rd(k);
	for(int i = 1; i <= k; ++i) rd(w[i]);
	for(int i = 1; i <= n; ++i)
	{
		rd(c[i]); rd(d[i]);
	}
	if(n <= 1000)
	{
		qq.push_back(0);
		dfs(1);
		writeln(ans);		
	}
	else puts("-1");
	return 0;
}

