#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 500005
#define maxk 15
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;

template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

const int mod = 1000000007;
int n, k, w[maxk], wmax, c[maxn], d[maxn];

namespace task1 {
  bool check() {
    return (wmax <= 3 && k <= 5) || (wmax <= 10 && k <= 3);
  }
  
  vector<int> a, oneT, cur;
  
  int calc() {
    cur = a;
    for (int i = 1; i <= n; i++) {
      cur[c[i]] += d[i];
      if (cur[c[i]] < 1 || cur[c[i]] > w[c[i]])
        return i;
    }
    oneT = cur;
    if (oneT == a) {
      puts("-1");
      exit(0);
    }
    int res = 0;
    while (++res) {
      int i = (res - 1) % n + 1;
      cur[c[i]] += d[i];
      if (cur[c[i]] < 1 || cur[c[i]] > w[c[i]])
        return res + n;
    }
  }
  
  void solve() {
    a.resize(k + 1), oneT.resize(k + 1), cur.resize(k + 1);
    int tot = 1;
    for (int i = 1; i <= k; i++) tot *= w[i];
    
    int ans = 0;
    for (int st = 0; st < tot; st++) {
      int tmp = st;
      for (int i = 1; i <= k; i++) {
        a[i] = tmp % w[i] + 1;
        tmp /= w[i];
      }
      (ans += calc()) %= mod;
    }
    
    printf("%d\n", ans);
  }
}

namespace task2 {
  const int DELTA = 500001;
  int reach[maxn << 1]; // reach[i + DELTA]: 在一个周期中，首次到达位移i的是第几步.
  int upReach, downReach, survive[100005], x; // x: 一个周期的位移. 
  
  bool check() {
    return wmax <= 100000 && n <= 100000 && k == 1;
  }
  
  int calc_survive(int cur) {
    if (survive[cur])
      return survive[cur];
    if (cur + downReach < 1)
      return survive[cur] = reach[-cur + DELTA];
    if (cur + upReach > w[1])
      return survive[cur] = reach[w[1] + 1 - cur + DELTA];
    if (x == 0)
      return survive[cur] = -1;
    return survive[cur] = (calc_survive(cur + x) + n) % mod;
  }
  
  void solve() {
    memset(reach, 0x3f, sizeof(reach));
    reach[0] = 0;
    for (int i = 1; i <= n; i++) {
      x += d[i];
      chmax(upReach, x);
      chmin(downReach, x);
      chmin(reach[x + DELTA], i);
    }
    int ans = 0;
    for (int i = 1; i <= w[1]; i++) {
      calc_survive(i);
      if (survive[i] == -1) {
        puts("-1");
        return;
      }
      (ans += survive[i]) %= mod;
    }
    printf("%d\n", ans);
  }
}

/*
其它维上出界时间 >= 该维上出界时间
*/ 
namespace task3 {
  bool check() {
    return wmax <= 1000000;
  }
  
  const int DELTA = 500001;
  int reach[maxn << 1]; // reach[i + DELTA]: 在一个周期中，首次到达位移i的是第几步.
  int upReach, downReach, survive[11][1000005], x; // x: 一个周期的位移. 
  
  int calc_survive(int i, int cur) {
    if (survive[i][cur])
      return survive[i][cur];
    if (cur + downReach < 1)
      return survive[i][cur] = reach[-cur + DELTA];
    if (cur + upReach > w[i])
      return survive[i][cur] = reach[w[1] + 1 - cur + DELTA];
    if (x == 0)
      return survive[i][cur] = mod + 1;
    return survive[i][cur] = (calc_survive(i, cur + x) + n) % mod;
  }
  
  int ptr[maxk];
  
  void solve() {
    for (int i = 1; i <= k; i++) {
      memset(reach, 0x3f, sizeof(reach));
      reach[0] = upReach = downReach = x = 0;
      for (int j = 1; j <= n; j++) {
        if (c[j] == i) {
          x += d[j];
          chmax(upReach, x);
          chmin(downReach, x);
          chmin(reach[x + DELTA], j);
        }
      }
      for (int j = 1; j <= w[i]; j++)
        calc_survive(i, j);
      sort(survive[i] + 1, survive[i] + w[i] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
      memset(ptr, 0, sizeof(ptr));
      for (int j = 1; j <= w[i]; j++) {
        int cnt = 1;
        for (int ii = 1; ii <= k; ii++) {
          if (ii == i) continue;
          while (ptr[ii] < w[ii] && survive[ii][ptr[ii] + 1] < survive[i][j])
            ++ptr[ii];
          cnt = (ll)cnt * (w[ii] - ptr[ii]) % mod;
        }
        if (survive[i][j] > mod && cnt) {
          puts("-1");
          return;
        }
        ans = (ans + (ll)cnt * survive[i][j]) % mod;
      }
    }
    printf("%d\n", ans);
  }
}

int main() {
  freopen("walk.in", "r", stdin);
  freopen("walk.out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", w + i);
    chmax(wmax, w[i]);
  }
  for (int i = 1; i <= n; i++)
    scanf("%d%d", c + i, d + i);
  
  if (task1::check())
    task1::solve();
  else if (task2::check())
    task2::solve();
  else if (task3::check())
    task3::solve();
  
//  task3::solve();
  return 0;
}
