#include<bits/stdc++.h>
using namespace std;
int n, m, z[51][1010];
int ans_from[820010], ans_to[820010],tot[1010],k;
bool pd(){
	for(int i = 1; i <= n; ++i){
		for(int j = 2; j <= m; ++j){
			if(z[i][j] != z[i][j - 1])return false;
		}
	}
	return true;
}
void print(){
	printf("%d\n", k);
	for(int i = 1; i <= k; ++i){
		printf("%d %d\n", ans_from[i], ans_to[i]);
	}
}
void dfs(){
	if(k > 820010) return;
	if(!tot[n + 1]){
		if(pd())print();return;
	}
	for(int i = 1; i <= n + 1; ++i){
		if(tot[i]){
			for(int j = 1; j <= n + 1; ++j){
				if(tot[j] < m){
					tot[j]++;
					tot[i]--;
					++k;
					ans_from[k] = i;
					ans_to[k] = j;
					z[j][tot[j]] = z[i][tot[i] + 1];
					dfs();
					--k;
					tot[j]--;
					tot[i]++;
				}
			}
		}
	}
}
int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &z[i][j]);
		}
		tot[i] = m;
	}
	dfs();
	fclose(stdin);
	fclose(stdout);
}
