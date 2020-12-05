#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
ll urd() {
    ll ans = 0, t = 0;
    while (!isdigit(t = getchar()));
    do ans = ans * 10 + (t - '0');
    while (isdigit(t = getchar()));
    return ans;
}

int l[51][20000], sz[51], n, m, tt;

struct step {
    int from, to;

    step(int f, int t) : from(f), to(t) { }
} ss[82000];

int main()
{
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            l[i][sz[i]++] = urd();
    for (int i = m - 1; i >= 0; i--) {
        if (l[2][i] == 2) {
            sz[2]--, sz[0]++;
            ss[tt++] = step(2, 3);
        } else {
            sz[2]--, sz[1]++;
            ss[tt++] = step(2, 1);
        }
    }
    for (int i = sz[0] - 1; i >= 0; i--) {
        ss[tt++] = step(3, 2);
        sz[0]--;
    }
    for (int i = sz[1] - 1; i >= 0; i--) {
        if (l[1][i] == 2) {
            sz[1]--, sz[0]++;
            ss[tt++] = step(1, 3);
        } else {
            sz[1]--, sz[2]++;
            ss[tt++] = step(1, 2);
        }
    }
    for (int i = sz[0] - 1; i >= 0; i--) {
        ss[tt++] = step(3, 1);
    }
    cout << (tt - 1) << endl;
    for (int i = 0; i < tt; i++) {
        cout << ss[i].from << ss[i].to << endl;;
    }
    return 0;
}
