#include <bits/stdc++.h>
using namespace std;
#define rg register
#define xh(i,l,r) for (rg int i=(l);i<=(r);i++)
#define read(a) scanf("%d",&(a))
#define write(a) printf("%d",(a))
#define writeln puts("")
#define qmax(a,b) ((a)<(b)?(b):(a))
#define qmin(a,b) ((a)>(b)?(b):(a))
#define Babara_is_so_cute(f) freopen(f".in","r",stdin);freopen(f".out","w",stdout);
#define Babara_is_the_best fclose(stdin);fclose(stdout);

typedef long long ll;
#define readl(a) scanf("%lld",&(a))
#define writel(a) printf("%lld",(a))

typedef vector<int> vi;
#define pb push_back

typedef pair<int,int> pii;
#define mp make_pair

const int N=131072+5;
const int MOD=998244353;
int tmd[N][30],n,len,cc[N];
vi d[N];
char ch[N];
bool t[26];
ll hash(int l,int r){
	ll res=0;
	xh(i,l,r){
		res=(res*26%MOD+cc[i])%MOD;
	}
	return res;
}
int cnt(int l,int r){
	int res=0;
	xh(i,0,25) if ((tmd[r][i]-tmd[l-1][i])%2==1) res++;
	return res;
}
void init(){
	cin>>ch;
	len=strlen(ch);
	xh(i,0,25) tmd[0][i]=0;
	xh(i,1,len){
		cc[i]=ch[i-1]-'a';
		xh(j,0,25) if (j==cc[i]) tmd[i][j]=tmd[i-1][j]+1;else tmd[i][j]=tmd[i-1][j];
	}
	//xh(i,2,1000) d[i].clear();
}
void solve(){
	int f,lab,dc;
	int ans=0;
	xh(i,3,len){
		f=cnt(i,len);
		dc=d[i-1].size();
		xh(j,0,dc-1){
			lab=d[i-1][j];
			ll ha=hash(1,lab);
			bool fl=1;
			xh(k,2,(i-1)/lab)
				if (hash((k-1)*lab+1,k*lab)!=ha){fl=0;break;}
			if (fl){
				memset(t,0,sizeof(t));
				int cn=0;
				xh(la,1,lab-1){
					t[cc[la]]^=1;
					if (t[cc[la]]) cn++; else cn--;
					if (cn<=f) ans++;
				}
			}
		}
	}
	write(ans);writeln;
}
int T;
int main(){
	Babara_is_so_cute("string")
	read(T);
	xh(i,2,131072){
		xh(j,1,131072/i){
			d[i*j].pb(i);
		}
	}
	xh(i,1,T){
		init();
		solve();	
	}
	Babara_is_the_best
	return 0;
}
