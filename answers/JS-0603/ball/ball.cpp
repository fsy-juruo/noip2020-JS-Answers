#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
int sz[55];
int col[55][444];
vector< pair<int, int> > op;

void move(int from, int to){
	op.push_back(make_pair(from, to));
	col[to][sz[to]++] = col[from][--sz[from]];
}
void give_to(int pos, int target){
	int now = 0;
	while(sz[pos] > target){
		while(now == pos || sz[now] >= m) now++;
		move(pos, now);
	}
}

void solve(int now){
	int ncol = n - now;
	give_to(now, 0);
	int cnt = 0;
	int lvl;
	for(lvl = m-1; lvl >= 0; lvl--){
		rep(j, n){
			if(sz[j] > lvl && col[j][lvl] == ncol){
//				cout << now << ": " << " " << lvl << ": " << ncol << " " << j << endl;
				give_to(j, lvl);
				move((j + 1) % now, j);
				move(now, (j + 1) % now);
				give_to(now, cnt);
				move((j + 1) % now, now);
				cnt++;
			}
		}
	}
}

int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n){
		sz[i] = m;
		rep(j, m){
			cin >> col[i][j];
			col[i][j]--;
		}
	}
	for(int i = n; i > 1; i--) solve(i);
	give_to(1, 0);
	cout << op.size() << endl;
	rep(i, (int)op.size()) cout << op[i].first + 1 << " " << op[i].second + 1 << endl;
	return 0;
}
