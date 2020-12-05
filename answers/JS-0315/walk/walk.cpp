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
const int N = 100010, K = 12;
int n, k;
int w[K];
int c[N], d[N];
namespace bruteforce {
LL power[K];
vector<int> pos, Max;
bool getNextPos() {
  int m = pos.size();
  bool flg = false;
  for (int i = m - 1; i >= 0; i--) {
    if (pos[i] != w[i + 1]) {
      pos[i]++;
      for (int j = i + 1; j < m; j++) pos[j] = 1;
      flg = true;
      break;
    }
  }
  return flg;
}
int ans = 0;
map<vector<int>, int> emori;
int canExit(vector<int> cpos) {
  rep(i, cpos.size()) if (cpos[i] > w[i + 1] || cpos[i] <= 0) return 1;
  if (emori.count(cpos)) {
    return 2;
  }
  return false;
}
int simulate() {
  emori.clear();
  vector<int> curpos(pos);
  int i = 1, res = 0;
  while (true) {
    curpos[c[i] - 1] += d[i];
    ans++;
    int exs = canExit(curpos);
    if (exs == 1) {
  //     eprintf("%d\n", res);
       return 0;
    } else if (exs == 2) {
      cout << -1 << endl;
      return -1;
    }
    i = (i % n) + 1;
  }
  return 0;
}
void solve() {
  rep(i, k) {
    pos.push_back(1);
  //  Max.push_back(w[i + 1]);
  }
  do {
 //   rep(i, pos.size()) eprintf("%d ", pos[i]); eprintf("\n");
    if (simulate() == -1) return;
  } while (getNextPos());
  cout << ans << endl;
}
}
int main() {
#ifndef CHTHOLLY
  freopen("walk.in", "r", stdin);
  freopen("walk.out", "w", stdout);
#endif
  rd(n); rd(k);
  repn(i, k) rd(w[i]);
  repn(i, n) {
    rd(c[i]);
    rd(d[i]);
  }
  if ((k <= 5 && n <= 5) || (n <= 100 && k <= 3)) bruteforce::solve();
  else puts("-1");
  return 0;
}

