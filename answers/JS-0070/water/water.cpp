#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int H_many[100005];
bool v[100005],v2[100005];
struct ANS{
	LL x, y;
}ans[100005];
vector<int> g[100005];
LL gcd(LL a,LL b){
	if(!a) return b;
	else return gcd(b%a,a);
}
int Fast_read() {
	char ch = getchar();
	int sum = 0;
	while(ch >= '0'&&ch <= '9') {
		sum = (sum<<1) + (sum<<3) + (ch^48);
		ch = getchar();
	}
	return sum;
}
void dfs(int k, int a, int b) {
	if(v2[k]) {
		if(!ans[k].x&&!ans[k].y) {
			ans[k].x = a;
			ans[k].y = b;
		}else {
			ans[k].x = ans[k].x*b+ans[k].y*a;
			ans[k].y = ans[k].y*b;
			int mod = gcd(ans[k].x, ans[k].y);
			ans[k].x /= mod;
			ans[k].y /= mod;
		}
		return ;
	}
	for(int i = 0 ;i != g[k].size(); ++i) {
		int next = g[k][i];
		dfs(next, 1, H_many[k]*b);
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n = Fast_read(), m = Fast_read();
	int last_num = 0;
	for(int i = 1; i <= n; ++i) {
		int num = Fast_read();
		H_many[i] = num;
		if(!num) v2[i] = true;
		while(num) {
			int k = Fast_read();
			v[k] = true;
			g[i].push_back(k);
			num--;
		}
	}
	for(int i = 1; i <= n; ++i)
		if(!v[i]) dfs(i,1,1);
	for(int i = 1; i <= n; ++i)
		if(v2[i]) printf("%lld %lld\n", ans[i].x, ans[i].y);
	return 0;
}
