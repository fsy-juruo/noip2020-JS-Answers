#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define ttt template<typename T>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 1; i <= (int)(n); i++)
const int INF = 0x3f3f3f3f;
const LL INFLL = 1e18;

ttt inline void rd(T& x) {
  x = 0;
  T neg = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  x *= neg;
}
int n, m;
const int N = 440;
int a[N][N];
vector<pair<int, int> > path;
struct mys {
  vector<vector<int> > ve;
};
mys cur;
bool operator<(const mys& arr, const mys& brr) {
  rep(i, arr.ve.size()) {
    if (arr.ve[i] != brr.ve[i]) return arr.ve[i] < brr.ve[i];
  }
  return 0;
}
set<mys > st;
bool check(const mys& c) {
  rep(i, n + 1) {
    if (c.ve[i].empty()) continue;
    int prc = c.ve[i][0];
    rep(j, c.ve[i].size()) if (c.ve[i][j] != prc) return 0;
  }
  return 1;
}
void dfs() {
  if (check(cur)) {
    printf("%d\n", path.size());
    rep(i, path.size()) printf("%d %d\n", path[i].first + 1, path[i].second + 1);
    exit(0);
  }
  rep(i, n + 1) {
    // take the top item out of i
    if (cur.ve[i].empty()) continue;
    int u = cur.ve[i][cur.ve[i].size() - 1];
  //  cur.ve[i].pop_back();
    rep(j, n + 1) {
      if (j == i) continue;
      // and put it in j
      if (cur.ve[j].size() == m) continue;
      mys nxt = cur;
      nxt.ve[i].pop_back();
      nxt.ve[j].push_back(u);
      path.push_back(make_pair(i, j));
      if (!st.count(nxt)) {
        cur.ve[i].pop_back();
        cur.ve[j].push_back(u);
        st.insert(nxt);
        dfs();
        cur.ve[j].pop_back();
        cur.ve[i].push_back(u);
      }
      path.pop_back();
    }
  }
}
int main() {
#ifndef CHTHOLLY
  freopen("ball.in", "r", stdin);
  freopen("ball.out", "w", stdout);
#endif
  rd(n); rd(m);
  rep(i, n) rep(j, m) rd(a[i][j]);
  cur.ve.resize(n + 1);
  rep(i, n) rep(j, m) cur.ve[i].push_back(a[i][j]);
  dfs();
  return 0;
}

