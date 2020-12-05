#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, a, b) for(int (i) = (a); (i) <= (b); i++)

ll read() {
	char ch = getchar();
	int s = 1, w = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') s = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {w = w * 10 + ch - '0'; ch = getchar();}
	return s * w;
}

int in[maxn], out[maxn];
int ru[maxn], cnt;
int n, m;
vector<int> G[maxn];

ll gcd(ll a, ll b) {
	if(a % b == 0) return b;
	return gcd(b, a % b);
}

struct fenshu {
	ll s, m;
}ans[maxn];

fenshu add(fenshu a, fenshu b) {
	if(a.m == 0 && a.s == 0) return b;
	if(b.m == 0 && b.s == 0) return a;
	ll m = a.m * b.m, s = a.s * b.m + b.s * a.m;
	//cout << m << " " << s << endl;
	ll g = gcd(m, s);
	//cout << g << endl;
	m /= g, s /= g;
	fenshu ret;
	ret.s = s, ret.m = m;
	return ret;
}

fenshu div(fenshu a, int b) {
	ll m = a.m * b, s = a.s;
	//cout << m << " " << s << endl;
	ll g = gcd(m, s);
	//cout << "s" << endl;
	m /= g, s /= g;
	fenshu ret;
	ret.s = s, ret.m = m;
	return ret;
}

void dfs(int p, fenshu fa) {
	if(G[p].size() == 0) ans[p] = add(ans[p], fa);
	vector<int>::iterator it;
	for(it = G[p].begin(); it != G[p].end(); it++) {
		//cout << p << "->" << *it << endl;
		int si = G[p].size();
		//cout << si << endl;
		//cout << p << " " << ans[p].s << " " << ans[p].m << endl;
		//int a = *it;
		fenshu tmp = div(fa, si);
		//ans[*it] = add(ans[*it], div(ans[p], si));
		//cout << a << " " << ans[*it].s << "/" << ans[*it].m << endl;
		dfs(*it, tmp);
	}
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = read(), m = read();
	rep(i, 1, n) {
		int num = read();
		rep(j, 1, num) {
			int a = read();
			G[i].push_back(a);
			out[i]++;
			in[a]++;
		}
	}rep(i, 1, n) {
		ans[i].s = 0, ans[i].m = 0;
	}
	rep(i, 1, n) {
		if(in[i] == 0) {
			ru[++cnt] = i;
			fenshu re;
			re.s = 1, re.m = 1;
			ans[i] = re;
		}
	}
	
	rep(i, 1, cnt) {
		//cout << ru[i] << endl;
		dfs(ru[i], ans[ru[i]]);
	}
	rep(i, 1, n) {
		if(out[i] == 0) cout << ans[i].s << " " << ans[i].m << endl;
	}
	return 0;
}
