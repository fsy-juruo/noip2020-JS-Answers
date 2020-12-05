#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 5;
const int MAXK = 15;

int n,k;
ll ans;
int w[MAXK],c[MAXN],d[MAXN],a[MAXK],tmp[MAXK];

namespace SubTask1{
	bool Move(){
		for(int i = 1;i <= n;i++){
			tmp[c[i]] += d[i];
			if(tmp[c[i]] <= 0 || tmp[c[i]] > w[c[i]]){
				ans += i;
				return 0;
			}
		}
		ans += n;
		return 1;
	}
	
	void Calc(){
		if(!Move())
			return;
		int flag = 1;
		for(int i = 1;i <= k;i++){
			if(tmp[i] != a[i]){
				flag = 0;
				break;
			}
		}
		if(flag){
			printf("-1\n");
			exit(0);
		}
		while(Move());
	}
	
	void dfs(int dep){
		if(dep == k + 1){
			for(int i = 1;i <= k;i++)
				tmp[i] = a[i];
			Calc();
			return;
		}
		for(int i = 1;i <= w[dep];i++){
			a[dep] = i;
			dfs(dep + 1);
		}
	}
	
	void Solve(){
		dfs(1);
		printf("%lld\n",ans);
	}
}

namespace SubTask2{
	int t[MAXN << 1];
	
	void Solve(){
		memset(t,0x3f,sizeof(t));
		int lmax = 0,rmax = 0,cnt = 0;
		for(int i = 1;i <= n;i++){
			cnt += d[i];
			t[cnt + n] = min(t[cnt + n],i);
			lmax = max(lmax,-cnt);
			rmax = max(rmax,cnt);
		}
		if(lmax == rmax){
			printf("-1\n");
			return;
		}
		for(int i = 1;i <= w[1];i++){
			if(t[i + n] < INF || t[w[1] - i + 1 + n] < INF){
				ans += min(t[i + n],t[w[1] - i + 1 + n]);
				continue;
			}
			int dir = lmax - rmax;
			if(dir < 0){ // right
				dir = -dir;
				int num = ((w[1] - i + 1) - 1 - rmax) / dir + 1;
				ans += num * n;
				int pos = i + num * dir - 1;
				ans += t[w[1] - pos + 1 + n];
			}else{
				int num = (i - 1 - lmax) / dir + 1;
				ans += num * n;
				int pos = i - num * dir + 1;
				ans += t[pos + n];
			}
		}
		printf("%lld\n",ans);
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= k;i++)
		scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++)
		scanf("%d%d",&c[i],&d[i]);
	if(k == 1)
		SubTask2::Solve();
	else if(n <= 100 && k <= 5)
		SubTask1::Solve();
	else
		printf("-1\n");
	return 0;
}

