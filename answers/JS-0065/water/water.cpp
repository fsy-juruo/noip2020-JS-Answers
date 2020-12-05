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
int n,m;
int in[100005];
ll gcd(ll x,ll y){
	if(!y) return x;
	return gcd(y, x % y);
}
struct frac{
	ll x,y;
	void yue(){
		ll g = gcd(x,y);
		x /= g;y /= g;
	}
};
frac wt[100005];
frac operator + (frac x,frac y){
	frac k;
	ll xx = x.x * y.y + x.y * y.x, yy = x.y * y.y;
	k.x = xx;k.y = yy;k.yue();return k;
}
frac operator * (frac x,frac y){
	frac k;
	ll xx = x.x * y.x, yy = x.y * y.y;
	k.x = xx;k.y = yy;k.yue();return k;
}
frac operator / (frac x,ll y){
	frac k;
	ll xx = x.x, yy = x.y * y;
	k.x = xx;k.y = yy;k.yue();return k;
}
queue<int> q;
vector<int> v[100005];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		int num;
		scanf("%d",&num);
		rep(j,1,num) {
			int x;
			scanf("%d",&x);
			v[i].pb(x);
			in[x]++;
		}
	}
	rep(i,1,n) wt[i].y = 1;//void unexpected errors
	rep(i,1,m) wt[i].x = wt[i].y = 1;
	rep(i,1,n) if(!in[i]) q.push(i);
	while(!q.empty()){
		int x = q.front();q.pop();
		frac e = wt[x] / (int)v[x].size();
		rap(i,0,v[x].size()){
			int to = v[x][i];
			wt[to] = wt[to] + e;
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	rep(i,1,n) if(v[i].size() == 0) {
		wt[i].yue();
		printf("%lld %lld\n",wt[i].x,wt[i].y);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

