// wish to get a better mark

#include<bits/stdc++.h>
#define re register int
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

using namespace std;

inline int rd(){
	int fl=1,x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}

inline void wr(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10),putchar('0'+(x%10));
	else putchar(x+'0');
}

// ---------- IO ---------- //

const int N=5e5+5,K=15,mod=1e9+7;
int n,k,w[K],c[N],d[N],nw[K],fuckccf=1e6;
ll sss=1;
bool ok=0,kk=1;
ll ans;

inline ll qaq(){
	ll sum=0;int qwq[K]={0};
	for(re i=1;i<=k;i++) qwq[i]=nw[i];
	while(1){
		bool awa=0;
		for(re i=1;i<=n;i++){
			qwq[c[i]]+=d[i];sum++;
			if(qwq[c[i]]>w[c[i]]||qwq[c[i]]<=0){awa=1;break;}
		}
		if(awa) break;awa=1;
		for(re i=1;i<=k;i++) if(qwq[i]!=nw[i]) awa=0;
		if(awa){ok=1;break;}
	}
	return sum;
}

inline void dfs(int step){
	if(ok) return ;
	if(step==k+1){ans=(ans+qaq())%mod;return ;}
	for(re i=1;i<=w[step];i++) nw[step]=i,dfs(step+1);
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=rd();k=rd();
	for(re i=1;i<=k;i++){
		w[i]=rd();sss*=w[i];
		if(sss>=fuckccf) kk=0;
	}
	for(re i=1;i<=n;i++) c[i]=rd(),d[i]=rd();
	if(k==1){
		int maxn=0,minn=0,awa=0,qwq[N]={0};qwq[n]=-1;
		for(re i=1;i<=n;i++){
			awa+=d[i],maxn=max(maxn,awa),minn=min(minn,awa);
			if(!qwq[awa+n]) qwq[awa+n]=i;
		}
		if(awa==0&&maxn-minn>=n){puts("-1");return 0;}
		for(re i=1;i<=w[1];i++){
			int kals=i;
			while(kals+minn>0&&kals+maxn<=w[1]) ans+=n,kals+=awa;
			if(kals+minn<=0&&kals+maxn>w[1]) ans+=min(qwq[n-kals],qwq[n+(w[1]+1-kals)]);
			else if(kals+minn<=0) ans+=qwq[n-kals];
			else ans+=qwq[n+(w[1]+1-kals)];
		}
		wr(ans);puts("");
		return 0;
	}
	if(kk){
		dfs(1);
		if(ok) puts("-1");
		else wr(ans),puts("");
		return 0;
	}
	puts("-1"); //fuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccffuckccf
	return 0;
}

// ---------- Main ---------- //

