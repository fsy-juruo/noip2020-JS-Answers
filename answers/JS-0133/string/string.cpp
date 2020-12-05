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
void reads(char *s) {
  register char ch = gc;
  while (ch < 33) ch = gc;
  while (ch > 32) *s++ = ch, ch = gc;
}

static const int Maxn = (1 << 20) + 5;
typedef unsigned long long hash_t;
static const hash_t BASE = 29;
static const hash_t mod[2] = {1e9 + 7, 1e9 + 9};

int n;
char str[Maxn];
int pre[Maxn], suf[Maxn];
int cnt[26], odd;
hash_t pw[2][Maxn];
hash_t hs[2][Maxn];
int bit[Maxn];
inline void add(int x, int v) {
  ++x;
  while (x < Maxn) bit[x] += v, x += x & -x;
}
inline int ask(int x) {
  int res = 0; ++x;
  while (x) res += bit[x], x -= x & -x;
  return res;
}
void hash_init() {
  pw[0][0] = pw[1][0] = 1;
  for (int i = 1; i < Maxn; ++i) {
    pw[0][i] = pw[0][i - 1] * BASE % mod[0];
    pw[1][i] = pw[1][i - 1] * BASE % mod[1];
  }
}
inline hash_t get_hash(int id, int l, int r) {
  return (hs[id][r] - hs[id][l - 1] * pw[id][r - l + 1] % mod[id] + mod[id]) % mod[id];
}
inline bool equal(int l1, int r1, int l2, int r2) {
  return get_hash(0, l1, r1) == get_hash(0, l2, r2) && get_hash(1, l1, r1) == get_hash(1, l2, r2);
}

void Main() {
  reads(str + 1);
  n = strlen(str + 1);
  memset(cnt, 0, sizeof(cnt));
  odd = 0;
  for (int i = 1; i <= n; ++i) {
    int ch = str[i] - 'a';
    odd -= (cnt[ch] % 2 == 1);
    cnt[ch]++;
    odd += (cnt[ch] % 2 == 1);
    pre[i] = odd;
  }
  memset(cnt, 0, sizeof(cnt));
  odd = 0;
  for (int i = n; i >= 1; --i) {
    int ch = str[i] - 'a';
    odd -= (cnt[ch] % 2 == 1);
    cnt[ch]++;
    odd += (cnt[ch] % 2 == 1);
    suf[i] = odd;
  }
  hs[0][0] = hs[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int ch = str[i] - 'a';
    hs[0][i] = (hs[0][i - 1] * BASE + ch) % mod[0];
    hs[1][i] = (hs[1][i - 1] * BASE + ch) % mod[1];
  }
  memset(bit, 0, sizeof(bit));
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    if (i != 1) {
      long long res = 0;
      for (int R = i; R < n; R += i) {
        if (!equal(1, i, R - i + 1, R)) break;
        res += ask(suf[R + 1]);
      }
      ans += res;
    }
    add(pre[i], 1);
  }
  printf("%lld\n", ans);
  eprintf("ans = %lld\n", ans);
}

int main() {

  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);

  int tests = read();
  hash_init();
  while (tests--) Main();

  return 0;

}

