#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read(){
	LL s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
	return s * w;
}

int T, n;
char a[(1 << 20) + 10];

inline void init(){
	memset(a, 0, sizeof(a));
	cin >> a;
	for (n = 0; a[n] != 0; n++)
		n = n;
}

inline void work1(){
	LL ans = 0;
	n--;
	for (int i = 1; i < n; i++){
		if (n % i == 0){
			ans += i-1;
		}
	}
	printf("%lld\n", ans);
}

int main(void){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	T = read();
	while (T--){
		init();
		bool flag = 1;
		for (int i = 1; i < n; i++)
			if (a[i] != a[i-1]){
				flag = 0;
				break;
			}
		if (flag) work1();
		
	}
	return 0;
}
