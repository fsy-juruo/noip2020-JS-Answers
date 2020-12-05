#include<bits/stdc++.h>
#define x0 pmtx0
#define x1 pmtx1
#define y0 pmty0
#define y1 pmty1
#define pb push_back
#define mp make_pair
#define DEBUG printf("Passing Line %d in function [%s].\n",__LINE__,__FUNCTION__)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int > vi;
typedef pair<int ,int > pii;


template<typename T> inline void read(T &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	x*=f;
}
template<typename T> inline void write(T x){
	if(!x){putchar('0');return ;}
	if(x<0){putchar('-');x=-x;}
	static int st[27];int tot=0;
	while(x){st[++tot]=x%10;x/=10;}
	while(tot)putchar(st[tot--]+'0');
}
const int maxn=100007,INF=0x3f3f3f3f;
const int MOD=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

template<typename T> inline void chkmin(T &x,T y){x=(x<y?x:y);}
template<typename T> inline void chkmax(T &x,T y){x=(x<y?y:x);}
template<typename T> inline T ABS(T x){return (x<0?-x:x);}
inline int mod1(int x){if(x>MOD)x-=MOD;return x;}
inline int mod2(int x){if(x<0)x+=MOD;return x;}
inline void add(int &x,int y){x=mod1(x+y);}
inline void sub(int &x,int y){x=mod2(x-y);}
int n,m;
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
struct Frac{
	ll a,b;
	friend Frac operator +(const Frac &a,const Frac &b){
		ll g=gcd(a.a*b.b+b.a*a.b,b.b*a.b);
		return (Frac){(a.a*b.b+b.a*a.b)/g,b.b*a.b/g}; 
	}
}w[maxn];
int ind[maxn];
vector<int> G[maxn];
queue<int > q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,d;i<=n;i++){
		scanf("%d",&d);
		for(int j=1,v;j<=d;j++){
			scanf("%d",&v);
			ind[v]++;
			G[i].pb(v);
		}
	}
	for(int i=1;i<=n;i++){
		if(i<=m)w[i]=(Frac){1,1};
		else w[i]=(Frac){0,1};
		if(!ind[i])q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		Frac rt=w[u];
		rt.b*=G[u].size();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			w[v]=w[v]+rt;
			ind[v]--;
			if(ind[v]==0){q.push(v);}
		}
	}
	
	for(int u=1;u<=n;u++){
		if(!G[u].size()){
			ll g=gcd(w[u].a,w[u].b);
			printf("%lld %lld\n",w[u].a/g,w[u].b/g);
		}
	}
	return 0;
}
//THINGS TO REMEMBER
//1.LONG LONG !!!!
//2.FREOPEN!!!!(AND FILENAME)
//3.MAXN!!!!(AND MEMORY LIMIT)
//4.BORDER CASE!!!!!


