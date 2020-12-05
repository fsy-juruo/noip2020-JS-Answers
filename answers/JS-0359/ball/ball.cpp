#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 55;
const int maxm = 405;

int n, m;
int a[maxn][maxm], b[maxn][maxm];

namespace Solve1{
	vector<pii> ans;
	
	inline void work(int c){
		int top0 = m - 1, top1 = m - 1, top2 = -1;
		vector<pii> vec;
		while(top0 >= 0 && top1 >= 0){
			while(top0 >= 0 && a[0][top0] != c){
				a[2][++top2] = a[0][top0--];
				vec.PB(MP(0, 2));
			}
			while(top1 >= 0 && a[1][top1] != c){
				a[2][++top2] = a[1][top1--];
				vec.PB(MP(1, 2));
			}
			if(!(top0 >= 0 && top1 >= 0))
				break;
			int len0 = 0, len1 = 0;
			for(; top0 - len0 + 1 >= 0 && a[0][top0 - (len0 + 1) + 1] == c; ++len0);
			for(; top1 - len1 + 1 >= 0 && a[1][top1 - (len1 + 1) + 1] == c; ++len1);
			if(top0 + len1 < m){
				FOR(i, 0, len1){
					a[0][++top0] = a[1][top1--];
					vec.PB(MP(1, 0));
				}
			}
			else if(top1 + len0 < m){
				FOR(i, 0, len0){
					a[1][++top1] = a[0][top0--];
					vec.PB(MP(0, 1));
				}
			}
			else
				return;
		}
		ans = vec;
		return;
	}
	
	inline void work(){
		FOR(i, 0, n) FOR(j, 0, m)
			a[i][j] = b[i][j];
		work(0);
		FOR(i, 0, n) FOR(j, 0, m)
			a[i][j] = b[i][j];
		work(1);
		printf("%d\n", ans.size());
		FOR(i, 0, ans.size())
			printf("%d %d\n", ans[i].fst + 1, ans[i].snd + 1);
		return;
	}
}

int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	FOR(i, 0, n){
		FOR(j, 0, m)
			scanf("%d", &b[i][j]), --b[i][j];
	}

	if(n == 2)
		Solve1::work();
	return 0;
}

