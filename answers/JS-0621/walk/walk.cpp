#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define gc getchar
using namespace std;

inline int read(){
	int x=0,y=1;char c=gc();while(c<'0'||c>'9'){if(c=='-') y=-1;c=gc();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();return (y==1)?x:-x;
}

const int mod=1e9+7;
int n,k,w[15],pos[15],ma[15],mi[15],cur[15],a[15];
struct step{
	int c,d;
} sp[500005];
ll ans;

inline bool check(){
	for(int i=1;i<=k;i++){
		if(pos[i]!=0) return 0;
	}
	for(int i=1;i<=k;i++){
		if(ma[i]-mi[i]<=1) return 0;
	}
	return 1;
}

inline bool nxt(ll &res){
	for(int i=1;i<=k;i++){
		if(a[i]<=mi[i]||a[i]>=ma[i]) return 0;
	}
	for(int i=1;i<=k;i++){
		a[i]+=pos[i];
	}
	res=(res+n)%mod;
	return 1;
}

inline ll calc(){
	ll res=0;
	//for(int i=1;i<=k;i++) cout<<cur[i]<<' ';
	memcpy(a,cur,sizeof(a));
	while(nxt(res));
	//cout<<"("<<res<<" ";
	for(int i=1;i<=n;i++){
		res=(res+1)%mod;
		a[sp[i].c]+=sp[i].d;
		if(a[sp[i].c]>w[sp[i].c]||a[sp[i].c]<1) break;
	}
	//cout<<res<<endl;
	return res;
}

inline void dfs(int x){
	if(x==k+1){
		ans=(ans+calc())%mod;
		return;
	}
	for(int i=1;i<=w[x];i++){
		cur[x]=i;
		dfs(x+1);
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=k;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		sp[i].c=read();
		sp[i].d=read();
		pos[sp[i].c]+=sp[i].d;
		ma[sp[i].c]=max(ma[sp[i].c],pos[sp[i].c]);
		mi[sp[i].c]=min(mi[sp[i].c],pos[sp[i].c]);
	}
	for(int i=1;i<=k;i++){
		ma[i]=w[i]-ma[i]+1;
		mi[i]=-mi[i];
		//cout<<ma[i]<<' '<<mi[i]<<" "<<pos[i]<<endl;
	}
	if(check()){
		puts("-1");
		return 0;
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

















