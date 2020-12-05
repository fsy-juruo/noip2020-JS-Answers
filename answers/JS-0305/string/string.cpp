#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1100000;
int n, a[MAXN], cnt1[300], cnt2[300], f[MAXN], f_[MAXN];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    while (n--) {
	char x = 0;
	int size = 0;
	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);
	while (1) {
	    x = getchar();
	    if (x >= 'a' && x <= 'z') a[++size] = x - 'a' + 1;
	    f[size] = f_[size] = 0;
	    if (size && x == '\n') break;
	}
	unsigned long long ans = (size - 1) * (size - 2) / 2;
	for (int i = 1; i <= size - 2; i++) {
	    cnt1[a[i]]++;
	    if (cnt1[a[i]] % 2 == 1) f[i] = f[i - 1] + 1;
	    else f[i] = f[i - 1] - 1;
	}
	for (int i = size; i > 2; i--) {
	    cnt2[a[i]]++;
	    if (cnt2[a[i]] % 2 == 1) f_[i] = f_[i + 1] + 1;
	    else f_[i] = f_[i + 1] - 1;
	    for (int j = 1; j <= i - 2; j++) if (f[j] > f_[i]) ans--;
	}
	cout << ans << endl;
    }

    return 0;
}
