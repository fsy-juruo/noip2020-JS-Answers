#include<bits/stdc++.h>
#define x0 pmtx0
#define x1 pmtx1
#define y0 pmty0
#define y1 pmty1
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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
const int maxn=2000007,INF=0x3f3f3f3f;
const int MOD=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

template<typename T> inline void chkmin(T &x,T y){x=(x<y?x:y);}
template<typename T> inline void chkmax(T &x,T y){x=(x<y?y:x);}
template<typename T> inline T ABS(T x){return (x<0?-x:x);}
inline int mod1(int x){if(x>MOD)x-=MOD;return x;}
inline int mod2(int x){if(x<0)x+=MOD;return x;}
inline void add(int &x,int y){x=mod1(x+y);}
inline void sub(int &x,int y){x=mod2(x-y);}
int n;
int nxt[maxn];
char s[maxn];
void get_border(){
	int j=0;
	nxt[1]=0;
	for(int i=2;i<=n;i++){
		while(j!=0&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])j++;
		nxt[i]=j;
	}
}
int pref[maxn],suff[maxn];
int cnt[27];
void init_f(){
	for(int i=1;i<=n;i++){
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']&1)pref[i]=pref[i-1]+1;
		else pref[i]=pref[i-1]-1;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=n;i>=1;i--){
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']&1)suff[i]=suff[i+1]+1;
		else suff[i]=suff[i+1]-1;
	}
}
vector<pair<int ,int > > Q[maxn];// such query is as \foreach j\in[1,i] that f[j]<=k times w;

void add_query(){
	for(int i=2;i<n;i++){
		int j=i;
		for(;j<n;j+=i)if(j+i>=n||i%(i+j-nxt[j+i])!=0)break;
		int k=j/i;
		if(k&1){
			Q[i-1].pb(mp(suff[j+1],(k+1)>>1));
			if(j>i)Q[i-1].pb(mp(suff[j-i+1],k>>1));
		}else{
			Q[i-1].pb(mp(suff[j+1],k>>1));
			Q[i-1].pb(mp(suff[j-i+1],k>>1));
		}
	}
}
ll ans=0;
struct BIT{
	int t[30];
	void init(){memset(t,0,sizeof(t));}
	void update(int x){x++;for(;x<=27;x+=(x&(-x)))t[x]++;}
	int query(int x){int rt=0;x++;for(;x;x-=(x&(-x)))rt+=t[x];return rt;}
}T;
void get_query(){
	//BIT or O(26)
	//BUT I prefer BIT LOL :)
	for(int i=1;i<=n;i++){
		T.update(pref[i]);		
		for(int j=0;j<Q[i].size();j++){
//			cout<<Q[i][j].fi<<' '<<Q[i][j].se<<' '<<i<<endl;
			ans+=(ll)Q[i][j].se*T.query(Q[i][j].fi);
		}
	}
}
void init(){
	T.init();
	memset(pref,0,sizeof(pref));
	memset(suff,0,sizeof(suff));
	memset(cnt,0,sizeof(cnt));
	ans=0;
	for(int i=1;i<=n;i++){
		Q[i].clear();
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%s",s+1);
		n=strlen(s+1);
//		DEBUG;
		get_border();
//		DEBUG;
//		for(int i=1;i<=n;i++)printf("%d ",nxt[i]);
//		printf("\n");
		init_f();
//		DEBUG;
		add_query();
//		DEBUG;
		get_query();
		printf("%lld\n",ans);
	}
	return 0;
}
//THINGS TO REMEMBER
//1.LONG LONG !!!!
//2.FREOPEN!!!!(AND FILENAME)
//3.MAXN!!!!(AND MEMORY LIMIT)
//4.BORDER CASE!!!!!


