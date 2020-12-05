#include <bits/stdc++.h>
using namespace std;
#define RG register
#define U(x, y, z) for (RG int x = y; x <= z; ++x)
#define D(x, y, z) for (RG int x = y; x >= z; --x)
template <typename T> inline void read(T &n){
	n = 0; char c; T f = 1;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	n *= f;
}
template <typename T> inline void write(T n){
	if (n < 0){
		putchar('-');
		n = -n;
	}
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}
template <typename T> inline void writesp(T n){
	write(n);
	putchar(' ');
}
template <typename T> inline void writeln(T n){
	write(n);
	putchar('\n');
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
#define K 11
#define N 110
const int P = 1e9 + 7;
int n, k, w[K], c[N], b[K], d[N], a[K], sum, ways[K];
long long ans;
inline bool check(){
	U(i, 1, k) b[i] = a[i];
//	U(i, 1, k) writesp(b[i]);
//	puts("");
//	writeln(ans);
	while (1){
		bool f = 1;
		if (k == 1){
			while (b[1] <= w[1] && b[1] >= 1){
				ans = (ans + n) % P;
				b[1] += ways[1]; 
			}
			b[1] -= ways[1];
			ans = (ans - n + P) % P;
		}
		U(i, 1, n){
			b[c[i]] += d[i];
				++ans;
			if (b[c[i]] <= 0 || b[c[i]] > w[c[i]]) {
				f = 0;
				break;
			}
		}
		if (f == 0) break;
//		if (ans > sum * k) return 0;
	}
//	writeln(ans);
	return 1;
}
inline void dfs(int dep){
//	cout << dep << endl;
	if (dep > k){
		if (!check()) ans = -1; 
		return ;
	}
	if (ans == -1) return ;
	U(i, 1, w[dep]){
		a[dep] = i;
		dfs(dep + 1);
		if (ans == -1) return ;
	}
}
int main(){
	FO("walk");
	read(n), read(k);
	U(i, 1, k){
		read(w[i]);
		sum += w[i];
	}
	U(i, 1, n){
		read(c[i]), read(d[i]);
		ways[c[i]] += d[i];
	}
	int flg = 1;
	U(i, 1, k) if (ways[c[i]] != 0){
		flg = 0;
		break ;
	}
	if (flg == 1){
		puts("-1");
		return 0;
	}
	dfs(1);
	writeln(ans);
	return 0;
}
/*
2 1
9
1 1
1 1
*/
