#include<bits/stdc++.h>
typedef int mrt;
#define int long long
using namespace std;
int n, k, w[11], c[500010], d[500010], fsta[11], fstb[11], fin[11], cur[11], ans, flag, cnt;
int stepwho[200020];
inline int read() {
	int n; char c; bool neg = false;
	while(!isdigit(c = getchar())) if(c == '-') neg = true;
	n = c - '0';
	while( isdigit(c = getchar()))  n = n * 10 + c - '0';
	return n * (neg ? -1 : 1);
}
vector<int> pos(1);
void work(int dim) {
	if(dim == k + 1) {
		cnt++;
		//for(int i = 1; i <= k; i++) printf("%d ", pos[i]); putchar('\n');
		for(int i = 1; i <= k; i++) cur[i] = pos[i];
		int a = 0;
		while(true) {
			bool b = 1;
			for(int i = 1; i <= k; i++) b = b && (cur[i] + fsta[i] <= w[i]) && (cur[i] + fstb[i] >= 1);
			if(b) for(int i = 1; i <= k; i++) cur[i] += fin[i];
			else break;
			a += n;
		}
		for(int i = 1; i < n; i++) {
			cur[c[i]] += d[i];
			if(cur[c[i]] > w[i] || cur[c[i]] < 1) return a += i, ans += a, void();
		}
		int t = 0;
		for(int i = 1; i <= n; i++) t |= fin[i];
		if(!t) return flag = true, void();
	}
	for(int i = 1; i <= w[dim]; i++) {
		pos.push_back(i);
		work(dim + 1);
		pos.pop_back();
		if(flag) return;
	}
}
mrt main() {
	freopen("walk.in",  "r", stdin);
	freopen("walk.out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= k; i++) w[i] = read();
	for(int i = 1; i <= n; i++) {
		c[i] = read(), d[i] = read();
		fin[c[i]] += d[i];
		fsta[c[i]] = max(fsta[c[i]], fin[c[i]]);
		fstb[c[i]] = min(fstb[c[i]], fin[c[i]]);
		if(k == 1 && !stepwho[fin[c[i]] + (int)1e5]) stepwho[fin[c[i]] + (int)1e5] = i;
	}
	//for(int i = -5; i <= 5; i++) printf("%d ", stepwho[(int)1e5 + i]); putchar('\n');
	if(n <= 1000) {
		work(1);
		if(flag) printf("-1\n");
		else printf("%d\n", ans);
	} else if(k == 1) {
		int ans[100010];
		memset(ans, 0, sizeof(ans));
		for(int i = -fstb[1]; i >= 1; i--) ans[i] = stepwho[-i + (int)1e5];
		for(int i = w[1]; i >= w[1] + 1 - fsta[1]; i--) ans[i] = stepwho[w[1] - i + (int)1e5 + 1];
		if(-fstb[1] < w[1] - fsta[1]) {
			if(fin[1] == 0) flag = true;
			if(fin[1] > 0) for(int i = w[1] - fsta[1]; i > -fstb[1]; i--)      ans[i] = n + ans[i + fin[1]];
			if(fin[1] < 0) for(int i = -fstb[1] + 1; i <= w[1] - fsta[1]; i++) ans[i] = n + ans[i + fin[1]];
		}//for(int i = 1; i <= w[1]; i++) printf("%d ", ans[i]); putchar('\n');
		if(flag) printf("-1\n");
		else printf("%d\n", accumulate(ans + 1, ans + w[1] + 1, 0) % (int)(1e9+7));
	}
	
	
}
