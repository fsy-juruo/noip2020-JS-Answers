#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const int tt[10][10] ={{1, 2}, {2, 1}, {1, 3}, {3, 1}, {2, 3}, {3, 2}};
struct Node{
	int s[4][25], len[4], id;
};
int n, m, cnt, s[4][25], tx[N], ty[N], pre_id[N];
queue<Node>qq;
inline bool check(Node tmp){
	for (int i = 1; i <= 3; ++i){
		int flag = 1;
		for (int j = 2; j <= m; ++j)
			if (tmp.s[i][j] != tmp.s[i][j - 1]){
				flag = 0; break;
			}
		if (!flag) return 0;
	}
	return 1;
}
inline void putout(int id){
	if (!id){
		cout << cnt << endl;
		return;
	}
	++cnt;
	putout(pre_id[id]);
	cout << tx[id] << ' ' << ty[id] << endl;
}
inline void bfs(){
	int tot = 0;
	Node tmp;
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= m; ++j)
			tmp.s[i][j] = s[i][j];
	tmp.len[1] = tmp.len[2] = m;
	tmp.id = 0;
	qq.push(tmp);
	while (qq.size()){
		tmp = qq.front(); qq.pop();
		if (check(tmp)){
			putout(tmp.id); return;
		}
		for (int i = 0; i < 6; ++i){
			Node t = tmp;
			int x = tt[i][0], y = tt[i][1];
			if (tmp.len[x] == 0 || tmp.len[y] == m) continue;
			++tot;
			pre_id[tot] = tmp.id;
			tx[tot] = x, ty[tot] = y;
			t.s[y][++t.len[y]] = t.s[x][t.len[x] --];
			t.id = tot;
			qq.push(t);
		}
	}
}
int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> s[i][j];
	bfs();
	return 0;
}

