#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v[100010];
inline ll gys(ll a, ll b)
{
	if(b == 0)return a;
	return gys(b, a %b);
}
struct AC{
	ll s;
	ll x;
	inline void yf()
	{
		ll t = gys(max(s, x), min(s, x));
		s /=t;
		x /=t;
	}
	inline void c(int p)
	{
		x *= p;
		yf();
	}
	inline void pl(AC p)
	{
		s = s *p.x +p.s *x;
		x *= p.x;
		yf();
	}
};
AC yi, li;
queue<int> q;
int pu, f;
int h[100010];
AC su[100010];
int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int i, j, n, m;
	cin >> n >> m;
	int d, t;
	memset(h, 0, sizeof(h));
	for(i = 1;i <= n;i++)
	{
		scanf("%d", &d);
		for(j = 1;j <= d;j++)
		{
			scanf("%d", &t);
			v[i].push_back(t);
			h[t]++;
		}
	}
	yi.s = 1;
	yi.x = 1;
	li.s = 0;
	li.x = 1;
	for(i = 1;i <= m;i++)
	{
		su[i] = yi;
	}
	for(i = m +1;i <= n;i++)
	{
		su[i] = li;
	}
	for(i = 1;i <= n;i++)
	{
		if(h[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		f = q.front();
		if(v[f].size() == 0)
		{
			q.pop();
		}
		else
		{
			su[f].c(v[f].size());
			for(i = 0;i < v[f].size();i++)
			{
				h[v[f][i]] --;
				su[v[f][i]].pl(su[f]);
				if(h[v[f][i]] == 0) {
					q.push(v[f][i]);
				}
			}
			q.pop();
		}
	}
	for(i = 1;i <= n;i++)
	{
		if(v[i].size() == 0)
		{
			cout << su[i].s << " " << su[i].x << endl;
		}
	}
 	return 0;
}

