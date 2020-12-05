#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, m;
pair <long long, long long> ans[N];
vector <long long> out, v[N];
queue <long long> q;
long long gcd (long long x, long long y) {
	if (y == 0)
		return x;
	return gcd (y, x % y);
}
pair <long long, long long> add (pair <long long, long long> fi, pair <long long, long long> se) {
	long long ret1 = fi.first * se.second + fi.second * se.first, ret2 = fi.second * se.second;
	long long ls = gcd (ret1, ret2);
	ret1 /= ls;
	ret2 /= ls;
	return make_pair (ret1, ret2);
}
void pushdown (long long x) {
	long long up = ans[x].first, dw = ans[x].second * (long long)(v[x].size ());
	long long ls = gcd (up, dw);
	up /= ls;
	dw /= ls;
	pair <long long, long long> xp = make_pair (up, dw);
	for (long long i = 0; i < (long long)v[x].size (); i ++) {
		long long y = v[x][i];
		ans[y] = add (xp, ans[y]);
	}
	ans[x].first = 0;
	ans[x].second = 1;
	return ;
}
int main () {
	freopen ("water.in", "r", stdin);
	freopen ("water.out", "w", stdout);
	scanf ("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i ++) {
		long long len;
		scanf ("%lld", &len);
		for (long long j = 1; j <= len; j ++) {
			long long x;
			scanf ("%lld", &x);
			v[i].push_back (x);
		}
		if (len == 0)
			out.push_back (i);
		ans[i].second = 1;
		ans[i].first = 0;
	}
	for (long long i = 1; i <= m; i ++) {
		ans[i].first = 1;
		q.push (i);
	}
	while (!q.empty ()) {
		long long x = q.front (); q.pop ();
		if ((long long)(v[x].size ()) == 0)
			continue ;
		pushdown (x);
		for (long long i = 0; i < (long long)(v[x].size ()); i ++)
			if ((long long)(v[v[x][i]].size ()) != 0)
				q.push (v[x][i]);
	}
	for (long long i = 0; i < (long long)(out.size ()); i ++)
		printf ("%lld %lld\n", ans[out[i]].first, ans[out[i]].second);
	return 0;
}

