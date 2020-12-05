#define mp make_pair
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll a, ll b) {
  if(a < b) swap(a, b);
  if(a % b == 0) return b;
  return GCD(b, a % b);
}
struct Frac {
  ll p, q;
  Frac() { q = 1; }
  Frac(ll x)
  : p(x), q(1) { }
  Frac(ll a, ll b)
  : p(a), q(b) {
    if(p) {
      ll G = GCD(p, q);
      p /= G; q /= G;
    }
  }
  void maintain() {
    if(!p) { q = 1; return; }
    ll G = GCD(p, q);
    p /= G;
    q /= G;
  }
  Frac operator + (const Frac& x) const {
    ll p1 = p, q1 = q, p2 = x.p, q2 = x.q;
    return Frac(p1 * q2 + p2 * q1, q1 * q2);
  }
  Frac operator / (const ll& x) const {
    return Frac(p, q * x);
  }
  void print() {
    printf("%lld %lld\n", p, q);
  }
};
typedef pair<ll, ll> PII;
const ll MAXN = 100000 + 10, MAXM = 10 + 5;
ll n, m;
vector<ll> e[MAXN], ve[MAXN];
ll d[MAXN];
Frac V[MAXN];
int main() {
  freopen("water.in", "r", stdin);
  freopen("water.out", "w", stdout);
  scanf("%lld%lld", &n, &m);
  for(ll i = 1; i <= n; i++) {
    if(i <= m) V[i] = Frac(1, 1);
    scanf("%lld", d + i);
    for(ll j = 0; j < d[i]; j++) {
      ll tmp; scanf("%lld", &tmp);
      e[i].push_back(tmp);
      ve[tmp].push_back(i);
    }
  }
  queue<ll> Q;
  for(int i = 1; i <= m; i++) Q.push(i);
  while(!Q.empty()) {
    ll t = Q.front();
    Q.pop();
    Frac Vt = V[t];
    for(ll i = 0; i < d[t]; i++) {
      V[e[t][i]] = V[e[t][i]] + (Vt / d[t]);
      Q.push(e[t][i]);
      V[t] = Frac(0, 1);
    }
  }
  for(ll i = 1; i <= n; i++) { 
    if(!d[i]) V[i].print();
  }
  putchar('\n');
  return 0;
}

