#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

template <typename T> inline void read(T &x) {
    x = 0; bool f = 0; char c = getchar();
    while (c <= 32) c = getchar();
    if (c == 45) f = 1, c = getchar();
    while (c > 32) x = x * 10 + c - 48, c = getchar();
    if (f) x *= -1;
}

#define endl '\n'

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

struct Rat {
    ll a, b;
    Rat(ll a = 0, ll b = 1): a(a), b(b) {
        fix();
    }
    void fix() {
        ll g = gcd(a, b);
        a /= g, b /= g;
    }
    Rat operator + (const Rat &o) {
        Rat ans;
        ll g = gcd(b, o.b);
        ans.a = o.b / g * a + b / g * o.a;
        ans.b = b / g * o.b;
        ans.fix();
        return ans;
    }
};

int n, m;
vector <int> g[100005];
int deg[100005];
int que[100005], lb, rb;
Rat ans[100005];

int main() {
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
    read(n), read(m);
    rep(i, n) {
        int d;
        read(d);
        rep(j, d) {
            int to;
            read(to);
            -- to;
            g[i].pb(to);
            deg[to] ++;
        }
    }
    rep(i, n) if (!deg[i]) que[rb ++] = i;
    while (lb < rb) {
        int u = que[lb ++];
        rep(i, g[u].size()) {
            int v = g[u][i];
            if (-- deg[v] == 0) {
                que[rb ++] = v;
            }
        }
    }
    rep(i, m) ans[i] = 1;
    rep(id, n) {
        int u = que[id];
        rep(i, g[u].size()) {
            int v = g[u][i];
            ans[v] = ans[v] + Rat(ans[u].a, ans[u].b * g[u].size());
        }
    }
    rep(i, n) if (!g[i].size())
        cout << ans[i].a << " " << ans[i].b << endl;
    return 0;
}
