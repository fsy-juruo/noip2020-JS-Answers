/* tourist bless me
 * lxl bless me
 * rqy bless me
 * fuckccf
 */
// Where there's will, there's a way.
#include <cstdio>
#include <map>
#define int long long

using namespace std;
const int mod = 1e9 + 7;

bool flag;
int n,k,ans,mul = 1,w[15],x[15],m[15];
int c[500005],d[500005];
map < int,bool > vis[20]; 

inline int read() {
#define gc c = getchar()
	int d = 0,f = 0,gc;
	while(c < 48 || c > 57) f |= (c == '-'),gc;
	while(c > 47 && c < 58) d = (d << 1) + (d << 3) + (c ^ 48),gc;
#undef gc
	return f ? -d : d;
}

void exgcd(int a,int b,int& x,int& y) {
	if(!b) x = 1,y = 0;
	else exgcd(b,a % b,y,x),y -= a / b * x;
}

int inv(int a) {
	int x,y;
	exgcd(a,mod,x,y);
	return (x % mod + mod) % mod;
}

signed main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n = read(),k = read();
	for(int i = 1;i <= k;i ++) {
		w[i] = m[i] = read();
		mul = mul * w[i] % mod;
	}
	for(int i = 1;i <= n;i ++) {
		c[i] = read(),d[i] = read();
		x[c[i]] += d[i];
	}	 
	for(int i = 1;i <= k;i ++) {
		flag |= x[i];
		x[i] = 0;
	}
	if(!flag) {
		puts("-1");
		return 0;
	}
	for(int i = 1;;i ++) {
		if(i == n + 1) i = 1;
		ans = (ans + mul) % mod;
		x[c[i]] += d[i];
		if(!x[c[i]]) continue;
		if(!vis[c[i]][x[c[i]]]) mul = mul * inv(w[c[i]]) % mod * (-- w[c[i]]) % mod;
		vis[c[i]][x[c[i]]] = true;
		if(x[c[i]] < 0) vis[c[i]][x[c[i]] + m[c[i]] + 1] = true;
		else vis[c[i]][x[c[i]] - m[c[i]] - 1] = true;
		if(!w[c[i]] || !mul) break;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
