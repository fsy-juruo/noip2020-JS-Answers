#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int nxt, to;
};

struct Node {
  long long deno, nume;
};

int n, m;
int tot, head[100043], indeg[100043], outdeg[100043];
Edge e[1000043];
Node val[100043];

void AddEdge(int u, int v) {
  ++tot; e[tot].nxt = head[u]; e[tot].to = v; head[u] = tot; ++outdeg[u]; ++indeg[v];
}

long long Gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return Gcd(b, a % b);
}

void Bfs() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (indeg[i] == 0) {
      q.push(i);
      val[i].deno = 1; val[i].nume = 1;
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    long long ndeno = val[u].deno, nnume = val[u].nume * outdeg[u];
    for (int i = head[u]; i > 0; i = e[i].nxt) {
      int v = e[i].to;
      if (val[v].deno == 0 || val[v].nume == 0) {
        val[v].deno = ndeno; val[v].nume = nnume;
      } else {
        long long temp = Gcd(val[v].nume, nnume);
        long long down = val[v].nume * nnume / temp;
        long long up = down / val[v].nume * val[v].deno + down / nnume * ndeno;
        val[v].deno = up; val[v].nume = down;
        temp = Gcd(val[v].deno, val[v].nume);
        val[v].deno /= temp; val[v].nume /= temp;
      }
      if (--indeg[v] == 0) {
        q.push(v);
      }
    }
  }
}

int main() {
  freopen("water.in", "r", stdin);
  freopen("water.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int d;
    scanf("%d", &d);
    for (int j = 1; j <= d; ++j) {
      int x;
      scanf("%d", &x);
      AddEdge(i, x);
    }
  }
  Bfs();
  for (int i = 1; i <= n; ++i) {
    long long temp = Gcd(val[i].deno, val[i].nume);
    val[i].deno /= temp; val[i].nume /= temp;
    if (outdeg[i] == 0) {
      printf("%lld %lld\n", val[i].deno, val[i].nume);
    }
  }
  return 0;
}

