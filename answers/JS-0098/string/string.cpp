// Author: 23forever
#include <bits/stdc++.h>
const int MAXN = 1100000;
const int MAXL = 21;
const int P = 2333;
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

void enablefileIO() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
}

ULL b[MAXN + 5];
char s[MAXN + 5];
int n;

void init() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  
  b[0] = 1;
  for (int i = 1; i <= n; ++i) b[i] = b[i - 1] * P;
}

namespace brute2 {

bool chk(int n, int k) {
  for (int i = k + 1; i <= n; ++i) {
    if (s[i] != s[i - k]) return false;
  }
  return true;
}

int cnt[30];

int calc(int l, int r) {
  memset(cnt, 0, sizeof(cnt)); int ret = 0;
  for (int k = l; k <= r; ++k) {
    ++cnt[s[k] - 'a'];
    ret += (cnt[s[k] - 'a'] % 2 ? 1 : -1);
  }
  return ret;
}

void solve() {
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j < n; ++j) {
      int len_ab = j * i;
      if (len_ab >= n) break;
      
      if (chk(len_ab, j)) {
        int fc = calc(len_ab + 1, n); 
        memset(cnt, 0, sizeof(cnt)); int fa = 0;
        for (int k = 1; k < j; ++k) {
          ++cnt[s[k] - 'a'];
          fa += (cnt[s[k] - 'a'] % 2 ? 1 : -1);
          if (fa <= fc) ++ans;
        }
      }
    }
  }
  printf("%lld\n", ans);
}

}

namespace solver {

int f[MAXN + 5], cnt[30], S[30], suf[MAXN + 5];

ULL hsh[MAXN + 5];

ULL getHsh(int l, int r) {
  return hsh[r] - hsh[l - 1] * b[r - l + 1];
}
bool chk(int x, int len) {
  int rst = x - len;
  return getHsh(1, rst) == getHsh(x - rst + 1, x);
}

void solve() {
  hsh[0] = 0;
  for (int i = 1; i <= n; ++i) hsh[i] = hsh[i - 1] * P + s[i];
  
  memset(cnt, 0, sizeof(cnt));
  memset(suf, 0, sizeof(suf));
  for (int i = n; i; --i) {
    ++cnt[s[i] - 'a'];
    suf[i] = suf[i + 1] + (cnt[s[i] - 'a'] % 2 ? 1 : -1);
  }
  
  memset(cnt, 0, sizeof(cnt));
  memset(f, 0, sizeof(f));
  memset(S, 0, sizeof(S));

  LL ans = 0; ++cnt[s[1] - 'a'], f[1] = 1;
  for (int i = 1; i <= 26; ++i) ++S[i];
  for (int j = 2; j < n; ++j) {
    ++cnt[s[j] - 'a'];
    f[j] = f[j - 1] + (cnt[s[j] - 'a'] % 2 ? 1 : -1);
    for (int i = 1; i * j < n; ++i) {
      if (chk(i * j, j)) ans += S[suf[i * j + 1]];
    }
    for (int i = f[j]; i <= 26; ++i) ++S[i];
  }
  printf("%lld\n", ans);
}

}

int main() {
  enablefileIO();
  int t; scanf("%d", &t);

  while (t--) {
    init();
  
    if (n <= 500) {
      brute2::solve();
    } else {
      solver::solve();
    }
  }
  return 0;
}
