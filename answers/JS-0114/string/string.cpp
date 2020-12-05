#include <cstdio>
#include <cstring>
typedef unsigned long long ll;
const int MAXN = (1 << 20) + 3;
char a[MAXN];
int charset[30], preodd[MAXN], lastodd[MAXN];
int n;
inline int check(int x) {
    for(int i = 1; i < n/x; i++) {
        for(int j = 0; j < x; j++) {
            if(a[x*i+j]!=a[j]) return i;
        }
    }
    return n/x;
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", a);
        n = strlen(a);
        memset(charset, 0, sizeof charset);
        charset[a[0]-'a'] = 1; preodd[0] = 1;
        for(int i = 1; i < n; i++) { if(charset[a[i]-'a']) preodd[i] = preodd[i-1] - 1; else preodd[i] = preodd[i-1] + 1; charset[a[i] - 'a'] ^= 1; }
        memset(charset, 0, sizeof charset);
        charset[a[n-1]-'a'] = 1; lastodd[n-1] = 1;
        for(int i = n-2; ~i; i--) {
            lastodd[i] = lastodd[i+1] + ((charset[a[i]-'a']) ? -1 : 1);
            charset[a[i]-'a']^=1;
        }
        ll ans(0);
        for(int i = 2; i < n; i++) {
            int bound = check(i);
            for(int j = 1; j <= bound; j++) {
                    if(i * j == n) break;
                    int& odd = lastodd[i*j];
                    int a1(0);
                    for(int k = 0; k < i-1; k++) if(preodd[k] <= odd) a1++;
                    ans+=a1;
            }
        }
        printf("%llu\n", ans);
    }
    return 0;
}
