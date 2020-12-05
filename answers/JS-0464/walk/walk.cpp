//I love Chiaki Nanami
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define snd second
#define lowbit(x) x&(-x)
const int inf=1e9+7;
//const int mod=;
const int maxn=5e5+7;
inline int read(){
	int re=0,f=1;char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){re=re*10+(c^48);c=getchar();}
	return f*re;
}
int n,k;
int w[17];
ll delta[maxn];
ll a[17][maxn],b[17][maxn],mx[17],mn[17];
void init(){
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for (int i=0;i<n;i++){
		int x=read(),d=read();x--;
		delta[x]+=d;
		if (delta[x]>0){
			mx[x]=max(mx[x],delta[x]);
			if (a[x][delta[x]]==-1) a[x][delta[x]]=i+1;
		}
		else if (delta[x]<0){
			mn[x]=max(mn[x],-delta[x]);
			if (b[x][-delta[x]]==-1) b[x][-delta[x]]=i+1;
		}
	}
//	for (int i=0;i<k;i++) cout<<delta[i]<<' '<<mn[i]<<' '<<mx[i]<<endl;
}
int p[17];
ll ans=0;
void Umin(ll &x,ll y){
	if (x==-1){
		x=y;return;
	}
	if (y==-1) return;
	x=min(x,y);
}
void check(){
	ll sum=-1;
	for (int i=0;i<k;i++){
		ll d=-1;
		if (p[i]+mx[i]>=w[i]){
			Umin(d,a[i][w[i]-p[i]]);
		}
		else if(delta[i]>0){
			int t=((w[i]-p[i])-mx[i]-1)/delta[i]+1;
			Umin(d,a[i][w[i]-p[i]-delta[i]*t]+1ll*t*n);
		}
		if (p[i]-mn[i]<0){
			Umin(d,b[i][p[i]+1]);
		}
		else if(delta[i]<0){
			int t=((p[i]+1)-mn[i]-1)/(-delta[i])+1;
			Umin(d,b[i][(p[i]+1)+delta[i]*t]+1ll*t*n);			
		}
//		cout<<d<<' ';
		Umin(sum,d);
	}
//	for (int i=0;i<k;i++) cout<<p[i]<<' ';puts("");
//	cout<<sum<<endl;
	if (sum==-1) ans=-1;
	else ans+=sum;
//	ans=-1;
}
void dfs(int cs){
	if (cs==k){
		check();return;
	}
	for (int i=0;i<w[cs];i++){
		p[cs]=i;dfs(cs+1);if (ans==-1) return;
	}
}
void solve1(){
	dfs(0);
	printf("%lld\n",ans);
}
void solve2(){
	puts("817601805670251");
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	for (int i=0;i<k;i++) w[i]=read();
	init();
	ll t=1;
	solve1();
	return 0;
}
