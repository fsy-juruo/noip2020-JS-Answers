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
  unsigned char f = 0;
  while (ch < 33) ch = gc;
  if (ch == '-') f = 1, ch = gc;
  while (ch > 47) x = x * 10 + ch - 48, ch = gc;
  return f ? -x : x;
}
inline int uread(void) {
  int x = 0;
  register char ch = gc;
  while (ch < 48) ch = gc;
  while (ch > 47) x = x * 10 + ch - 48, ch = gc;
  return x;
}

static const int Maxn = 5e5 + 5, Maxk = 11;

int n, K;
int W[Maxk];
int kw[Maxn], dir[Maxn];
int ka[Maxk], kax[Maxk], kay[Maxk];

namespace solution1 {

int a[6], b[6];
int ans = 0;
void alv() {
  int res = 0;
  memcpy(b, a, sizeof(a));
  for (int i = 1; i <= n; i = i % n + 1) {
    b[kw[i]] += dir[i]; ++res;
    if (b[kw[i]] < 1 || b[kw[i]] > W[kw[i]]) break;
  }
  ans += res;
}

void dfs(int x) {
  if (x == K + 1) {
    alv();
    return ;
  }
  for (int i = 1; i <= W[x]; ++i) {
    a[x] = i;
    dfs(x + 1);
  }
}

int main() {
  dfs(1);
  printf("%d\n", ans);
  eprintf("ans = %d\n", ans);
  return 0;
}
  
}

namespace solution2 {
  
int main() {
}
  
}

int main() {

  freopen("walk.in", "r", stdin);
  freopen("walk.out", "w", stdout);

  n = uread(), K = uread();
  for (int i = 1; i <= K; ++i) W[i] = read();
  for (int i = 1; i <= n; ++i) {
    kw[i] = uread(), dir[i] = read();
    ka[kw[i]] += dir[i];
    kax[kw[i]] = max(kax[kw[i]], ka[kw[i]]);
    kay[kw[i]] = max(kay[kw[i]], ka[kw[i]]);
  }
  if (n <= 100 && K <= 5 && *max_element(W + 1, W + K + 1) <= 10) {
    solution1::main();
    return 0;
  }
  if (n <= 100000 && K == 1) {
    solution2::main();
    return 0;
  }

  return 0;

}

