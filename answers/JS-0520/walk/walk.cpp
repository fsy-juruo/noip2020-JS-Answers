#include <bits/stdc++.h>

using namespace std;

int n, k;
long long w[20], c[500010], d[500010];
long long maxi[20], mini[20], fi[20];

long long st[20], now[20];

long long res;

void cwork(void) {
    for (int i = 1; i <= k; ++i) {
        now[i] = st[i];
    }

//    cerr << k << endl;
//    for (int i = 1; i <= k; ++i) {
//        cerr << st[i] << ' ';
//    }
//    cerr << endl;
    long long num_turn = LLONG_MAX / 2;
    for (int i = 1; i <= k; ++i) {
        if (st[i] + maxi[i] > w[i] || st[i] + mini[i] < 1) {
            num_turn = 0;
            break;
        }

        if (fi[i] > 0) {
            num_turn = min(num_turn, (w[i] - maxi[i] - st[i]) / fi[i] + 1);
//            cerr << "1: " << i << ' ' << num_turn << endl;
        }
        if (fi[i] < 0) {
            num_turn = min(num_turn, (st[i] + mini[i]) / abs(fi[i]) + 1);
//            cerr << "2: " << i << ' ' << num_turn << endl;
        }
    }
//    cerr << num_turn << endl;

    if (num_turn > LLONG_MAX / 4) {
        puts("-1");
        exit(0);
    }

    for (int i = 1; i <= k; ++i) {
        now[i] += fi[i] * num_turn;
    }

    long long tot = num_turn * n;
    for (int i = 1; i <= n; ++i) {
        now[c[i]] += d[i];
        ++tot;
        if (now[c[i]] > w[c[i]] || now[c[i]] < 1) {
            break;
        }
    }
    res += tot;
}

void dfs(int kk) {
    if (kk > k) {
        cwork();
        return;
    }
    for (long long i = 1; i <= w[kk]; ++i) {
        st[kk] = i;
        dfs(kk + 1);
    }
}

int main(void) {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%lld", &w[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &c[i], &d[i]);
    }

    for (int i = 1; i <= n; ++i) {
        fi[c[i]] += d[i];
        maxi[c[i]] = max(maxi[c[i]], fi[c[i]]);
        mini[c[i]] = min(mini[c[i]], fi[c[i]]);
    }

    dfs(1);

    printf("%lld\n", res);

	return 0;
}

