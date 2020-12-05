#include<bits/stdc++.h>
using namespace std;
int n, m;
int s[51][401];
int top[51];
int a[820001], b[820001];
int fin, ans[820001], bns[820001];
void dfs(int dep){
	if(dep > 820001) return;
	bool fl = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < top[i];j++){
			if(s[i][j] != s[i][0]){
				fl = 0;
				break;
			}
		}
	}
	if(fl){
		fin = dep;
		for(int i = 1;i <= dep;i++){
			ans[i] = a[i], bns[i] = b[i];
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(top[j] > m || top[i] == 0) continue;
			a[dep] = i, b[dep] = j;
			top[i]--;
			s[j][top[j]++] = s[i][top[i]];
			dfs(dep+1);
		}
	}
}
void naive(){
	dfs(1);
	printf("%d\n", fin);
	for(int i = 1;i <= fin;i++){
		printf("%d %d\n", ans[i], bns[i]);
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < m;j++){
			int num;
			scanf("%d", &num);
			s[i][top[i]++] = num;
		}
	}
	naive();
	return 0;
}
