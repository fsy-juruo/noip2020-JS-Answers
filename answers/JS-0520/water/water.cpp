#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Num {
    ll a, b;
};

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    if (a < b) {
        swap(a, b);
    }
    return gcd(b, a % b);
}

Num pls(Num a, Num b) {
    ll ta = a.a * b.b + b.a * a.b;
    ll tb = a.b * b.b;
    Num res;
    if (ta == 0) {
        res.a = 0;
        res.b = 1;
        return res;
    }
    ll g = gcd(ta, tb);
    res.a = ta / g;
    res.b = tb / g;
    return res;
}

int n, m;
vector<int> e[100010];
int in[100010];
vector<int> p;

Num w[100010];

void topo(void) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        p.push_back(u);
        for (int i = 0; i < e[u].size(); ++i) {
            int v = e[u][i];
            --in[v];
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main(void) {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        int d;
        scanf("%d", &d);
        while (d--) {
            int v;
            scanf("%d", &v);
            e[i].push_back(v);
            ++in[v];
        }
    }

    topo();

    for (int i = 1; i <= m; ++i) {
        w[i].a = w[i].b = 1;
    }
    for (int i = m + 1; i <= n; ++i) {
        w[i].a = 0;
        w[i].b = 1;
    }

    for (int i = 0; i < p.size(); ++i) {
        Num t = w[p[i]];
        t.b *= e[p[i]].size();
        Num t2;
        t2.a = 0;
        t2.b = 1;
        t = pls(t, t2);
        for (int j = 0; j < e[p[i]].size(); ++j) {
            int v = e[p[i]][j];
            w[v] = pls(w[v], t);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 0) {
            printf("%lld %lld\n", w[i].a, w[i].b);
        }
    }

	return 0;
}

