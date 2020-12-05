// stay simple, stay naive
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
#define eprintf(...) ({ fprintf(stderr, __VA_ARGS__); fflush(stderr); })
#else
#define eprintf(...) 42
#endif

#define gc getchar()
inline int read(void) {
  int x = 0;
  register char ch = gc;
  while (ch < 48) ch = gc;
  while (ch > 47) x = x * 10 + ch - 48, ch = gc;
  return x;
}

static const int Maxn = 1e5 + 5;

long long gcd(long long x, long long y) {
  while (y) {
    long long t = x % y;
    x = y, y = t;
  }
  return x;
}

struct frac {
  long long x, y;
  frac() : x(0), y(1) { }
  frac(long long x, long long y) : x(x), y(y) { trim(); }
  void trim(void) {
    if (x == 0) y = 1;
    else {
      long long g = gcd(x, y);
      x /= g, y /= g;
    }
  }
  frac &operator += (const frac &b) {
    long long Y = y * b.y;
    long long X = x * b.y + b.x * y;
    *this = frac(X, Y);
    return *this;
  }
  friend frac operator / (frac a, const long long &b) {
    a.y *= b; a.trim();
    return a;
  }
};
int n, m;
int od[Maxn], deg[Maxn];
vector<int> g[Maxn];
frac ans[Maxn];

int main() {

  freopen("water.in", "r", stdin);
  freopen("water.out", "w", stdout);
  
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    od[i] = read();
    for (int j = 1; j <= od[i]; ++j) {
      int v = read();
      g[i].push_back(v);
      deg[v]++;
    }
  }
  for (int i = 1; i <= m; ++i)
    ans[i] = frac(1, 1);

  int qh = 0, qe = 0;
  static int que[Maxn];
  for (int i = 1; i <= n; ++i)
    if (!deg[i]) que[++qe] = i;
  while (qh < qe) {
    int u = que[++qh];
    for (int i = 0; i < (int)g[u].size(); ++i) {
      int v = g[u][i];
      if (!--deg[v]) que[++qe] = v;
    }
  }
  for (int i = 1; i <= qe; ++i) {
    int u = que[i];
    for (int j = 0; j < (int)g[u].size(); ++j) {
      int v = g[u][j];
      ans[v] += ans[u] / od[u];
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (od[i] == 0) {
      ans[i].trim();
      printf("%lld %lld\n", ans[i].x, ans[i].y);
    }
  }

  return 0;

}

