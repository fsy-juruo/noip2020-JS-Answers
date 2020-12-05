#include<bits/stdc++.h>
using namespace std;
#define fgx cerr<<"------------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
#define pii pair<LL,LL>
#define mpt make_pair
#define fr first
#define sc second
inline int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-1;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
#define M 100020
int n,m,od[M],ind[M],que[M],hd=1,tl; pii hv[M];
vector<int>vec[M];
inline LL Gcd(LL x,LL y){if(!y) return x; return Gcd(y,x%y);}
inline pii Get(LL x,LL y){LL gg=Gcd(x,y); return mpt(x/gg,y/gg);}
inline pii Add(pii x,pii y){
	LL xfr=x.fr,xsc=x.sc,yfr=y.fr,ysc=y.sc;
	LL fz=xfr*ysc+yfr*xsc,fm=xsc*ysc;
	return Get(fz,fm);
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		od[i]=read();
		for(int j=1,x;j<=od[i];j++)
			x=read(),vec[i].pb(x),ind[x]++;
	}
	for(int i=1;i<=n;i++) hv[i]=mpt(0ll,1ll);
	for(int i=1;i<=n;i++)
		if(!ind[i]) que[++tl]=i,hv[i]=mpt(1ll,1ll);
	while(hd<=tl){
		int x=que[hd++],y; pii nw=Get(hv[x].fr,(LL)hv[x].sc*od[x]);
		for(int i=0,TP=vec[x].size(),y;i<TP;i++){
			y=vec[x][i],hv[y]=Add(hv[y],nw),--ind[y];
			if(!ind[y]) que[++tl]=y;
		}
	}
	for(int i=1;i<=n;i++) if(!od[i]) printf("%lld %lld\n",hv[i].fr,hv[i].sc);
	return 0;
}
