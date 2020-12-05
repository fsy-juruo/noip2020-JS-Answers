#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)

typedef long long LL;
const int N = 50 + 5, M = 400 + 10;

template <typename Tp> void read(Tp &x){
	x = 0; int op = 1; char ch = getchar();
	while(!isdigit(ch)){ if(ch == '-') op = -1; ch = getchar(); }
	while(isdigit(ch)){ x = x*10+ch-'0'; ch = getchar(); } x *= op;
}
template <typename Tp> void CMax(Tp &x, Tp y){ if(y > x) x = y; }
template <typename Tp> void CMin(Tp &x, Tp y){ if(y < x) x = y; }

int n, m, col[N][M];


LL sta[15], len[15], ss, tt;

struct Opt{
	int x, y;
} op[1000];

bool check(){
	if(sta[1] == ss || sta[2] == ss || sta[3] == ss ||
	   sta[1] == tt || sta[2] == tt || sta[3] == tt)
			return true;
	return false;
}

int op1[820000 + 10], op2[820000 + 10], step;

void solve0()
{
	if(n == 1) puts("0");
	else {
		for(int i = 1; i <= 100000; ++ i){
			int t = rand() % 6 + 1;
			int x = op[t].x, y = op[t].y;
			if(len[x] == 0) swap(x, y);
			if(len[y] == m) y = 6 - x - y;
			len[y] ++; len[x] --;
			op1[++ step] = x; op2[++ step] = y;
		}
		for(int i = 1; i <= 100000; ++ i){
			int t = rand() % 6 + 1;
			int x = op[t].x, y = op[t].y;
			if(len[x] == 0) swap(x, y);
			if(len[y] == m) y = 6 - x - y;
			len[y] ++; len[x] --;
			op1[++ step] = x; op2[++ step] = y;
			if(len[1] == m && len[2] == m) break;
		}
		printf("%d\n", step);
		for(int i = 1; i <= step; ++ i){
			printf("%d %d\n", op1[i], op2[i]);
		}
	}
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	srand((unsigned)time(0));
	read(n); read(m);
	for(int i = 1; i <= n; ++ i){
		len[i] = m;
		for(int j = 1; j <= m; ++ j){
			read(col[i][j]);
			sta[i] = sta[i - 1] * 3 + col[i][j];
		}
	}
	for(int i = 1; i <= m; ++ i) ss = ss * 3 + 1, tt = tt * 3 + 2;
	op[1] = (Opt){ 1, 2 };
	op[2] = (Opt){ 1, 3 };
	op[3] = (Opt){ 2, 3 };
	op[4] = (Opt){ 3, 1 };
	op[5] = (Opt){ 3, 2 };
	op[6] = (Opt){ 2, 1 };
	solve0();
	return 0;
}

