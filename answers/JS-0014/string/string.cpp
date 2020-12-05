#include <bits/stdc++.h>
using namespace std;
//#define RG register
#define U(x, y, z) for (int x = y; x <= z; ++x)
#define D(x, y, z) for (int x = y; x >= z; --x)
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
#define N (1 << 20)
int T, n;
int ji[N + 10], vis[27], a[N + 10], si[N + 10], s[27][N + 10];
int head[N], cnt;
struct node{
	int v, nxt;
}e[N << 4];
inline void add(int u, int v){
	++cnt;
	e[cnt].nxt = head[u];
	e[cnt].v = v;
//	cout << cnt << " " << u << " " << v << " " << e[cnt].nxt << endl;
	head[u] = cnt;
}
long long ans;
//inline void prepare(){
//	lg[1] = 0;
//	U(i, 1, N)
//		lg[i] = (1 << lg[i - 1] + 1 == i) ? lg[i - 1] + 1 : lg[i - 1];
//}
inline bool check(int l, int r){
	int len = r - l + 1;
	U(i, l, r) if (a[i] != a[i - len]) return 0;
	return 1;
}
//inline void solve(){
//	U(i, 2, n){
//		int len = n - i;
//		if (len % 2 == 0){
//			int ti = i - 1;
//			ans += i - 1;
//			while (ti % 2 == 0){
//				ti /= 2;
//				ans++;
//			}
//		}
//		else ans += i / 2;
//	}
//	writeln(ans);
//}
int main(){
	FO("string");
	read(T);
//	prepare();
	while (T--){
//		scanf("%s", ch + 1);
		string str;
		ans = 0;
		cin >> str;
		n = str.size();
		memset(vis, 0, sizeof vis);
		memset(ji, 0, sizeof ji);
		memset(si, 0, sizeof si);
//		U(i, 1, n) v[i].clear();
		memset(head, 0, sizeof head);
		memset(s, 0, sizeof s);
//		bool falg = 1;
		U(i, 1, n){
			a[i] = str[i - 1] - 'a';
		}
//		U(i, 2, n) if (a[i] != a[i - 1]) falg = 0;
//		if (falg == 1){
//			solve();
//			continue ;
//		}
		//writeln(n);
		cnt = 0;
		D(i, n, 3){
			if (vis[a[i]] % 2 == 0){
				++vis[a[i]];
				ji[i] = ji[i + 1] + 1;
			}
			else{
				++vis[a[i]];
				ji[i] = ji[i + 1] - 1;
			}
		}
		for (int i = 1; i <= n; ++i){
			add(i, i);
			int ti = i + 1;
			int tj = 2 * i;
			while (check(ti, tj) && tj <= n){
//				cout << tj << " " << i << endl;
				add(tj, i);
				ti += i;
				tj += i;
			}
		}
//	cout << cnt << endl;
//		U(i, 0, cnt) cout << i << " " << e[i].v << " " << e[i].nxt << endl;
//		U(i, 1, n) cout << head[i] << " ";
//		cout << endl;
//		U(i, 1, n){
//			cout << " " << i  << " " << e[head[i]].v << endl;
//		}
		memset(vis, 0, sizeof vis);
		U(i, 1, n - 1){
			U(j, 0, 25) s[j][i] = s[j][i - 1];
			if (vis[a[i]] % 2 == 0){
				++vis[a[i]];
				si[i] = si[i - 1] + 1;
			}
			else{
				++vis[a[i]];
				si[i] = si[i - 1] - 1;
			}
			U(j, si[i], 25) s[j][i]++;
//		cout << 1 << " " << head[1] << endl;
//			cout << i << " " << head[i] << endl;
			for (int j = head[i]; j; j = e[j].nxt){
				int v = e[j].v;
//				cout << i << " " << v << endl;
//				cout << j << " ";
				ans += s[ji[i + 1]][v - 1];
			}
//			cout << endl;
		}
		writeln(ans);
	}
	return 0;
}
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
