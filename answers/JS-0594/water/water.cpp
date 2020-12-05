#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
inline int read() {
	int f=1,x=0;char ch=getchar();
	for(; !isdigit(ch); ch=getchar()) if(ch=='-') f=0;
	for(; isdigit(ch); ch=getchar()) x=x*10+ch-'0';
	return f?x:-x;
}
#define pi pair<ll,ll>
#define x first
#define y second
struct node{
	int pos;
	pi now;
};

int n, m;
int d[N];
bool if_out[N];
vector <int> e[N];
pi ans[N];

ll gcd(ll x, ll y) {
	while(y^=x^=y^=x%=y) ;
	return x;
}

pi add(pi a, pi b) {
	ll fenmu = a.y*b.y;
	ll fenzi_a = a.x*b.y, fenzi_b = b.x*a.y;
	ll fenzi = fenzi_a+fenzi_b;
	ll opt = gcd(fenmu, fenzi);
	fenmu /= opt, fenzi /= opt;
	pi ans; ans.x=fenzi, ans.y=fenmu;
	return ans;
}

pi chu(pi a, ll b) {
	ll fenmu = a.y, fenzi = a.x;
	fenmu *= b;
	ll opt = gcd(fenmu, fenzi);
	fenmu /= opt, fenzi /= opt;
	pi ans; ans.x=fenzi, ans.y=fenmu;
	return ans;
}

queue <node> q;
void bfs(int s) {
	pi opt; opt.x=opt.y=1;
	node qwq; qwq.pos=s;qwq.now=opt;
	q.push(qwq);
	while(q.size()) {
		node fr = q.front(); q.pop();
		int x = fr.pos;
		pi nxt; nxt = chu(fr.now, (ll)d[x]);
		for(int i = 0; i < e[x].size(); i ++) {
			int y = e[x][i];
			ans[y] = add(ans[y], nxt);
			qwq.pos = y;qwq.now=nxt;
			q.push(qwq);
		}
	}
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i ++) {
		d[i] = read();
		for(int j = 1; j <= d[i]; j ++) {
			int v = read();
			e[i].push_back(v);
		}
		if(d[i] == 0) {
			if_out[i] = 1;
		}
		ans[i].x=0;ans[i].y=1;
	}
	for(int i = 1; i <= m; i ++) {
		bfs(i);
	}
	for(int i = 1; i <= n; i ++) {
		if(if_out[i]) 
			printf("%lld %lld\n", ans[i].x, ans[i].y);
	}
	return 0;
}

