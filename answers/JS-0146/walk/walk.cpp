#include<bits/stdc++.h>
#define ll long long
#define N 105
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=b;i>=a;--i)
#define all(x) x.begin(),x.end()
#define VI vector<int>
#define pii pair<int,int>
#define fi first
#define SZ(x) ((int)x.size())
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int n,k,c[N],d[N],w[N],cur[N],ccur[N];
bool check(){
	rep(i,1,k){
		if(1 <= ccur[i] && ccur[i] <= w[i]) continue;
		return 0;
	}
	return 1;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	rep(i,1,k) scanf("%d",&w[i]);
	rep(i,1,n) scanf("%d%d",&c[i],&d[i]);
	int tot = 1; rep(i,1,k) tot = tot*w[i];
	rep(i,1,k) cur[i] = 1;
	int ans = 0;
	while(tot--){
//		rep(i,1,k) cout << cur[i] << ' ';
//		cout << endl;
		rep(i,1,k) ccur[i] = cur[i];
		rep(i,1,n*100){
			ccur[c[(i-1)%n+1]] += d[(i-1)%n+1];ans++;
			if(!check()) break;
		}
		cur[k]++;
		per(i,1,k) if(cur[i] > w[i]) cur[i] -= w[i],cur[i-1]++;
	}
	printf("%d",ans);
	return 0;
}

