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
const int N = 1058576;
string s;
int n;
int app[N][27];
namespace brute {
const int N = 1010;
int bf(int, int);
int mem[N][N];
int f(int l, int r) {
// return bf(l, r);
  if (mem[l][r] != -1) return mem[l][r];
  int ret = 0;
  rep(i, 26) {
    if ((app[r][i] - app[l - 1][i]) % 2 == 1) ret++;
  }
  return mem[l][r] = ret;
}
int bf(int l, int r) {
  int ret = 0;
  rep(i, 26) {
    int cs = 0;
    for (int j = l; j <= r; j++) if (s[j] == 'a' + i) cs++;
    if (cs % 2 == 1) ret++;
  }
  return ret;
}
LL power[N];
LL hash[N];
LL hashOf[N][N];
const int BASE = 131, MOD = 19260817;
void notgethash(int l) {
  for (int i = l; i <= n;
       i++) hashOf[l][i] = (hashOf[l][i - 1] + power[i - l] * (s[i] - 'a' + 1) % MOD) % MOD;
}
map<string, int> st;
int htot = 0;
typedef pair<pair<int, int>, int> tripair;
set<tripair> vis;
void cleanup() {
  st.clear();
  htot = 0;
//  memset(hashOf, 0, sizeof(hashOf));
//  memset(app, 0, sizeof(app));
  vis.clear();
}

void solveCase() {
  LL ans = 0;
  memset(mem, -1, sizeof(mem));
  repn(i, n) {
    rep(j, 26) {
      app[i][j] = app[i - 1][j] + (s[i] == (j + 'a'));
    }
  }
  repn(i, n) notgethash(i);
  repn(i, n) {  // a = s[1..i]
    for (int j = i + 1; j <= n - 1; j++) { // b = s[i + 1..j]
      // check how long we can reach by repeating (AB)
      // note, that one repetition is also allowed
      LL curh = hashOf[1][j];
      if (f(j + 1, n) >= f(1, i)) {
        int k = j + 1;
        if (!vis.count(make_pair(make_pair(hashOf[1][i], hashOf[i + 1][j]),
                                 hashOf[k][n]))) {
          vis.insert((make_pair(make_pair(hashOf[1][i], hashOf[i + 1][j]),
                                hashOf[k][n])));
          //                          eprintf("%d %d %d (%d, %d)\n", i, j, k, f(k, n), f(1, i));
          ans++;
        }
      }
//     if (f(j + 1, n) <= f(1, i) - 2) break;
      int k = j + j;
      if (j + j <= n)
        for (; k + 1 <= n; k += j) {
          if (hashOf[k - j + 1][k] == curh) {
            if (f(k + 1, n) >= f(1, i)) {

              if (!vis.count(make_pair(make_pair(hashOf[1][i], hashOf[i + 1][j]),
                                       hashOf[1 + k][n]))) {
                vis.insert((make_pair(make_pair(hashOf[1][i], hashOf[i + 1][j]),
                                      hashOf[1 + k][n])));
                //         eprintf("%d %d %d (%d, %d)\n", i, j, k, f(k, n), f(1, i));
                ans++;
              }
            }
          } else break;
        }
    }
  }
  cout << ans << endl;
  cleanup();
}
}
void solveCase() {
  cin >> s;
  n = s.length();
  s = "$" + s;
  if (n <= 1000) brute::solveCase();
  else brute::solveCase();
}
int main() {
#ifndef CHTHOLLY
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
#endif
  int tc;
  cin >> tc;
  using brute::power;
  power[0] = 1;
  repn(i, 1000) {
    power[i] = power[i - 1] * 131 % 19260817;
  }
  while (tc--) solveCase();
  return 0;
}

