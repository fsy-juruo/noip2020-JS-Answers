#include<bits/stdc++.h>
#define D 7
#define N 100010
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=sig;
}
template<typename T> void write(T x){
	if (x<0){putchar('-');x=-x;}
	T y=0;int wei=0;
	while (x>9){y=y*10+x%10;x/=10;++wei;}putchar(x+48);
	while (wei--){putchar(y%10+48);y/=10;}
}
void open(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	return;
}
int n,m;
int len[N];
int g[N][D];
int du[N];
bool vis[N];
struct fs{
	ll x,y;
	void crt(){
		x=y=1;
		return;
	}
};
fs ans[N];
ll gcd(ll x,ll y){
	while (x%y) y^=x^=y^=x%=y;
	return y;
}
ll lcm(ll x,ll y){
	ll g=gcd(x,y);
	return x/g*y;
}
void yf(fs &x){
	ll g=gcd(x.x,x.y);
	x.x/=g;
	x.y/=g;
	return;
}
fs plu(fs u,fs v){
	ll w=lcm(u.y,v.y);
	fs res;
	res.x=w/u.y*u.x+w/v.y*v.x;
	res.y=w;
	yf(res);
	return res;
}
void dfs(int p){
	vis[p]=true;
	if (!len[p]) return;
	fs now=ans[p];
	now.y=now.y*len[p];
	yf(now);
	for (int i=1;i<=len[p];i++){
		du[g[p][i]]--;
		ans[g[p][i]]=plu(ans[g[p][i]],now);
		if (!du[g[p][i]]) dfs(g[p][i]);
	}
	return;
}
int main(){
	open();
	read(n);read(m);
	for (int i=1;i<=n;i++){
		read(len[i]);
		for (int j=1;j<=len[i];j++){
			read(g[i][j]);
			du[g[i][j]]++;
		}
	}
	for (int i=1;i<=n;i++) ans[i].y=1;
	for (int i=1;i<=n;i++)
		if (!du[i]&&!vis[i]){
			ans[i].crt();
			dfs(i);
		}
	for (int i=1;i<=n;i++)
		if (!len[i]){
			write(ans[i].x);putchar(' ');write(ans[i].y);putchar('\n');
		}
	return 0;
}

