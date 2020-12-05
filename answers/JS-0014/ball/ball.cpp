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
int n, m, flg;
int a[51][51], tt[51], x[51], y[51];
inline bool ck1(){
	U(i, 1, n + 1)
		if (tt[i] != 0 && tt[i] != m) return 0;
	return 1;
}
inline bool check(){
	U(i, 1, n + 1)
		U(j, 2, tt[i])
			if (a[i][j] != a[i][j - 1]) return 0;
//	U(i, 1, n + 1){
//		U(j, 1, tt[i])
//			cout << a[i][j] << " ";
//		cout << endl;
//	}
	return 1;
}
inline void dfs(int dep){
//	cout << dep << endl;
	if (ck1()){
//		cout << tt[1] << " " << tt[2] << ' ' << tt[3] << endl;
		if (check()){
			flg = dep - 1;
			cout << flg << endl;
			U(i, 1, flg)
//				cout << x[i] << " " << y[i] << endl;
			return ;
		}
	}
	if (dep > m * n) return ;
	if (flg){
		return ;
	}
	U(i, 1, n + 1)
		U(j, 1, n + 1)
		if (i == j) continue ;
		else{
//			cout << i << " " << j << " " << tt[i] << " " << tt[j] << endl;
			if (tt[i] >= 1 && tt[j] < m)
				a[j][++tt[j]] = a[i][tt[i]--];
			else continue ;
//			cout << i << " " << j << " " << tt[i] << " " << tt[j] << endl << endl;
			x[dep] = i; y[dep] = j;
			dfs(dep + 1);
			if (flg) return ;
			a[i][++tt[i]] = a[j][tt[j]--];
		}
}
int main(){
	//FO("");
	read(n), read(m);
	U(i, 1, n) tt[i] = m;
	U(i, 1, n)
		U(j, 1, m)
			read(a[i][j]);
	dfs(1);
//	cout << flg << endl;
/*	U(i, 1, flg)
		writesp(x[i]), writeln(y[i]);*/
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
