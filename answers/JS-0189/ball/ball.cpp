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

int n, m;
int a[55][405];
int top[55];
vector <pair <int, int> > op;

void mov(int x, int y) {
    a[y][top[y] ++] = a[x][-- top[x]];
    op.pb(mp(x, y));
}

void print() {
    printf("%d\n", (int) op.size());
    rep(i, op.size())
        printf("%d %d\n", op[i].first + 1, op[i].second + 1);
}

void DO(int trash, int emp, int v) {
    mov(trash, emp);
    rep(i, n + 1) if (i != trash && i != emp) {
        while (true) {
            int las = -1;
            rep(j, top[i]) if (a[i][j] == v) las = j;
            if (las == -1) break;
            for (int j = top[i] - 1; j > las; -- j) {
                bool threw = 0;
                rep(ni, n + 1) if (ni != i && ni != trash && ni != emp) {
                    if (top[ni] <= m - 1) {
                        mov(i, ni);
                        threw = 1;
                        break;
                    }
                }
                if (!threw) {
                    mov(i, emp);
                }
            }
            if (top[emp] == 0 || a[emp][top[emp] - 1] == v) {
                mov(i, emp);
            } else {
                mov(i, trash);
                while (top[emp] && a[emp][top[emp] - 1] != v) {
                    rep(ni, n + 1) if (ni != trash && ni != emp) {
                        if (top[ni] <= m - 1) {
                            mov(emp, ni);
                            break;
                        }
                    }
                }
                mov(trash, emp);
            }
        }
    }
    while (top[trash]) {
        if (a[trash][top[trash] - 1] == v) {
            mov(trash, emp);
            continue;
        }
        rep(i, n + 1) if (i != trash && i != emp) {
            if (top[i] <= m - 1) {
                mov(trash, i);
                break;
            }
        }
    }
}

int main() {
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    read(n), read(m);
    rep(i, n) {
        rep(j, m) read(a[i][j]);
        top[i] = m;
    }
    op.reserve(820000);
    rep(i, n) DO(i, !i ? n : i - 1, a[i][top[i] - 1]);
    print();
    return 0;
}
