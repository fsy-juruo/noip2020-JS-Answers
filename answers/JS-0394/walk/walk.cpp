#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int P = 1e9 + 7;
const int N = 5e5 + 10;
const int K = 11;
const int W = 1e6 + 10;

int n , k;
int w[K];
int a[W][K];

vector < int > v[K];
vector < int > g[K];
LL ans;
bool h;

template <typename T> void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> void print(T x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void write(T x , char c) {
	if (x < 0) {x = -x; putchar('-'); }
	print(x);
	putchar(c);
}

void dfs(int dep , int s) {
	if (h) return;
	if (dep > k) {
		if (ans == INT_MAX) {
			h = 1;
			return;
		}
		ans = (ans + s) % P;
		return;
	} 
	for (int i = 1; i <= w[dep]; i++) dfs(dep + 1 , min(s , a[i][dep]));
}

int main() {

	freopen("work.in" , "r" , stdin);
	freopen("work.out" , "w" , stdout);

	read(n); read(k);
	if (n > 100) {
		write(-1 , '\n');
		return 0;
	}
	
	for (int i = 1; i <= k; i++) {
		read(w[i]);
		v[i].push_back(0);
		g[i].push_back(0);
	}
	
	for (int i = 1; i <= n; i++) {
		int d , x;
		read(d); read(x);
		v[d].push_back(x);
		g[d].push_back(i);
	}
	
	for (int i = 1; i <= k; i++) {
		int l = 1 , r = w[i] , ll = 1 , lr = w[i];
		
		if (v[i].size() <= 1) {
			for (int j = 1; j <= w[i]; j++) {
				a[j][i] = INT_MAX;
			}
			continue;
		}
		
		while(ll <= lr && v[i].size() > 1) {
			for (int j = 1; j < v[i].size(); j++) {
				a[ll][i] += g[i][j] - g[i][j - 1];
				a[lr + 1][i] -= g[i][j] - g[i][j - 1];
				l -= v[i][j]; r -= v[i][j];
				chkmax(ll , l); chkmin(lr , r);
				if (ll > lr) break;
			}
			g[i][0] = g[i][g[i].size() - 1] - n;
			if (ll == 1 && lr == w[i]) {
				write(-1 , '\n');
				return 0;
			}
		}
		for (int j = 1; j <= w[i]; j++) {
			a[j][i] += a[j - 1][i];
		}
	}
	
	dfs(1 , INT_MAX);
	if (h) write(-1 , '\n');
	else write(ans , '\n');

	return 0;

}

