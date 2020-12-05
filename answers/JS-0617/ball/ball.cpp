#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F) {
	F = 0; int R = 1; char CH = getchar();
	for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
	for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
	F *= R;
}
const int N = 410, M = 410;
vector<int> qi[N]; int co[M], flag[N], fl[M], d[N], u[N], n, m, zi[N];
void movi(int x, int y) {
	printf("%d %d\n", x, y);
	qi[y].push_back(qi[x][qi[x].size() - 1]), qi[x].pop_back();
}
void merg(int bs, int nt, int col) {
	int res = 0;
	for(int i = 0; i < m; i++)
		if(qi[bs][i] != col) {
			res = i;
			break; 
		}
	for(int i = res; i < m; i++) movi(bs, n + 1);
	for(int i = m - 1; i >= 0; i--)
		if(qi[nt][i] == col) {
			res = i;
			break;
		}
	for(int i = res + 1; i < m; i++) movi(nt, n + 1);
	movi(nt, bs);
	while(qi[bs].size() != m) movi(n + 1, bs);
	while(qi[nt].size() != m) movi(n + 1, nt);
}
void work() {
	int mini = 0; co[0] = INT_MAX;
	for(int i = 1; i <= m; i++) zi[i] = 0, co[i] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < m; j++) {
			co[qi[i][j]] += m - j + 1;
		}
	for(int i = 1; i <= n; i++)
		if(!flag[i])
			zi[qi[i][m - 1]] = i;
	for(int i = 1; i <= m; i++)
		if(!fl[i] && zi[i] && co[i] < co[mini]) mini = i;
	fl[mini] = 1; int zz = 0;
	for(int i = 1; i <= n; i++)
		if(!flag[i] && zi[mini] != i) {
			d[i] = 0;
			for(int j = 0; j < m; j++)
				if(qi[i][j] == mini) d[i]++;
				else break;
			if(d[i] >= d[zz]) zz = i; 
		}
	flag[zz] = 1;
	while(true) {
		int ff = 1;
		for(int j = 0; j < m; j++)
			if(qi[zz][j] != mini) {
				ff = 0; break;
			}
		if(ff) break;
		int maxx = 0;
		for(int j = 1; j <= n; j++) {
			if(flag[j]) continue; 
			u[j] = 0;
			for(int k = m - 1; k >= 0; k--)
				if(qi[j][k] == mini) {
					u[j] = k + 1;
					break;
				}
			if(u[j] > u[maxx]) maxx = j;
		}
		merg(zz, maxx, mini);
	}
}
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	read(n), read(m);
	for(int i = 1; i <= n; i++) {
		int pi;
		for(int j = 1; j <= m; j++)
			read(pi), qi[i].push_back(pi);
	}
	for(int i = 1; i <= n - 1; i++) work();
	return 0;
}

