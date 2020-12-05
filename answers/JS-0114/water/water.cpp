#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
vector<int> e[MAXN];
int outlist[MAXN], outcnt(0);
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
struct Number {
    ll a, b;
    Number() {a = 0; b = 1;}
    Number(ll a, ll b) : a(a), b(b) {}
    Number operator + (const Number& x) const {
        if(a == 0) return Number(x.a, x.b);
        if(x.a == 0) return Number(a, b);
        ll na = a * x.b + b * x.a;
        ll nb = b * x.b;
        ll g = gcd(na, nb);
        return Number(na/g, nb/g);
    }
    Number operator / (const Number& x) const {
        if(a == 0) return Number();
        ll g1 = gcd(a, x.a);
        ll g2 = gcd(b, x.b);
        return Number(a/g1*x.b/g2, b/g2*x.a/g1);
    }
    Number operator / (ll x) const {
        if(a == 0) return Number();
        ll g = gcd(a, x);
        return Number(a/g, x/g*b);
    }
} ans[MAXN];
void dfs(int u) {
    int sz = e[u].size();
    if(sz == 0) return;
    Number ad = ans[u] / sz;
    ans[u].a = 0, ans[u].b = 1;
    for(int i = 0; i < sz; i++) {
        int& v = e[u][i];
        ans[v] = ans[v] + ad;
        dfs(v);
    }
}
int main() {
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) { // start from 1
        int x;
        scanf("%d", &x);
        for(int j = 0; j < x; j++) {
            int v;
            scanf("%d", &v); e[i].push_back(v);
        }
        if(x == 0) outlist[outcnt++] = i;
    }
    for(int i = 1; i <= m; i++) ans[i] = Number(1, 1);
    for(int i = 1; i <= m; i++) if(ans[i].a) dfs(i);
    for(int i = 0; i < outcnt; i++) printf("%lld %lld\n", ans[outlist[i]].a, ans[outlist[i]].b);
    return 0;
}
