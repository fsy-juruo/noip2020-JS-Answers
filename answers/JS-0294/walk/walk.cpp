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

namespace FastIO{
	const int SIZE=(1<<20);
	char in[SIZE],*inS=in,*inT=in+SIZE;
	inline char Getchar(){
		if(inS==inT){
			inT=(inS=in)+fread(in,1,SIZE,stdin);
			if(inS==inT)return EOF;
		}
		return *inS++;
	}
	char out[SIZE],*outS=out,*outT=out+SIZE;
	inline void Flush(){
		fwrite(out,1,outS-out,stdout);
		outS=out;
	}
	inline void Putchar(char c){
		*outS++=c;
		if(outS==outT)Flush();
	}
	struct NTR{
		~NTR(){Flush();}
	}ZTR;
}
#ifndef LOCAL
	#define getchar FastIO::Getchar
	#define putchar FastIO::Putchar
#endif
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
const int maxn=1000007,INF=0x3f3f3f3f;
const int MOD=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

template<typename T> inline void chkmin(T &x,T y){x=(x<y?x:y);}
template<typename T> inline void chkmax(T &x,T y){x=(x<y?y:x);}
template<typename T> inline T ABS(T x){return (x<0?-x:x);}
inline int mod1(int x){if(x>MOD)x-=MOD;return x;}
inline int mod2(int x){if(x<0)x+=MOD;return x;}
inline void add(int &x,int y){x=mod1(x+y);}
inline void sub(int &x,int y){x=mod2(x-y);}

int n,k;
int w[maxn],c[maxn],d[maxn];

int cnt[17];
int fst[maxn<<2];
int mn,mx;
map<int ,pair<int,int > > stp;
int mxmod[maxn];
ll ans=0;
void solve1(){
	mn=mx=0;
	for(int i=1;i<=n;i++){
		cnt[1]+=d[i];
		if(!fst[cnt[1]+n])fst[cnt[1]+n]=i;
		mn=min(mn,cnt[1]);
		mx=max(mx,cnt[1]);
	}
	mn=-mn;
	int rt=ABS(cnt[1]);
	if(rt==0&&mn+mx+1<=w[1]){
		puts("-1");
		return ;
	}

	for(int i=1;i<=mn;i++){
		if(stp.find(i)==stp.end())stp[i]=mp(LINF,1);
		stp[i].fi=min(stp[i].fi,fst[n-i]-1);
		if(cnt[1]<0){
			mxmod[i%rt]=i;
		}	
	}
	for(int i=w[1];i>=w[1]-mx+1;i--){
		if(stp.find(i)==stp.end())stp[i]=mp(LINF,1);
		stp[i].fi=min(stp[i].fi,fst[w[1]-i+1+n]-1);
//		ans[i]++;
		if(cnt[1]>0){
			mxmod[i%rt]=i;
		}
	}
	//mn+1,w[1]-mx
	
	//bruteforce
	
	for(int i=mn+1;i<=min(w[1]-mx,mn+rt);i++){
		ll c=(w[1]-mx-i)/rt+1;
		stp[mxmod[i%rt]].se+=c;
		ll tmp=(ll)ABS(i-mxmod[i%rt])/rt;

		ans+=(ll)(tmp+tmp+(cnt[1]<0?c-1:-c+1))*c/2*n;
	}
	for(map<int ,pair<int,int > >::iterator it=stp.begin();it!=stp.end();it++){
		ans+=(ll)((*it).se.se)*((*it).se.fi);
	}
	printf("%lld\n",ans);
	
}struct node{
	int t[6];
	friend bool operator<(const node &a,const node &b){
		if(a.t[5]!=b.t[5])return a.t[5]>b.t[5];
		if(a.t[4]!=b.t[4])return a.t[4]>b.t[4];
		if(a.t[3]!=b.t[3])return a.t[3]>b.t[3];
//		return a.t[1]>b.t[1];
		if(a.t[2]!=b.t[2])return a.t[2]>b.t[2];
		return a.t[1]>b.t[1];
	}
};
map<pair<node,int >,int > vis;

int dfs(node pos,int i){
//	cout<<pos.t[1]<<' '<<pos.t[2]<<' '<<i<<' '<<endl;;
	if(vis.find(mp(pos,i))!=vis.end()){
	return vis[mp(pos,i)];}
//		cout<<pos.t[1]<<' '<<pos.t[2]<<' '<<i<<' '<<vis[mp(pos,i)]<<endl;

	vis[mp(pos,i)]=-1;
	node rt=pos;
//	cout<<c[i]<<' '<<d[i]<<endl;
	rt.t[c[i]]+=d[i];
	if(rt.t[c[i]]>w[c[i]]||rt.t[c[i]]<1)return vis[mp(pos,i)]=1;
	int tmp=dfs(rt,(i)%n+1);
	if(tmp==-1)return -1;
	else return vis[mp(pos,i)]=tmp+1;
}
void solve_bf(){
	int tmp;
	for(int a1=1;a1<=w[1];a1++){
		if(k==1){
			tmp=dfs((node){0,a1,0,0,0,0},1);
			if(tmp==-1){
				puts("-1");
				exit(0);
			}
			ans+=tmp;
			continue;
		}
	for(int a2=1;a2<=w[2];a2++){
		if(k==2){
//			cout<<a1<<' '<<a2<<endl;
			tmp=dfs((node){0,a1,a2,0,0,0},1);
			if(tmp==-1){
				puts("-1");
				exit(0);
			}
			ans+=tmp;
//			cout<<endl;
			continue;
		}
	for(int a3=1;a3<=w[3];a3++){
		if(k==3){
			tmp=dfs((node){0,a1,a2,a3,0,0},1);
			if(tmp==-1){
				puts("-1");
				exit(0);
			}
			ans+=tmp;
			continue;
		}
	for(int a4=1;a4<=w[4];a4++){
		if(k==4){
			tmp=dfs((node){0,a1,a2,a3,a4,0},1);
			if(tmp==-1){
				puts("-1");
				exit(0);
			}
			ans+=tmp;
			continue;
		}
	for(int a5=1;a5<=w[5];a5++){
			tmp=dfs((node){0,a1,a2,a3,a4,a5},1);
			if(tmp==-1){
				puts("-1");
				exit(0);
			}
			ans+=tmp;
	}
	}
	}	
	}
	}
	
	printf("%lld\n",ans);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",w+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",c+i,d+i);
	}
	if(k==1){
		solve1();
		return 0;
	}
//	if(k==2){
//		solve2();
//		return 0;
//	}
//	if(k==3){
//		solve3();
//		return 0;
//	}
	solve_bf();
	return 0;
}
//THINGS TO REMEMBER
//1.LONG LONG !!!!
//2.FREOPEN!!!!(AND FILENAME)
//3.MAXN!!!!(AND MEMORY LIMIT)
//4.BORDER CASE!!!!!


