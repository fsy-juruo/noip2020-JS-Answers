#include <cstdio>
const int MAXN = 500005;
int w[15], c[MAXN], d[MAXN];
int pos[15], lb[15], rb[15];
inline int mmin(const int& a, const int& b) { return a < b ? a : b; }
inline int mmax(const int& a, const int& b) { return a < b ? b : a; }
int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    int n, k;
    for(int i = 1; i <= k; i++) scanf("%d", w + i), lb[i] = n+1, rb[i] = -n-1; //!
    int flag = 1;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", c + i, d + i);
        pos[c[i]] += d[i];
        lb[i] = mmin(lb[i], pos[c[i]]);
        rb[i] = mmax(rb[i], pos[c[i]]);
    }
    for(int i = 1; i <= k; i++) {
        if(pos[i]) { flag = 0; break; }
        if(lb[i]!=n+1) {
        if((rb[i] - lb[i]) > w[i]) {
            flag = 0;
            break;
        }
        }
    }
    if(flag) { puts("-1"); return 0; }
    
    return 0;
}
