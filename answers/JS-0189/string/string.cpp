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

int count_bits(unsigned x) {
    x = (x & 0x55555555) + ((x & 0xAAAAAAAA) >>  1);
    x = (x & 0x33333333) + ((x & 0xCCCCCCCC) >>  2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >>  4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >>  8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

char s[1000005];
int n;
int precnt[1000005][30];
int premask[1000005];
int sufcnt[1000005];
int sufmask[1000005];
int z[1000005];

void calc_z() {
    for (int i = 1, l = 0, r = 0; i < n; ++ i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]); else z[i] = 0;
        for (; i + z[i] < n && s[z[i]] == s[i + z[i]]; ++ z[i]);
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
}

void solve() {
    scanf("%s", s);
    n = strlen(s);
    calc_z();
    premask[0] = 0;
    rep(i, n) {
        premask[i + 1] = premask[i];
        premask[i + 1] ^= 1 << (s[i] - 'a');
        memcpy(precnt[i + 1], precnt[i], sizeof(precnt[i]));
        register int j = count_bits(premask[i + 1]) + 1;
        while (j <= 26) ++ precnt[i + 1][j], j += j & -j;
    }
    sufmask[n] = 0;
    for (int i = n - 1; ~i; -- i) {
        sufmask[i] = sufmask[i + 1];
        sufmask[i] ^= 1 << (s[i] - 'a');
        sufcnt[i] = count_bits(sufmask[i]);
    }
    ll ans = 0;
    for (int AB = 2; AB < n; ++ AB) {
        int *sum = precnt[AB - 1];
        for (int ABAB = AB; ABAB <= AB + z[AB] && ABAB < n; ABAB += AB) {
            register int x = sufcnt[ABAB] + 1;
            while (x) ans += sum[x], x -= x & -x;
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T;
    read(T);
    while (T --) solve();
    return 0;
}
