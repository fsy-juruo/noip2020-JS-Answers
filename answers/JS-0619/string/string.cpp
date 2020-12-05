#include<bits/stdc++.h>
using namespace std;
#define maxn 1050005
#define maxm 2000005
#define int long long
#define inf 0x3f3f3f3f
#define mod 1000000007
//#define local
void file(string ss){freopen((ss+".in").c_str(),"r",stdin);freopen((ss+".out").c_str(),"w",stdout);}
template<typename Tp> void read(Tp &x){
	x=0;int fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-'){fh=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=(x*10)+c-'0';c=getchar();}x*=fh;
}
int n,m;
char s[maxn];
int ans;
int nxt[maxn];
int ff[maxn],sf[maxn];

vector<int>Fc[200005];
void prep0(int N=200000){
	for(int i=1;i<=N;++i){
		for(int j=1;i*j<=N;++j){
			Fc[i*j].push_back(i);
		}
	}
}

namespace Subsolve{
	
	struct BIT{
		int b[maxn];
		void add(int x,int v){for(x++;x<=n+1;x+=(x&(-x)))b[x]+=v;}
		int ask(int x){int ret=0;for(x++;x;x-=(x&(-x)))ret+=b[x];return ret;}
		void clear(){for(int i=0;i<=n+1;++i)b[i]=0;}
	}T;
	
	vector<int>qq[maxn],pp[maxn];
	
	int h[30];
	void prep(){
		T.clear();
		nxt[1]=0;
		for(int i=2,j=0;i<=n;++i){
			while(j&&s[i]!=s[j+1])j=nxt[j];
			if(s[i]==s[j+1])++j;
			nxt[i]=j;
		}
		int tsm=0;
		for(int i=0;i<26;++i)h[i]=0;
		for(int i=1;i<=n;++i){
			h[s[i]-'a']++;
			if(h[s[i]-'a']%2==0)--tsm;
			else ++tsm;
			ff[i]=tsm;
		}
		tsm=0;
		for(int i=0;i<26;++i)h[i]=0;
		for(int i=n;i;--i){
			h[s[i]-'a']++;
			if(h[s[i]-'a']%2==0)--tsm;
			else ++tsm;
			sf[i]=tsm;
		}
	}
	int cc[maxn],ct;
	void fj(int x){
		ct=0;
		for(int i=1;i*i<=x;++i){
			if(x%i==0){
				cc[++ct]=i;
				if(i*i!=x)cc[++ct]=x/i;
			}
		}
		sort(cc+1,cc+ct+1);
	}
	int cc2(int x){
		return upper_bound(cc+1,cc+ct+1,x)-cc-1;
	}
	int cc21(int nn,int x){
		return upper_bound(Fc[nn].begin(),Fc[nn].end(),x)-Fc[nn].begin();
	}
	int calc1(int p){
		int tms=(p-nxt[p]),len=p-nxt[p];
		if(p%tms==0)tms=p/tms;
		else tms=1,len=p;
		
		int ret=0;
		for(int l=1,r;l<=tms;l=r+1){
			r=tms/(tms/l);
			int ll=(l-1)*len,rr=r*len;
			ret+=cc21(tms,tms/l)*(T.ask(rr)-T.ask(ll));
		}
		for(int i=0;i<Fc[tms].size();++i){
			int ps=Fc[tms][i]*len;
			if(ff[ps]<=sf[p+1])ret--;
		}
		return ret;
	}
	
	int calc(int p){
		int tms=(p-nxt[p]),len=p-nxt[p];
		if(p%tms==0)tms=p/tms;
		else tms=1,len=p;
		if(tms<200000){
			return calc1(p);
		}
		fj(tms);
		int ret=0;
		for(int l=1,r;l<=tms;l=r+1){
			r=tms/(tms/l);
			int ll=(l-1)*len,rr=r*len;
			ret+=cc2(tms/l)*(T.ask(rr)-T.ask(ll));
		}
		for(int i=1;i<=ct;++i){
			int ps=cc[i]*len;
			if(ff[ps]<=sf[p+1])ret--;
		}
		return ret;
	}
	void solve(){
		prep();
		ans=0;
		for(int i=0;i<=n;++i)qq[i].clear(),pp[i].clear();
		for(int i=2;i<n;++i){
			qq[sf[i+1]].push_back(i);
		}
		for(int i=1;i<=n;++i)pp[ff[i]].push_back(i);
		for(int i=0;i<=n;++i){
			for(unsigned j=0;j<pp[i].size();++j)T.add(pp[i][j],1);
			for(unsigned j=0;j<qq[i].size();++j)ans+=calc(qq[i][j]);
		}
		
		printf("%lld\n",ans);
	}
}
signed main(){
	#ifndef local
		file("string");
	#endif
	prep0();
	int CasT;
	read(CasT);
	while(CasT--){
		scanf("%s",s+1);n=strlen(s+1);
		Subsolve::solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

