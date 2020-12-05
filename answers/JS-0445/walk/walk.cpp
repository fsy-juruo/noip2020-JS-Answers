#include<bits/stdc++.h>
using namespace std;
#define int long long
int st[500010],dir[500010],dim[14];
int n,k;
namespace SubTaskA{
	int coor1[14],tot=0,coor2[14];
	int solve(){
		memcpy(coor2,coor1,sizeof(coor1));
		int ans=0,i=1;
		while(1){
			coor2[st[i]]+=dir[st[i]];
			ans++;
			if(1<=coor2[st[i]] && coor2[st[i]]<=dim[st[i]]);
			else
				break;
			if(ans>=40000000)
				break;
			i=(((i-1)%n)+1);
		}
		if(ans>=40000000)
			return 0;
		tot=(tot+ans)%1000000007;
		return 1;
	}
	void dfs(int curdim){
		if(curdim==k+1){
			int k=solve();
			if(k==0){
				printf("-1");
				exit(0);
			}
			return;
		}
		for(coor1[curdim]=1;coor1[curdim]<=dim[curdim];coor1[curdim]++)
			dfs(curdim+1);
	}
	int SolveMain(){
		dfs(1);
		return tot;
	}
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%lld",dim+i);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",st+i,dir+i);
	if(n<=100 && k<=3){
		SubTaskA::SolveMain();
		printf("%lld",SubTaskA::SolveMain());
		return 0;
	}
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
