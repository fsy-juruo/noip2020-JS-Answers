#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

#define LOG(msg) //cout << msg << endl

using namespace std;

int k, n;
struct cd {
    int cord[11];

    cd() { memset(cord, 0, sizeof(int) * 11); }

    cd operator+(cd b) {
        cd ans = *this;
        for (int i = 1; i <= k; i++)
            ans.cord[i] += b.cord[i];
        return ans;
    }
    cd operator+=(cd b) {
        for (int i = 1; i <= k; i++)
            cord[i] += b.cord[i];
        return *this;
    }
} now, last, dir[500000], w;

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

bool check(cd pt) {
    for (int i = 1; i <= k; i++)
        if (pt.cord[i] >= w.cord[i] || pt.cord[i] < 0)
            return false;
    return true;
}

int from(cd start) {
    int steps = 0;
    int idx = 0;
    while (check(start)) {
        start += dir[idx];
        steps++, idx++, idx %= n;
    }
    return steps;
}

int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    n = urd(), k = urd();
    for (int i = 1; i <= k; i++)
        w.cord[i] = urd();
    for (int i = 0; i < n; i++) {
        int idx = urd(), d = rd();
        dir[i].cord[idx] += d;
    }
    cd pt = cd();
    int ans = 0;
    while(pt.cord[k] <= w.cord[k]) {
        ans += from(pt);
        pt.cord[1]++;
        for (int i = 1; i < k; i++)
            pt.cord[i + 1] += pt.cord[i] / w.cord[i],
            pt.cord[i] %= w.cord[i];
    }
    cout << ans << endl;
    return 0;
}
