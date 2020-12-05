#include<bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define pd priority_queue
using namespace std;
template<typename Tp>
void read(Tp &x){
	x = 0;
	int f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	x *= f;
}
template<typename Tp> void Cmax(Tp &x, Tp y) { if(y > x) x = y;}
template<typename Tp> void Csum(Tp &x, Tp y) { x = (x + y); }
typedef long long LL;
const int N = 100;
int n, m;
int sta[N][450], top[N];
int f[100040][3];
bool Hash[25][25][25][10][10][10];
void dfs(int top1, int top2, int top3, int s1, int s2, int s3, int s){
	if(Hash[top1][top2][top3][s1][s2][s3])
		return;
	Hash[top1][top2][top3][s1][s2][s3] = 1;
	int maxn = max(s1, max(s2, s3));
	int r = (top1 == 0) + (top2 == 0) + (top3 == 0);
	if(maxn == (1 << m) - 1 && r == 1){
		printf("%d\n", s);
		for(int i = 1; i < s; ++i)
			printf("%d %d\n", f[i][0], f[i][1]);
		exit(0);
	}
	if(top2){
		f[s][0] = 2;
		if(top1 < m){
			int p = s2 >> (top2 - 1);
			f[s][1] = 1;
			p &= 1;
			if(p)
				dfs(top1 + 1, top2 - 1, top3, s1 | (1 << top1), s2 - (1 << (top2 - 1)), s3, s + 1);
			else
				dfs(top1 + 1, top2 - 1, top3, s1, s2, s3, s + 1);
			
		}
		if(top3 < m){
			int p = s2 >> (top2 - 1);
			p &= 1;
			f[s][1] = 3;
			if(p)
				dfs(top1 , top2 - 1, top3 + 1, s1 , s2 - (1 << (top2 - 1)), s3 | (1 << top3), s + 1);
			else
				dfs(top1 , top2 - 1, top3 + 1, s1, s2, s3, s + 1);
		}
	}
	if(top3){
		f[s][0] = 3;
		if(top2 < m){
			int p = s3 >> (top3 - 1);
			p &= 1;
			f[s][1] = 2;
			if(p)
				dfs(top1, top2 + 1, top3 - 1, s1 , s2 | (1 << top2), s3 - (1 << (top3 - 1)), s + 1);
			else
				dfs(top1, top2 + 1, top3 - 1, s1, s2, s3, s + 1);
			
		}
		if(top1 < m){
			int p = s3 >> (top3 - 1);
			p &= 1;
			f[s][1] = 1;
			if(p)
				dfs(top1 + 1, top2, top3 - 1, s1 | (1 << top1), s2 , s3 - (1 << (top3 - 1)), s + 1);
			else
				dfs(top1 + 1, top2, top3 - 1, s1, s2, s3, s + 1);
			
		}
	}
	if(top1){
		f[s][0] = 1;
		if(top2 < m){
			int p = s1 >> (top1 - 1);
			p &= 1;
			f[s][1] = 2;
			if(p)
				dfs(top1 - 1, top2 + 1, top3, s1 - (1 << (top1 - 1)), s2 | (1 << top2), s3, s + 1);
			else
				dfs(top1 - 1, top2 + 1, top3, s1, s2, s3, s + 1);
			
		}
		if(top3 < m){
			int p = s1 >> (top1 - 1);
			p &= 1;
			f[s][1] = 3;
			if(p)
				dfs(top1 - 1, top2, top3 + 1, s1 - (1 << (top1 - 1)), s2 , s3 | (1 << top3), s + 1);
			else
				dfs(top1 - 1, top2, top3 + 1, s1, s2, s3, s + 1);
		}
	}
}
void init(){
	read(n); read(m);
	int s1 = 0, s2 = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			read(sta[i][j]);
			if(sta[i][j] == 1){
				if(i == 1)
					s1 |= (1 << (j - 1));
				else
					s2 |= (1 << (j - 1));
			}
		}
	}
	if(n == 2)
		dfs(m, m, 0, s1, s2, 0, 1);
}
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	init();
	return 0;
}

