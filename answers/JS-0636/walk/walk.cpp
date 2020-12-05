#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n; long long ans;
vector< pair<int, int> >g[12];
int lim[12];
int d[12], t[1000006], mtim[10][1000006];
int mx;
#define t(p) t[p+500000]
void ctt(int pk, int k)
{
	int p[20];
	for(int i = 1; i <= k; ++i)
		p[i] = 0;
	while(true)
	{
		p[pk]++;
		if(p[pk] > lim[pk] || mtim[pk][p[pk]] == 0x7f7f7f7f ) break;
		int T = mtim[pk][p[pk]];
		long long E = 1;
		for(int i = 1; i <= k; ++i)
		{
			while(p[i] <= lim[i] &&mtim[i][p[i]] < T) ++p[i];
			int h = lim[i] + 1 - p[i];
			if(i != pk)
				E = E*h%mod;
		}
		ans = (ans + mtim[pk][p[pk]] * E)%mod;
	}
}
void sol(int k)
{
	for(int i = 0; i < 1000006; ++i)
		t[i] = 0x7f7f7f7f;
	t(1) = 0;
	int p = 1, L = 1, R = 1;
	for(int i = 0; i < g[k].size(); ++i)
	{
		int np = p + g[k][i].first;
		#define Min(a, b) (((a) < (b))? (a):(b))
		#define Max(a, b) (((a) < (b))? (b):(a))
		t(np) = Min(t(np), g[k][i].second);
		p = np; L = Min(L, p), R = Max(R, p);
	}
	for(int i = 1; i <= lim[k]; ++i)
	{
		int l = 1-i, r = l + lim[k] +1;
		int lt, rt;
		if(t(l) == 0x7f7f7f7f && d[k] >= 0)
			lt = 0x7f7f7f7f;
		else if(t(l) != 0x7f7f7f7f)
			lt = t(l);
		else
		{
			// 先走 N 个周期, 使下一个周期最左端到达 l 
			int len = L - l, N = len/(-d[k]) + bool(len%(-d[k]));
			lt = N*n + t(l-N*d[k]);
		}
		if(t(r) == 0x7f7f7f7f && d[k] <= 0)
			rt = 0x7f7f7f7f;
		else if(t(r) != 0x7f7f7f7f)
			rt = t(r);
		else
		{
			int len = r - R, N = len/(d[k]) + bool(len%d[k]);
			rt = N*n + t(r-N*d[k]);
		}
		mtim[k][i] = Min(lt, rt);
		if(mtim[k][i] != 0x7f7f7f7f) mx = Max(mx, mtim[k][i]);
	}
	sort(mtim[k]+1, mtim[k]+lim[k]+1);
}
int main(void)
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	int k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; ++i)
		scanf("%d", lim+i);
	for(int i = 1; i <= n; ++i)
	{
		int t, d;
		scanf("%d%d", &t, &d);
		g[t].push_back(make_pair(d, i));
	}
	for(int pk = 1; pk <= k; ++pk)
		for(int i = 0; i < g[pk].size(); ++i)
			d[pk] += g[pk][i].first;
	
//					for(int pk = 1; pk <= k; ++pk)
//						cout << pk << ' ' << lim[pk] << ' ' << d[pk] << endl;
	
	for(int pk = 1; pk <= k; ++pk)
		sol(pk);
	bool flg = true;
	for(int i = 1; i <= k; ++i)
	{
		if(mtim[i][lim[i]] != 0x7f7f7f7f)
			flg = false;
	}
	if(flg)
	{
		puts("-1");
		return 0;
	}
	for(int pk = 1; pk <= k; ++pk)
		ctt(pk, k);
	int ere[20];
	for(int i = 1; i <= k; ++i)
		ere[i] = 0;
	for(int i = 1; i <= mx; ++i)
	{
		long long E = 0;
		for(int j = 1; j <= k; ++j)
		{
			int u = ere[j];
			while(u < lim[j] && mtim[j][u] < i) ++u;
			E = E*(u-ere[j])%mod;
		}
		ans = (ans + E*i)%mod;
	}
	printf("%lld\n", ans);
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
