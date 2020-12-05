#include<bits/stdc++.h>
#define lson(id) (id<<1)
#define rson(id) ((id<<1)|1)
#define pb push_back
#define fi first
#define se second
#define lowbit(x) ((x)&(-x))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vii;

const int mo=1000000007;
const int maxn=500003;

int n,k,w[13],c[maxn],d[maxn],mn[maxn][13],mx[maxn][13],pos[13],cur[13],tpos[13];
ll res;

bool check(){
	for(int i=1;i<=k;++i)
		if(pos[i])return false;
	for(int i=1;i<=k;++i)
		if(mx[n][i]+mn[n][i]<w[i])
			return true;
	return false;
}

bool chk(int x){
	for(int i=1;i<=k;++i)
		if(cur[i]+mn[x][i]<1||cur[i]+mx[x][i]>w[i]){
			return true;
		}
	return false;
}

int solve(){
	int rt=0;
	for(int i=1;i<=k;++i)cur[i]=tpos[i];
	while(!chk(n)){
		for(int i=1;i<=k;++i)
			cur[i]+=pos[i];
		(rt+=n)%=mo;
	}
	int l=0,r=n+1,mid;
	while(l<r-1){
		mid=(l+r)/2;
		if(chk(mid))r=mid;
		else l=mid;
	}
//	for(int i=1;i<=k;++i)printf("%d ",tpos[i]);printf(": %d\n",rt+r);
	return (rt+r)%mo;
}

void dfs(int t){
	if(t>k){
		(res+=solve())%=mo;
		return ;
	}
	for(int i=1;i<=w[t];++i){
		tpos[t]=i;
		dfs(t+1);
	}
}

int main(){
	int mxw=0;
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		scanf("%d",&w[i]);
		mxw=max(mxw,w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",&c[i],&d[i]);
		pos[c[i]]+=d[i];
		for(int j=1;j<=k;++j)mn[i][j]=mn[i-1][j];
		for(int j=1;j<=k;++j)mx[i][j]=mx[i-1][j];
		mn[i][c[i]]=min(mn[i][c[i]],pos[c[i]]);
		mx[i][c[i]]=max(mx[i][c[i]],pos[c[i]]);
//		for(int j=1;j<=k;++j)printf("%d ",mn[i][j]);puts("#");
//		for(int j=1;j<=k;++j)printf("%d ",mx[i][j]);puts("#");
//		puts("%");
	}
	if(check()){
		puts("-1");
		return 0;
	}
	if(mxw<=10||mxw<=100000&&k==1){
		dfs(1);
		printf("%lld\n",res%mo);
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

/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/

