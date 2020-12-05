#include<cstdio>
int stk[17][107], tp[17], n, m, ans, step[100007][2];
int main(){
	freopen("ball.in", "r", stdin);
	freopsn("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		tp[i] = m;
		for(int j = 1; j <= m; ++j)
			scanf("%d", &stk[i][j]);
	}
	step[++ans][0] = 1, step[ans][1] = n+1;
	stk[n+1][++tp[n+1]] = stk[1][tp[1]--];
	while(tp[n+1] < m){
		while(stk[1][tp[1]] == stk[n+1][tp[n+1]] && tp[1] > 0){
			step[++ans][0] = 1, step[ans][1] = n+1;
			stk[n+1][++tp[n+1]] = stk[1][tp[1]--];
		}
		while(stk[2][tp[2]] == stk[n+1][tp[n+1]] && tp[2] > 0){
			step[++ans][0] = 2, step[ans][1] = n+1;
			stk[n+1][++tp[n+1]] = stk[2][tp[2]--];
		}
		int ls = 1, tmp = tp[1];
		while(stk[1][tmp] == stk[1][tmp-1] && tmp > 0) ++ls, --tmp;
		if(ls + tp[2] >= m || tp[2] == 0){
			while(stk[2][tp[2]] == stk[1][tp[1]] && tp[2] > 0){
				step[++ans][0] = 2, step[ans][1] = 1;
				stk[1][++tp[1]] = stk[2][tp[2]--];
			}
		}
		else{
			while(stk[1][tp[1]] == stk[2][tp[2]] && tp[1] > 0){
				step[++ans][0] = 1, step[ans][1] = 2;
				stk[2][++tp[2]] = stk[1][tp[1]--];
			}
		}
	}
	printf("%d\n", ans);
	for(int i = 1; i <= ans; ++i) printf("%d %d\n", step[i][0], step[i][1]);
	return 0;
}
