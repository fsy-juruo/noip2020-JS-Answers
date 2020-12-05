#include<bits/stdc++.h>
using namespace std;
#define re register
#define Re register
#define ll long long
#define mod 1000000007
#define MAXN 500005
int n,k,pos[20],w[20],c[MAXN],d[MAXN],p2[20];
ll cnt[20];
ll ans;
void dfs(int step){
	if(step > k){
		int res = 0;
		bool o = true;
		memcpy(p2,pos,sizeof p2);
		while(o){
			for(re int i = 1;i <= n;i++){
				p2[c[i]] += d[i];res++;
				if(p2[c[i]] > w[c[i]]  || p2[c[i]] <= 0){
					o = false;
					break;
				}
			}
		}
		ans += res;
		return;
	}
	for(re int i = 1;i <= w[step];i++){
		pos[step] = i;dfs(step + 1);
	}
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(re int i = 1;i <= k;i++){
		scanf("%d",&w[i]);
	}
	for(re int i = 1;i <= n;i++){
		scanf("%d%d",&c[i],&d[i]);
		cnt[c[i]] += d[i];
	}
	bool no = false;
	for(re int i = 1;i <= k;i++){
		if(cnt[i] != 0)no = true;
	}
	if(!no){
		cout << -1 << endl;
		return 0;
	}
	dfs(1);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
