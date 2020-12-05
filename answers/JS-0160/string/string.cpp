#include<bits/stdc++.h>
using namespace std;

const int N=1100000;
const int mul=1528987;
const int MOD=1e9+7;
int T,n,tot;
long long ans;
int ap[30],val[30];
int h[N],suf[N],pw[N];
char s[N];

inline int hnum(int x,int y){
	return (h[y]+MOD-1ll*h[x-1]*pw[y-x+1]%MOD)%MOD;
}

void modify(int x){
	while(x<=27){
		val[x]++;
		x+=x&-x;
	}
}

int query(int x){
	int ret=0;
	while(x){
		ret+=val[x];
		x-=x&-x;
	}
	return ret;
}

void solve(){
	ans=0ll;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) h[i]=(1ll*h[i-1]*mul%MOD+s[i])%MOD;
	memset(ap,0,sizeof(ap));
	memset(suf,0,sizeof(suf));
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1];
		int x=s[i]-'a';
		ap[x]^=1;
		if(ap[x]) suf[i]++;
		else suf[i]--;
	}
	tot=0;
	memset(ap,0,sizeof(ap));
	memset(val,0,sizeof(val));
	for(int i=1;i<=n;i++){
		int hh=hnum(1,i);
		int x=s[i]-'a';
		ap[x]^=1;
		if(ap[x]) tot++;
		else tot--;
		for(int j=i;j<n;j+=i){
			if(hnum(j-i+1,j)!=hh) break;
			ans+=1ll*query(suf[j+1]+1);
		}
		modify(tot+1);
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=1ll*pw[i-1]*mul%MOD;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
