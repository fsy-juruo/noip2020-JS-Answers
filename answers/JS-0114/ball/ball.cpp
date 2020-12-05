#include <cstdio>
#include <cstring>
const int MAXN = 55;
const int MAXM = 405;
int n, m;
int ans, a1[820000], a2[820000];
int a[MAXN][MAXM];
inline int check(int* a) {
    int& res = a[0];
    for(int i = 1; i < n; i++) if(res != a[i]) return -1;
    return res;
}
bool check() {
    for(int i = 0; i < n; i++)
        if(-1 == check(a[i])) return 0;
    return 1;
}
void print() {
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++) {
        printf("%d %d\n", a1[i], a2[i]);
    }
}
void mov(int x, int y) {
    a1[ans] = x;
    a2[ans++] = y;
}
int main() {
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", a[i] + j);
        }
    }
    if(check()) { print(); return 0;}
    if(n == 2) {

        for(int i = 0; i < m; i++) {
            if(a[0][i] == 2) {
                int search = 0;
                for(int j = m-1; ~j; --j) if(a[1][j] == 1) { search = j; break; }
                for(int j = search+1; j < m; j++) mov(2, 3);
                mov(1, 3);
                mov(2, 1);
                for(int j = search; j > i; j--) mov(2, 3);
                mov(1, 2);
                mov(3, 1);
                for(int j = i+1; j < m; j++) mov(3, 2);
            }
            if(a[1][i] == 1) {
                int search = 0;
                for(int j = m-1; ~j; --j) if(a[0][j] == 2) { search = j; break; }
                for(int j = search+1; j < m; j++) mov(1, 3);
                mov(2, 3);
                mov(1, 2);
                for(int j = search; j > i; j--) mov(1, 3);
                mov(2, 1);
                mov(3, 2);
                for(int j = i+1; j < m; j++) mov(3, 1);
            }
        }
        print();
        return 0;
    }
    return 0;
}
