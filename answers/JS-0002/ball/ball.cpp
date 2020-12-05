#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N , M;
vector < pair < int , int > > ans;
vector < int > V[11111];

int main() {
	
	#ifndef evenbao
	freopen("ball.in" , "r" , stdin);
	freopen("ball.out" , "w" , stdout);
	#endif
	
	scanf("%d%d" , &N , &M);
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= M; ++j) {
		int x; scanf("%d" , &x);
		V[i].push_back(x);
	}
	while (true) {
		int pos = 0;
		for (int i = 1; i <= N; ++i) {
			int cur = 0 , jj = 0;
			while (cur < M && V[i][cur] == V[i][0]) ++cur;
			if (cur != M) {
				for (int j = 1; j <= N; ++j) {
					if (i == j) continue; int pp = -1;
					for (int k = M - 1; k >= 0; --k) {
						if (V[j][k] == V[i][0]) {
							pp = k;
							break;
						}
					}
					if (pp == -1) continue;
					if (M - cur + (M - 1 - pp) <= M) {
						jj = j;
					}
				}
			} else continue;
			if (!jj) continue;
			vector < int > tmp; tmp.clear();
			while (V[i].size() > cur) {
				ans.push_back(make_pair(i , N + 1));
				tmp.push_back(V[i][V[i].size() - 1]);
				V[i].pop_back();
			}
			while (V[jj][V[jj].size() - 1] != V[i][0]) {
				ans.push_back(make_pair(jj , N + 1));
				tmp.push_back(V[jj][V[jj].size() - 1]);
				V[jj].pop_back();
			}
		    ans.push_back(make_pair(jj , i));
		    V[i].push_back(V[i][0]); V[jj].pop_back();
		    for (int k = tmp.size() - 1; k >= 0; --k) {
		    	if (V[i].size() < M) {
		    		V[i].push_back(tmp[k]);
		    		ans.push_back(make_pair(N + 1 , i));
				} else {
					V[jj].push_back(tmp[k]);
					ans.push_back(make_pair(N + 1 , jj));
				}
			}
			pos = i; break;
		}
		if (!pos) break;
	}
	printf("%d\n" , (int) ans.size());
	for (int i = 0; i < ans.size(); ++i) printf("%d %d\n" , ans[i].first , ans[i].second);
	return 0;
}

