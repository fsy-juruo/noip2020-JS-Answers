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

const int mod = 1000000007;

struct Move {
    int c, d;
};

const int inf = 0x3f3f3f3f;

int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

struct State {
    int pre, minpre, maxpre;
    State(): pre(), minpre(), maxpre() {}
    State(int x): pre(x), minpre(min(0, x)), maxpre(max(0, x)) {}
    State(int p, int mn, int mx): pre(p), minpre(mn), maxpre(mx) {}
    inline State operator + (const State &o) const {
        return State(
            max(-inf, min(+inf, pre + o.pre)),
            max(-inf, min(minpre, pre + o.minpre)),
            min(+inf, max(maxpre, pre + o.maxpre))
        );
    }
};

int n, k, u[15];
Move mov[500005];
State pre[500005];
State bl[25];
ll f[15][1000005];
int ptr[15];
bool flag;

#define pii pair <ll, int>

priority_queue <pii, vector <pii>, greater <pii> > pq;

void solve(int d) {
    pre[0] = State();
    rep(i, n) pre[i + 1] = pre[i] + State(mov[i].c == d ? mov[i].d : 0);
    bl[0] = pre[n];
    rep(i, 20) bl[i + 1] = bl[i] + bl[i];
    rep(i, u[d]) {
        int runs = 0;
        State cur = State();
        for (int j = 20; ~j; -- j) {
            State nw = cur + bl[j];
            if (nw.minpre + i >= 0 && nw.maxpre + i < u[d]) {
                runs += 1 << j;
                cur = nw;
            }
        }
        int lb = 0, rb = n - 1;
        while (lb < rb) {
            int md = (lb + rb + 1) >> 1;
            State nw = cur + pre[md];
            if (nw.minpre + i >= 0 && nw.maxpre + i < u[d])
                lb = md;
            else
                rb = md - 1;
        }
        State nw = cur + pre[lb + 1];
        if (nw.minpre + i >= 0 && nw.maxpre + i < u[d])
            f[d][i] = 1LL << 60, flag = 1;
        else
            f[d][i] = 1LL * runs * n + lb + 1;
    }
    stable_sort(f[d], f[d] + u[d]);
}

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    read(n), read(k);
    rep(i, k) read(u[i]);
    rep(i, n) {
        read(mov[i].c), read(mov[i].d);
        -- mov[i].c;
    }
    bool hav = 0;
    rep(i, k) {
        flag = 0;
        solve(i);
        if (!flag) hav = 1;
    }
    if (!hav) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, k) ptr[i] = 0, pq.push(mp(f[i][ptr[i]], i));
    int ans = 0;
    while (!pq.empty()) {
        int i = pq.top().second; pq.pop();
        int cur = f[i][ptr[i]] % mod;
        rep(j, k) if (i != j) cur = 1LL * cur * (u[j] - ptr[j]) % mod;
        if (f[i][ptr[i]] < (1LL << 60)) (ans += cur) %= mod;
        ptr[i] ++;
        if (ptr[i] < u[i]) pq.push(mp(f[i][ptr[i]], i));
    }
    cout << ans << endl;
    return 0;
}
