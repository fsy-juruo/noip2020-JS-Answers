#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int n, K;
int w[43];
int c[500043], d[500043];
int f[43], a[43];
long long ans;

void Dfs(int s) {
  if (s == K + 1) {
    for (int i = 1; i <= K; ++i) {
      a[i] = f[i];
    }
    bool flag = true;
    while (flag) {
      for (int i = 1; i <= n; ++i) {
        a[c[i]] += d[i];
        ++ans; ans %= MOD;
        if (a[c[i]] < 1 || a[c[i]] > w[c[i]]) {
          flag = false;
          break;
        }
      }
      bool mark = true;
      for (int i = 1; i <= K; ++i) {
        if (f[i] != a[i]) mark = false;
      }
      if (mark) {
        printf("-1\n");
        exit(0);
      }
    }
    return;
  }
  for (int i = 1; i <= w[s]; ++i) {
    f[s] = i;
    Dfs(s + 1);
  }
}

int main() {
  freopen("walk.in", "r", stdin);
  freopen("walk.out", "w", stdout);
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= K; ++i) {
    scanf("%d", &w[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &c[i], &d[i]);
  }
  Dfs(1);
  printf("%lld\n", ans);
  return 0;
}

