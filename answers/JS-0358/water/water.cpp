// luogu uid 114082 求互关
// /se 希望能上电视 /se 
/* tourist bless me
 * lxl bless me
 * rqy bless me
 * fuckccf
 */
// Hard work leads to success.
// I'm curious that whether someone would notice this :D
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 1e5 + 5;

struct frac {
	int p,q;
	frac(int _p = 0,int _q = 1): p(_p),q(_q) {}
} ans[maxn];
int n,m;
int ind[maxn],outd[maxn];
vector < int > edge[maxn];
queue < int > q;

inline int read() {
#define gc c = getchar()
	int d = 0,f = 0,gc;
	while(c < 48 || c > 57) f |= (c == '-'),gc;
	while(c > 47 && c < 58) d = (d << 1) + (d << 3) + (c ^ 48),gc;
#undef gc
	return f ? -d : d;
}

int gcd(int a,int b) {
	if(!b) return a;
	return gcd(b,a % b);
}

frac ad(frac a,frac b) {
	int g = gcd(a.q,b.q);
	frac c;
	c.q = a.q / g * b.q;
	c.p = b.q / g * a.p + a.q / g * b.p;
	return c;
}

int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i ++) {
		outd[i] = read();
		for(int a,j = 1;j <= outd[i];j ++) {
			a = read();
			edge[i].push_back(a);
			ind[a] ++;
		}
	}
	for(int i = 1;i <= m;i ++) q.push(i),ans[i] = frac(1,1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(!outd[u]) continue;
		frac f = ans[u];
		f.q *= outd[u];
		for(int v,i = 0;i < edge[u].size();i ++) {
			v = edge[u][i];
			ind[v] --;
			ans[v] = ad(ans[v],f);
			if(!ind[v]) q.push(v);
		}
	}
	for(int i = 1;i <= n;i ++) {
		if(!outd[i]) {
			int g = gcd(ans[i].p,ans[i].q);
			printf("%d %d\n",ans[i].p / g,ans[i].q / g);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
