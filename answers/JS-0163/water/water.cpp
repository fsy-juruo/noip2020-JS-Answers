#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

#define LOG(msg) //cout << msg << endl

using namespace std;

int gcd(int a, int b) {
    if (a == b || b == 0) return a;
    return gcd(b, a % b);
}

struct frac {
    ull u, d;

    frac() : u(0), d(1) {  }
    frac(ull uu, ull dd) : u(uu), d(dd) { update(); }
    frac(ull uu, ull dd, int c) : u(uu), d(dd) { }

    frac update() {
        ll t = gcd(d, u);
        u /= t, d /= t;
        return *this;
    }

    void print() {
        cout << u << " " << d;
    }

    frac operator+(frac b) {
        LOG("adding: ");
        //print(); cout << "\t+\t"; b.print(); cout << endl;
        if (b.u == 0) return *this;
        if (u == 0) return b;
        if (b.d == d) return frac(u + b.u, d);
        else
            return frac(u * b.d, d * b.d, 1) + frac(b.u * d, b.d * d, 1);
    }

    frac operator+=(frac b) {
        return *this = *this + b;
    }

    frac operator/(ull c) {
        d *= c;
        return update();
    }
};

ll rd() {
    ll ans = 0, t = 0, c = 1;
    while (!isdigit(t = getchar())) if (t == '-') c = -1;
    do ans = ans * 10 + (t - '0');
    while (isdigit(t = getchar()));
    return ans * c;
}

ll urd() {
    ll ans = 0, t = 0;
    while (!isdigit(t = getchar()));
    do ans = ans * 10 + (t - '0');
    while (isdigit(t = getchar()));
    return ans;
}

unsigned next[10000][10000];
map<int, frac> ed;

unsigned n, m;

void s(int f) {
    stack<int> v;
    stack<frac> flow;
    v.push(f);
    flow.push(frac(1, 1));
    while (!v.empty()) {
        frac cur = flow.top();
        int curV = v.top();
        if (next[curV][0] == 0) {
            LOG("End at " << (curV + 1));
            ed[curV] += cur;
            v.pop();
            flow.pop();
            continue;
        }
        LOG("At " << (curV + 1) << "\tnow: ");
        //cur.print(); LOG("  ");
        frac nx = cur / next[curV][0];
        v.pop();
        flow.pop();
        for (unsigned i = 1u; i <= next[curV][0]; i++) {
            v.push(next[curV][i]);
            flow.push(nx);
        }
    }
}

int main() {
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
    n = urd(), m = urd();
    for (unsigned i = 0; i < n; i++) {
        unsigned dd = next[i][0] = urd();
        if (dd == 0) ed[i] = frac();
        for (unsigned j = 1; j <= dd; j++)
            next[i][j] = urd() - 1;
    }
    for (unsigned i = 0; i < m; i++) s(i);
    for (map<int, frac>::iterator it = ed.begin(); it != ed.end(); it++) {
        it->second.print();
        putchar('\n');
    }
    return 0;
}
