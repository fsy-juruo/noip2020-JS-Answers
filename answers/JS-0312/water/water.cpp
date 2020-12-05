#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 100005
#define mp make_pair

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<ll, ll> P;

ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

int n, m;
vector<int> adj[maxn];
int inDeg[maxn], topo[maxn];
P f[maxn];

void fracPlus(P &x, const P &y) {
  ll d = gcd(x.second, y.second);
  P res;
  res.second = x.second / d * y.second;
  res.first = x.first * (y.second / d) + (x.second / d) * y.first;
  x = res;
}

int main() {
  freopen("water.in", "r", stdin);
  freopen("water.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int d;
    scanf("%d", &d);
    for (int j = 1; j <= d; j++) {
      int a;
      scanf("%d", &a);
      adj[i].push_back(a);
      ++inDeg[a];
    }
  }
  
  queue<int> que;
  for (int i = 1; i <= n; i++)
    if (!inDeg[i])
      que.push(i);
  for (int i = 1; i <= n; i++) {
    int u = que.front();
    que.pop();
    topo[i] = u;
    for (int j = 0; j < (int)adj[u].size(); j++) {
      int v = adj[u][j];
      --inDeg[v];
      if (!inDeg[v])
        que.push(v);
    }
  }
  for (int i = 1; i <= n; i++)
    f[i] = mp(i <= m, 1);
  for (int i = 1; i <= n; i++) {
    int u = topo[i];
    if (adj[u].empty()) continue;
    for (int j = 0; j < (int)adj[u].size(); j++) {
      int v = adj[u][j];
      P tmp = mp(f[u].first, f[u].second * (int)adj[u].size());
      fracPlus(f[v], tmp);
    }
    f[u] = mp(0, 1);
  }
  
  for (int i = 1; i <= n; i++) {
    if (adj[i].empty()) {
      ll d = gcd(f[i].first, f[i].second);
      printf("%lld %lld\n", f[i].first / d, f[i].second / d);
    }
  }
  return 0;
}

