// Author: 23forever
#include <bits/stdc++.h>
#define pb push_back
const int MAXN = 5e5;
const int MAXK = 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;

void read(int &x) {
  x = 0; int w = 1; char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  }
  x *= w;
}

void enablefileIO() {
  freopen("walk.in", "r", stdin);
  freopen("walk.out", "w", stdout);
}

int n, k, w[MAXK + 5], c[MAXN + 5], d[MAXN + 5];
int sum[MAXK + 5];
vector < int > vec[MAXK + 5];

void init() {
  enablefileIO();
  
  read(n), read(k);
  for (int i = 1; i <= k; ++i) read(w[i]);
  for (int i = 1; i <= n; ++i) {
    read(c[i]), read(d[i]);
    sum[c[i]] += d[i];
    vec[c[i]].pb(i);
  }
}

namespace task1 {

int cur[MAXK + 5], pos[MAXN + 5], ans, rst[MAXK + 5];

int calc() {
  int sum = 0; bool f = true;
  for (int i = 1; i <= k; ++i) pos[i] = cur[i];
  while (f) {
    for (int i = 1; i <= n; ++i) {
      int x = c[i];
      pos[x] += d[i], ++sum;
      if (pos[x] <= 0 || pos[x] > w[x]) {
        f = false; break;
      }
    }
  }
  return sum;
}
/*
int calc() {
  for (int i = 1; i <= k; ++i) {
    d[i] = INF;
    if (sum[i]) {
      if (sum[i] < 0) {
        d[i] = cur[i] / (-sum[i]);
        rst[i] = cur[i] % (-sum[i]);
      } else {
        d[i] = (w[i] - cur[i] + 1) / sum[i];
        rst[i] = (w[i] - cur[i] + 1) % sum[i];
      }
    }
  }
  
  int mn = INF, ret = INF;
  for (int i = 1; i <= k; ++i) mn = min(mn, d[i]);
  for (int i = 1; i <= k; ++i) {
    if (d[i] == mn) {
      if (rst[i]) {
        ret = min(ret, vec[i][rst[i] - 1] + d[i] * n);
      } else {
        ret = min(ret, (d[i] - 1) * n + vec[i][vec[i].size() - 1]);
      }
    }
  }
  
  return ret;
}
*/
void dfs(int x) {
  if (x > k) {
    ans = (ans + calc()) % P; return;
  }
  
  for (int i = 1; i <= w[x]; ++i) {
    cur[x] = i;
    dfs(x + 1); 
  }
}

void solve() {
  dfs(1);
  printf("%d\n", ans);
}

}

int main() {
  init();
  
  bool f = true;
  for (int i = 1; i <= k; ++i) {
    if (sum[i]) {
      f = false; break;
    }
  }
  
  if (f) {
    puts("-1"); return 0;
  }
  
  task1::solve();
  return 0;
}
