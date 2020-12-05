// Author: 23forever
#include <bits/stdc++.h>
const int MAXN = 100000;
typedef long long LL;
using namespace std;

void read(int &x) {
  x = 0; char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  }
}

void enablefileIO() {
  freopen("water.in", "r", stdin);
  freopen("water.out", "w", stdout);
}

int n, m;

LL gcd(LL x, LL y) {
  //cout << x << ' ' << y << endl;
  if (!y) return x;
  return gcd(y, x % y);
}

struct Frac {
  LL x, y;
  Frac(): x(0), y(1) {}
  Frac(LL _x, LL _y): x(_x), y(_y) {}
  
  Frac operator + (const Frac &rhs) const {
    LL co = y * rhs.y / gcd(y, rhs.y);
    Frac ret; ret.x = x * co / y + rhs.x * co / rhs.y, ret.y = co;
    return Frac(ret.x, ret.y); 
  }
  Frac operator += (const Frac &rhs) {
    return (*this) = (*this) + rhs;
  }
};

namespace graph {
const int MAXM = 1000000;
struct Edge {
  int to, nxt;
  Edge() {}
  Edge(int _to, int _nxt): to(_to), nxt(_nxt) {}
} edge[MAXM + 5];
int tot, head[MAXN + 5];

void init() {
  tot = 0, memset(head, -1, sizeof(head));
}

int in[MAXN + 5], out[MAXN + 5];
void addedge(int u, int v) {
  edge[tot] = Edge(v, head[u]), head[u] = tot++;
  ++in[v], ++out[u];
}

Frac res[MAXN + 5];
queue < int > que;

void topsort() {
  for (int i = 1; i <= m; ++i) {
    que.push(i), res[i] = Frac(1, 1);
  }
  
  while (!que.empty()) {
    int u = que.front(); que.pop();
    
    for (int i = head[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].to;
      
      LL x = res[u].x, y = res[u].y * out[u], g = gcd(x, y);
      res[v] += Frac(x / g, y / g);
      if (!--in[v]) que.push(v);
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    if (!out[i]) {
      LL x = res[i].x, y = res[i].y, g = gcd(x, y);
      printf("%lld %lld\n", x / g, y / g);
    }
  }
}

}

void init() {
  enablefileIO();
    
  read(n), read(m); graph::init();
  for (int i = 1; i <= n; ++i) {
    int d; read(d);
    for (int j = 1; j <= d; ++j) {
      int v; read(v);
      graph::addedge(i, v);
    }
  }
}

int main() {
  init();
  
  graph::topsort();
  return 0;
}
