#include <cstdio>
#include <cstdlib>

int const N=55,M=405;

int map[N][M];
int cnt[N];

int n,m;

int ans[int(1e6)][2];

void check(int d){
	for(int i = 1;i <= n;++i){
		int t = map[i][1];
		for(int j = 1;j <= m;++j){
			if(map[i][j] != t) return;
		}
	}

	printf("%d\n",d);

	for(int i = 0;i < d;++i){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}

	exit(0);
}

int maxn;

void dfs(int d){
	if(d >= maxn) return;
	bool flag = 1;

	for(int i = 1;i <= n; ++i)
		flag &= (cnt[i]==m);
	
	if(flag) check(d);

	for(int i = 1;i <= n+1;++i){
		for(int j = 1;j <= n+1;++j){
			if(j==ans[d-1][0] and i == ans[d-1][1]) continue;
			if(i==j) continue;
			if(cnt[i]<=0) continue;
			if(cnt[j]>=m) continue;
			ans[d][0]=i;
			ans[d][1]=j;
			int bak = map[i][cnt[i]];
			map[j][++cnt[j]]=map[i][cnt[i]--];
			dfs(d+1);
			--cnt[j];
			++cnt[i];
			map[i][cnt[i]]=bak;
		}
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			scanf("%d",map[i]+j);
		}
		cnt[i]=m;
	}

	for(int i = 1;i < 1e5;++i){
		maxn = i;
		dfs(0);
	}

	return 0;
}
