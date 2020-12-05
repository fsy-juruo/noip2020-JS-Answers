#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define N 1500005
#define F first
#define S second
#define random(x) (rand()%(x))
char s[N];
int n,tot=0,nxt[N],b[N],pr[N],cnt[26],fod[N],bod[N],suf[N][27],num[27];
vii fc;
inline ll gcd(ll a,ll b){
	ll c;
	while(b){
		c=b;b=a%b;a=c;
	}
	return a;
}
inline void gNxt(){
	int i=1,j=0;
	nxt[0]=-1;
	while(i<n){
		while(j!=-1&&s[i]!=s[j]) j=nxt[j];
		nxt[i]=j;++i;++j;
	}
}
inline void sieve(int n){
	b[0]=1;b[1]=1;
	for(int i=2;i<=n;++i){
		if(!b[i]) pr[++tot]=i;
		for(int j=1;i*pr[j]<=n;++j){
			b[i*pr[j]]=0;
			if(i%pr[j]==0) break;
		}
	}
}
/*
inline int dfs(int lv,int num){
	if(lv==fc.size()) return 
}
inline int calc(int xh){
	ii nd;
	for(int i=1;pr[i]*pr[i]<=xh;++i){
		if(xh%pr[i]==0){
			nd.F=i;nd.S=0;
			while(xh%pr[i]==0){
				xh/=pr[i];
				++nd.S;
			}
			fc.push_back(nd);
		}
	}
	if(xh>1) fc.push_back(ii(xh,1));
}
*/
inline ll calc(int xh,int l,int rs){
	ll ans=0;
	for(int i=1;i*i<=xh;++i){
		if(xh%i==0){
			if(l/i-2>=0) ans+=suf[l/i-2][rs];
			if(i*i<xh&&l/(xh/i)-2>=0) ans+=suf[l/(xh/i)-2][rs];
		}
	}
	/*
	for(int i=1;i*i<=xh;++i){
		if(xh%i==0){
			printf("%d ",l/i-2);
			if(i*i<xh) printf("%d ",l/(xh/i)-2);
		}
	}
	puts("");
	*/
	return ans;
}
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int T,xh,od;
	ll ans;
	scanf("%d",&T);
	sieve(1<<20);
	while(T--){
		scanf("%s",s);
		n=strlen(s);
		fc.clear();//init
		for(int i=0;i<=n;++i){
			fod[i]=0;bod[i]=0;nxt[i]=0;
			for(int j=0;j<=26;++j) suf[i][j]=0;
		}
		for(int i=0;i<=26;++i) num[i]=0;
		ans=0;//init
		gNxt();
		for(int i=0;i<26;++i) cnt[i]=0;
		cnt[s[0]-'a']=1;
		fod[0]=1;
		num[1]=1;
		od=0;
		for(int j=0;j<=26;++j){
			od+=num[j];
			suf[0][j]+=od;
		}
		for(int i=1;i<n;++i){
			++cnt[s[i]-'a'];
			if(cnt[s[i]-'a']&1) fod[i]=fod[i-1]+1;
			else fod[i]=fod[i-1]-1;
			/*
			suf[i]+=suf[i-1];
			if(fod[i]&1) ++suf[i];
			*/
			++num[fod[i]];
			od=0;
			for(int j=0;j<=26;++j){
				od+=num[j];
				suf[i][j]+=od;
			}
		}
		
		for(int i=0;i<26;++i) cnt[i]=0;
		
		for(int i=n-1;i>=0;--i){
			++cnt[s[i]-'a'];
			if(cnt[s[i]-'a']&1) bod[i]=bod[i+1]+1;
			else bod[i]=bod[i+1]-1;
			--num[fod[i]];
			//printf("%d\n",bod[i+1]);
			//for(int j=0;j<=5;++j) printf("%d ",num[j]);
			//puts("");
			/*
			for(int j=0;j<=bod[i+1];++j){
				suf[i]+=num[j];
			}
			*/
			//printf("%d\n",suf[i]);
		}
		//suf[n-1]=0;
		//for(int i=0;i<n;++i) printf("%d ",suf[i]);puts("");
		//for(int i=0;i<n;++i) printf("%d ",nxt[i]);puts("");
		for(int i=n-1;i>=2;--i){// c=[i,n-1]
			xh=i-1-nxt[i-1];
			if(i%xh) xh=i;
			xh=i/xh;
			//printf("%d %d %d:\n",xh,i,bod[i]);
			ans+=calc(xh,i,bod[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
