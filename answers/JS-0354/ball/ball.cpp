//rng_58 bless me
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define REP(i,n) for(int (i) = 0;(i) < (n);(i)++)
const int MAXN = 60;
const int MAXT = 820000;
struct node {
	int cost;
	vector <int> a[MAXN];
	vector <pair<int,int> > ans;
	node(){}
	node(int Cost,vector <pair<int,int> > Ans,vector <int> A[]) {
		cost = Cost;
		ans = Ans;
		REP(i,MAXN) {
			a[i] = A[i];
		}
	}
};
int N,M;
vector <pair<int,int> > ans;
vector <int> a[MAXN];
queue <node> q;
void bfs() {
	q.push(node(0,ans,a));
	while(!q.empty()) {
		node x = q.front();
		q.pop();
		int cost = x.cost;
		if(cost > MAXT) {
			continue;
		}
		vector <int> a[MAXN] = x.a;
		vector <pair<int,int> > ans = x.ans;
		bool ok = 1;
		REP(i,N) {
			set <int> st;
			REP(j,a[i].size()) {
				st.insert(a[i][j]);
			}
			ok &= st.size() == 1;
		}
		if(ok) {
			cout << cost << endl;
			REP(i,ans.size()) {
				cout << ans[i].first << ' ' << ans[i].second << endl;
			}
			return;
		}
		REP(i,N + 1) {
			if(a[i].empty()) {
				continue;
			}
			REP(j,N + 1) {
				if(i == j || a[j].size() > M - 1) {
					continue;
				}
				vector <int> na[MAXN];
				vector <pair<int,int> > nans = ans;
				REP(i,MAXN) {
					na[i] = a[i];
				}
				nans.push_back({i,j});
				int tmp = a[i][a[i].size() - 1];
				na[i].erase(a[i].end() - 1);
				na[j].push_back(tmp);
				q.push(node(cost + 1,nans,na));
			}
		}
	}
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin >> N >> M;
	REP(i,N) {
		REP(j,M) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	bfs();
	return 0;
}

