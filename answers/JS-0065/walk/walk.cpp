#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define rep(i,j,k) for(int (i) = (j);(i) <= (k);(i)++)
#define rap(i,j,k) for(int (i) = (j);(i) < (k) ;(i)++)
#define per(i,j,k) for(int (i) = (j);(i) >= (k);(i)--)
#define sit set<int>::iterator
#define mit map<int,int>::iterator
#define itrm(it,g) for(it = g.begin(); it != g.end(); it++)
#define mpr make_pair
#define pii pair<int,int>
int n,k,w[15],pos[15],pos1[15],sum[15];int ans;
int c[1000005],d[1000005];
int check(int x){
	rep(i,1,k) pos1[i] = pos[i] + x * sum[i];
	//rep(i,1,k) if(po[i] <= 0 || pos[i] > w[i]) return x * n;
	rep(i,1,n) {
		pos1[c[i]] += d[i];
		if(pos1[c[i]] <= 0 || pos1[c[i]] > w[c[i]]) return x * n + i;
	}
	return -1;
}
void get(){
	//printf("%d %d\n",pos[1],pos[2]);
	int l = 0, r = 1e7;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid) != -1) r = mid;
		else l = mid + 1;
	}
	if(l > 9999999) {
		puts("-1");
		exit(0);
	}
	else {
		ans += check(l);
	}
}
void dfs(int x){
	if(x == k + 1) {
		get();
		return;
	}
	rep(i,1,w[x]) {
		pos[x] = i;
		dfs(x + 1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	rep(i,1,k) scanf("%d",w+i);
	rep(i,1,n) {scanf("%d%d",c+i,d+i);sum[c[i]] += d[i];}
	dfs(1);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

