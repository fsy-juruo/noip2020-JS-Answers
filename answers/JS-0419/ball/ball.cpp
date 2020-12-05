#include <bits/stdc++.h>
using namespace std;

int n, m, color[60][20010], pos[60], ans[20010], ans1[820010], ans2[820010], num[60], tep1 = 0, r[60], step = 0;
bool t = false;

bool check (){
	bool f = true;
	for (int i = 1; i <= n; i ++){
		if (pos[i] != m){
			f = false;
			break;
		}
	}
	return f;
}

void DFS (int i, int tep, int step){
	if (step > 820000){
		return ;
	}
	if (check ()){
		if (t){
			return ;
		}
		for (int i = 0; i < tep; i ++){
			cout << ans1[i] << " " << ans2[i];
			cout << endl;
		}
		t = true;
		return ;
	}
	else {
		if (num[i] == pos[i]){
			DFS (i + 1, tep, step);
		}
		else {
			bool ff = false;
			int u = color[i][num[i]];
			for (int j = 1; j <= n; j ++){
				int tep1 = 0;
				while (num[j] == m && u == color[j][num[j]]){
					ff = true;
					pos[j] ++;
					num[j] ++;
					num[i] --;
					ans1[tep + tep1] = i;
					ans2[tep + tep1] = j;
					tep1 ++;
				}
				DFS (i + 1, tep + tep1, step + tep1);
				for (int i = 1; i <= tep1; i ++){
					ans1[tep + i] = 0;
					ans2[tep + 1] = 0;
					pos[j] --;
					num[j] --;
					num[i] ++;
				}
			}
			if (!ff){
				int tepp = 0;
				while (num[i] != pos[i]){
					ans1[tep + tepp] = i;
					ans2[tep + tepp] = n + 1;
					ans[tep1 + tepp] = color[i][num[i]];
					num[i] --;
					tepp ++;
				}
				tep1 += tepp;
				DFS (i + 1, tep + 1, step + 1);
				tep1 -= tepp;
			}
		}
	}
}

void work (){
	for (int i = tep1; i >= 1; i --){
		cout << n + 1 << " " << r[ans[i]] << " ";
	}
}

int main (){
	freopen ("ball.in", "r", stdin);
	freopen ("ball.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			cin >> color[i][j];
		}
		num[i] = m;
	}
	if (n == 1){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i ++){
		bool f = true;
		for (int j = 1; j <= m; j ++){
			if (color[i][j] != color[i][j + 1]){
				if (f){
					pos[i] = j;
					f = false;
				}
			}
		}
	}
	for (int i = 1; i <= n; i ++){
		r[color[i][pos[i]]] = i;
	}
	for (int i = 1; i <= n; i ++){
		if (num[i] != pos[i]){
			for (int j = num[i]; j > pos[i]; j --){
				ans[num[i] - j + tep1 + 1] = color[i][j];
			}
			step += num[i] - pos[i];
			tep1 += num[i] - pos[i];
		}
	}
	cout << step + tep1 << endl;
	for (int i = 1; i <= n; i ++){
		if (num[i] != pos[i]){
			for (int j = num[i]; j > pos[i]; j --){
				cout << i << " " << n + 1 << " ";
			}
		}
	}
	work ();
	fclose (stdin);
	fclose (stdout);
	return 0;
}
