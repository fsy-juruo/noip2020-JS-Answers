// stay simple, stay naive
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
#define eprintf(...) ({ fprintf(stderr, __VA_ARGS__); fflush(stderr); })
#else
#define eprintf(...) 42
#endif

static const int Maxn = 52, Maxm = 405;

int n, m;
vector<int> a[Maxn];
vector<pair<int, int> > ans;

void transfer(int x, int y) {
  ans.push_back(make_pair(x, y));
  a[y].push_back(a[x].back());
  a[x].pop_back();
}

void solve(int id) {
  int C = a[id][0];
  for (int i = id + 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      while (a[i][j] == C) {
        int k = 0;
        for (k = 0; k < m; ++k)
          if (a[id][k] != C) break;
        for (int _ = 0; _ < j; ++_) transfer(id, n + 1);
        for (int _ = j; _ < m - 1; ++_) transfer(i, n + 1);
        transfer(i, id);
        for (int _ = j; _ < m - 1; ++_) transfer(n + 1, i);
        for (int _ = 0; _ < j - 1; ++_) transfer(n + 1, id);
        transfer(n + 1, i);
      }
    }
  }
}

int main() {

  freopen("ball.in", "r", stdin);
  freopen("ball.out", "w", stdout);
  
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x; scanf("%d", &x);
      a[i].push_back(x);
    }
  }
  for (int i = 1; i <= n; ++i) solve(i);
  printf("%u\n", ans.size());
  for (int i = 0; i < (int)ans.size(); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);

  return 0;

}

