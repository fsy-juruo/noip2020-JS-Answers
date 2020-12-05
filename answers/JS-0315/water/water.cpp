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
const int N = 100010;
vector<int> g[N], revg[N];
LL gcd(LL x, LL y) {
  if (x > y) swap(x, y);
  if (y % x == 0) return x;
  return gcd(y % x, x);
}
int d[N], n, m, ind[N], finalnode[N];
struct Fraction {
  LL p, q;
  Fraction(LL p = 0, LL q = 1) : p(p), q(q) {}
  void normalize() {
    if (p == 0) return;
    if (gcd(p, q) == 1) return;
    int qwq = gcd(p, q);
    p /= qwq;
    q /= qwq;
  }
  void print() {
    normalize();
    cout << p << ' ' << q << endl;
  }
  void set(LL agp, LL agq) {
  //  eprintf("%d %d\n", agp, agq);
    p = agp;
    q = agq;
    normalize();
  }
};
Fraction inc(Fraction& a, const Fraction& b) {
  Fraction cur;
//  eprintf("%d %d", a.p, a.q);
  cur.p = a.p * b.q + a.q * b.p;
//  eprintf(" (%d) ", cur.p);
  cur.q = a.q * b.q;
  cur.normalize();
  a = cur;
 // eprintf(" -> %d %d\n", a.p, a.q);
  return cur;
}
Fraction tot[N];
vector<int> seq;
void topo() {
  queue<int> q;
  repn(i, n) if (!ind[i]) {
    q.push(i);
    break;
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    seq.push_back(u);
    rep(i, g[u].size()) {
      int v = g[u][i];
      ind[v]--;
      if (ind[v] == 0) {
        q.push(v);
      }
    }
  }
 // rep(i, seq.size()) eprintf("%d ", seq[i]);
 // eprintf("\n");
}
namespace subtask1 {
void solve() {
  topo();
//  eprintf("topo!\n");
  int src = seq[0];
//  eprintf("%d\n", src);
  tot[src].set(1, 1);
  rep(i, seq.size()) {
    int u = seq[i];
//    eprintf("%d\n", u);
    rep(idx, revg[u].size()) {
      int v = revg[u][idx];
      Fraction delt = tot[v];
      int p = delt.p, q = delt.q;
      delt.set(p, q * d[v]);
      inc(tot[u], delt);
    }
  }
  repn(i, n) {
    if (finalnode[i]) tot[i].print();
  }
}
}
int main() {
#ifndef CHTHOLLY
  freopen("water.in", "r", stdin);
  freopen("water.out", "w", stdout);
#endif
  rd(n); rd(m);
  repn(i, n) {
    rd(d[i]);
    rep(j, d[i]) {
      int v;
      rd(v);
      g[i].push_back(v);
      ind[v]++;
      revg[v].push_back(i);
    }
    if (!d[i]) finalnode[i] = true;
  }
  if (m == 1) subtask1::solve();
  else subtask1::solve();
  return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/

