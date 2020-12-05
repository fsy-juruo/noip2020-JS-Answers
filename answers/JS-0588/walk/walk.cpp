#include<bits/stdc++.h>
using namespace std;
inline void read(int &x) {
	x = 0;
	register char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
}
int n,k,w[15],C[100005],d[100005],ans;
bool flag;
void dfs1(int a,int step) {
	if(a < 1 || a > w[1]) {
		ans += step;
		return;
	}
	if(step == n) {
		flag = 1;
		return;
	}
	dfs1(a + d[step],step + 1);
}
void dfs2(int a,int b,int step) {
	if(a < 1 || a > w[1] || b < 1 || b > w[2]) {
		ans += step;
		return;
	}
	if(step == n) {
		flag = 1;
		return;
	}
	if(C[step] == 1)
		dfs2(a + d[step],b,step + 1);
	else dfs2(a,b + d[step],step + 1);
}
void dfs3(int a,int b,int c,int step) {
	if(a < 1 || a > w[1] || b < 1 || b > w[2] || c < 1 || c > w[3]) {
		ans += step;
		return;
	}
	if(step == n) {
		flag = 1;
		return;
	}
	if(C[step] == 1)
		dfs3(a + d[step],b,c,step + 1);
	else if(C[step] == 2)
		dfs3(a,b + d[step],c,step + 1);
	else dfs3(a,b,c + d[step],step + 1);
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= k; ++i)
		read(w[i]);
	for(int i = 1; i <= n; ++i) {
		read(C[i]);
		read(d[i]);
	}
	if(k == 1) {
		for(int i = 1; i <= w[1]; ++i) {
			flag = 0;
			dfs1(i,1);
			if(flag == 1)
				dfs1(i,1);
		}
		cout << ans;
		return 0;
	}
	if(k == 2) {
		for(int i = 1; i <= w[1]; ++i)
			for(int j = 1; j <= w[2]; ++j) {
				flag = 0;
				dfs2(i,j,1);
				dfs2(i,j,1);
			}
		cout << ans;
		return 0;
	}
	if(k == 3) {
		for(int i = 1; i <= w[1]; ++i)
			for(int j = 1; j <= w[2]; ++j)
				for(int k = 1; j <= w[3]; ++k) {
					flag = 0;
					dfs3(i,j,k,1);
					if(flag == 1)
						dfs3(i,j,k,1);
				}
		cout << ans;
		return 0;
	}
	cout << "-1";
	return 0;
}
