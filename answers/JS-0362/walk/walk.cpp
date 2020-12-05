#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {if (ch=='-') neg=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*neg;
}
const int MAXN=1000;
int n,m;
int a[MAXN+5],b[MAXN+5],c[MAXN+5],d[MAXN+5];
int cp[MAXN+5];
int ans;
inline void dfs(int u) {
	if (u>m) {
		int cnt=1;
		for (int i=1;i<u;++i) cp[i]=b[i];
		while(true) {
			cp[c[cnt]]+=d[cnt];
			++ans;
			if (cp[c[cnt]]>a[c[cnt]] || cp[c[cnt]]<1) break;
			cnt=(cnt+1)%n;
			if (cnt==0) cnt=n;
		}
		return ;
	}
	for (int i=1;i<=a[u];++i) {
		b[u]=i;
		dfs(u+1);
		b[u]=0;
	}
}
signed main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;++i) a[i]=read();
	for (int i=1;i<=n;++i) c[i]=read(),d[i]=read();
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

3 2
3 3
1 1
2 -1
1 1
*/
