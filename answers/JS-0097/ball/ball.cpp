#include <bits/stdc++.h>

using namespace std;

const int N = 400 + 10;

int n,m;
int c[N];

vector <int> ans1;
vector <int> ans2;

vector <int> v[N];

void solve() {
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			int x;
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	for(int i=1; i<=n; ++i) {
		int t;
		for(int j=1; j<v[i].size(); ++j) {
			if(v[i][j] != v[i][j - 1]) {
				t = j;
			}
		}
		c[v[i][0]] = i;
		int minx = 0x7f7f7f7f , mi = 0;
		for(int j=1; j<=n+1; ++j) {
			if(v[i].size() < minx) {
				minx = v[i].size();
				mi = j;
			}
		}
//		for(int j=t;j<v[i].size();++j) {
//			v[mi].push_back(v[i][j]);
//			v[i].pop();
//			ans1.push_back(i);
//			ans2.push_back(mi);
//		}
		for(int j=t; j<v[i].size(); ++j) {
			v[c[v[i][j]]].push_back(v[i][j]);
			v[i].erase(v[i].end());
			ans1.push_back(i);
			ans2.push_back(c[v[i][j]]);
		}
	}
	printf("%d\n",ans1.size());
	for(int i=0; i<ans1.size(); ++i) {
		printf("%d %d\n",ans1[i],ans2[i]);
	}
}

stack<int>a[N];
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);

	scanf("%d%d",&n,&m);
//	if(n >= 10) {
//		solve();
//	}
	if(n == 2) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j) {
				int x;
				scanf("%d",&x);
				a[i].push(x);
			}
		}
		while(! a[1].empty()) {
			if(a[1].top() == 1) {
				a[3].push(1);
				ans1.push_back(1);
				ans2.push_back(3);
			} else {
				a[2].push(2);
				ans1.push_back(1);
				ans2.push_back(2);
			}
			a[1].pop();
		}//1:0 2:12 3:1

		while(! a[2].empty()) {
			if(a[2].top() == 1) {
				a[3].push(1);
				ans1.push_back(2);
				ans2.push_back(3);
			} else {
				a[1].push(2);
				ans1.push_back(2);
				ans2.push_back(1);
			}
			a[2].pop();
		}
	} else {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j) {
				int x;
				scanf("%d",&x);
				a[i].push(x);
			}
		}
//		c[1] = n + 1;
		for(int i=1; i<=n; ++i) {
			while(! a[i].empty()) {
				int t = a[i].top();
						a[i].pop();
				
				int o = 0;
				if(! c[t]) {
					for(int j=1; j<=n+1; ++j) {
						if(a[j].empty()) {
							c[t] = j;
							o = 1;
							break;
						}
					}
				}
//				cerr << "OK";
				if(o == 0) {
					a[i + 1].push(t);
					ans1.push_back(i);
					ans2.push_back(i + 1);
				} else {
					a[c[t]].push(t);
					ans1.push_back(i);
					ans2.push_back(c[t]);
				}
		
			}
		}
	}/*
	3 4
	1 2 3 4
	1 1 2 3
	2 3 1 1
	*/
	printf("%d\n",ans1.size());
	for(int i=0; i<ans1.size(); ++i) {
		printf("%d %d\n",ans1[i],ans2[i]);
	}
	return 0;
}
