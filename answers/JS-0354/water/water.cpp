//rng_58 bless me
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define REP(i,n) for(int (i) = 0;(i) < (n);(i)++)
const int MAXN = 100010;
vector <int> g[MAXN];
pair <int,int> ans[MAXN];
int rd[MAXN],cd[MAXN];
vector <int> st,ed;
int N,M;
void iint() {
	REP(i,N) {
		ans[i] = make_pair(0,1);
	}
}
pair <int,int> add(pair <int,int> a,pair <int,int> b) {
	int a1 = a.first;
	int a2 = a.second;
	int b1 = b.first;
	int b2 = b.second;
	int ansa1,ansa2,ansb1,ansb2;
	int sum1,sum2;
	int lcm = a2 * b2 / __gcd(a2,b2);
	if(a2 != b2) {
		ansa2 = lcm; ansa1 = lcm / a2 * a1; ansb2 = lcm; ansb1 = lcm / b2 * b1;
	} else {
		ansa2 = a2; ansa1 = a1; ansb2 = b2; ansb1 = b1;
	}
	sum1 = ansa1 + ansb1;
	sum2 = ansa2;
	int gcd = __gcd(sum1,sum2);
	sum1 = sum1 / gcd;
	sum2 = sum2 / gcd;
	return make_pair(sum1,sum2);
}
void dfs(int x) {
	for(int i = 0;i < g[x].size();i++) {
		int nx = g[x][i];
		pair <int,int> p = make_pair(ans[x].first,ans[x].second * g[x].size());
		dfs(nx);
		ans[nx] = add(ans[nx],p);
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin >> N >> M;
	iint();
	for(int i = 0;i < N;i++) {
		int K;
		cin >> K;
		while(K--) {
			int y;
			cin >> y;
			y--;
			g[i].push_back(y);
			rd[y]++;
			cd[i]++;
		}
	}
	for(int i = 0;i < N;i++) {
		if(rd[i] == 0) {
			st.push_back(i);
		}
		if(cd[i] == 0) {
			ed.push_back(i);
		}
	}
	REP(i,M) {
		ans[i].first = 1;
	}
	REP(i,st.size()) {
		dfs(i);
	}
	for(int i = 0;i < ed.size();i++) {
		cout << ans[ed[i]].first << ' ' << ans[ed[i]].second << endl;
	}
	return 0;
}

