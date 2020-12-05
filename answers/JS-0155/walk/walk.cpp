#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	if(ch=='-') f=-1;
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+(ch^'0');
		ch=getchar();
	}
	
	return ans*f;
}

int n,k;
int c[500005],d[500005];
int w[15],cr[15];
int tot=0;
//int idx=0;

inline int solve(int cr[]){
	register int i;
	int ans=0;
	int a[15];
	for(i=1;i<=k;++i) a[i]=cr[i];
	for(i=1;;++i){
		int t=i%n;
		if(!t) t=n;
		a[c[t]]+=d[t];
		if(a[c[t]]>w[c[t]]||a[c[t]]<1){
			ans+=i;
			break;
		}
	}
	
	return ans;
}

int idx[15];
void dfs(int dep){
	if(dep==k+1){
		tot+=solve(cr);
		return;
	}
	for(idx[dep]=1;idx[dep]<=w[dep];++idx[dep]){
		cr[dep]=idx[dep];
		dfs(dep+1);
	}
}

signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	register int i,j;
	
	for(i=1;i<=k;++i) w[i]=read();
	for(i=1;i<=n;++i){
		c[i]=read();
		d[i]=read();
	}
	
	dfs(1);
	printf("%lld\n",tot);
	return 0;
}
