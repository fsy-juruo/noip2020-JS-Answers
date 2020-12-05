#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
const int MOD=1e9+7;
int n,m,tot,ans;
int w[15],c[N],d[N],mn[15],mx[15],cur[15],mp[N*2];

void solve1(){
	tot=1;ans=0;
	for(int i=1;i<=m;i++) tot=1ll*tot*w[i]%MOD;
	for(int t=1;t<=2000;t++){
		int o=(t-1)%n+1;
		cur[c[o]]+=d[o];
		mx[c[o]]=max(mx[c[o]],cur[c[o]]);
		mn[c[o]]=min(mn[c[o]],cur[c[o]]);
		int ctot=1;
		for(int i=1;i<=m;i++){
			int l=1-mn[i];
			int r=w[i]-mx[i];
			if(l>r) ctot=0;
			else ctot=1ll*ctot*(r-l+1)%MOD;
		}
		ans=(ans+1ll*(tot+MOD-ctot)%MOD*t%MOD)%MOD;
		tot=ctot;
	}
	if(tot!=0) puts("-1");
	else printf("%d\n",ans);
}

void solve2(){
	for(int i=1;i<=n;i++){
		tot+=d[i];
		if(!mp[tot+N]) mp[tot+N]=i;
	}
	for(int i=1;i<=w[1];i++){
		int l=0,r=1000000;
		while(l<=r){
			int mid=(l+r)>>1;
			long long now=1ll*i+1ll*tot*mid;
			if(now<1ll||now>1ll*w[1]){
				r=mid-1;
				continue;
			}
			if(mp[N-int(now)]||mp[w[1]+1-int(now)+N]) r=mid-1;
			else l=mid+1;
		}
		r++;
		if(r>=1000000){
			puts("-1");
			return;
		}else{
			int now=i+tot*r;
			ans=(ans+1ll*r*n%MOD)%MOD;
			if(!mp[N-now]) ans=(ans+mp[w[1]+1-now+N])%MOD;
			else if(!mp[w[1]+1-now+N]) ans=(ans+mp[N-now])%MOD;
			else ans=(ans+min(mp[N-now],mp[w[1]+1-now+N]))%MOD;
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",w+i);
	for(int i=1;i<=n;i++) scanf("%d%d",c+i,d+i);
	if(m==1) solve2();
	else solve1();
	return 0;
}
