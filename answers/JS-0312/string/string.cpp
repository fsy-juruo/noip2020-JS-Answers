#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 1048585
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;

const int B = 101;
int n;
char s[maxn];
ull powb[maxn], prefixHash[maxn];
int cnt[35], fpre[maxn], fsuf[maxn];
int bit[35];

void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (n <= 2) {
    puts("0");
    return;
  }
  powb[0] = 1;
  for (int i = 1; i <= n; i++) {
    powb[i] = powb[i - 1] * B;
    prefixHash[i] = ull(s[i] - 'a') * powb[i - 1] + prefixHash[i - 1];
  }
  memset(cnt, 0, sizeof(cnt));
  fpre[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[s[i] - 'a'])
      fpre[i] = fpre[i - 1] - 1;
    else
      fpre[i] = fpre[i - 1] + 1;
    cnt[s[i] - 'a'] ^= 1;
  }
  memset(cnt, 0, sizeof(cnt));
  fsuf[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    if (cnt[s[i] - 'a'])
      fsuf[i] = fsuf[i + 1] - 1;
    else
      fsuf[i] = fsuf[i + 1] + 1;
    cnt[s[i] - 'a'] ^= 1;
  }
  memset(bit, 0, sizeof(bit));
  ll ans = 0;
  for (int i = 2; i < n; i++) {
    for (int j = fpre[i - 1]; j <= 26; j++)
      bit[j]++;
    ull coe = 0;
    for (int j = 1; j * i < n; j++) { // ÖØ¸´´ÎÊý 
      coe += powb[(j - 1) * i];
      if (prefixHash[i] * coe == prefixHash[j * i]) {
        ans += bit[fsuf[j * i + 1]];
      }
    }
  }
  printf("%lld\n", ans);
}

int main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--)
    solve();
  return 0;
}

