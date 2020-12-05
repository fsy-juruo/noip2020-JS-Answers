#include<bits/stdc++.h>
#define K 11
#define N 100005
using namespace std;
typedef long long ll;
const ll inf=0x7f7f7f7f;
const ll mod=1e9+7;
ll n,k,ans,w[K],d[N],c[N],now1[K],now2[K],val,dp[N<<1];
bool vis[N<<2],flag;
int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
namespace Subtask1{
	bool check(){
		for(int i=1;i<=k;i++)
			if(now2[i]<1||now2[i]>w[i])
				return 0;
		return 1;
	}
	ll calc(){
		ll cnt=0;
		for(int i=1;i<=k;i++)cnt=cnt*val+now2[i];
		return cnt;
	}
	void solve(){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=k;i++)now2[i]=now1[i];
		while(1){
			for(int i=1;i<=n;i++){
				now2[c[i]]+=d[i];
				ans++;
				if(ans>=mod)ans-=mod;
				if(!check())return;
			}
			ll vv=calc();
			if(vis[vv]){
				flag=1;
				return;
			}
			vis[vv]=1;
		}
	}
	void dfs(int x){
		if(x==k+1){
			solve();
			if(flag)return;
			return;
		}
		for(int i=1;i<=w[x];i++){
			now1[x]=i;
			dfs(x+1);
			if(flag)return;
		}
	}
	void work(){
		dfs(1);
		if(flag)puts("-1");
		else printf("%lld",ans);
	}
}
namespace Subtask2{
	bool check(ll pos){return (1<=pos&&pos<=w[1]);}
	void work(){
		ll l=inf,r=0,cnt;
		for(int i=1;i<=n;i++){
			cnt+=d[i];
			l=min(l,cnt);
			r=max(r,cnt);
			if(d[i]==1&&(!dp[cnt+1+n]))dp[cnt+n]=i;
			if(d[i]==-1&&(!dp[cnt-1+n]))dp[cnt+n]=i;
		}
		for(int i=1;i<=k;i++){
			if(ans>=mod)ans-=mod;
			if((!check(i+l))||(!check(i+r)))ans+=max(dp[1-i+n],dp[n-i+n])+1;
			else {
				if(cnt==0){
					puts("-1");
					return;
				}
				if(cnt>0){
					ll tot=(r-i)/cnt;
					ans=(ans+tot*n%mod)%mod;
					ans=(ans+dp[n-i-tot*cnt+n])%mod;
				}
				else {
					ll tot=(1-i)/cnt;
					ans=(ans+tot*n%mod)%mod;
					ans=(ans+dp[1-i-tot*cnt+n])%mod;
				}
			}
		}
		printf("%lld",ans);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	if(k==10)val=4;
	else val=11;
	for(int i=1;i<=k;i++)w[i]=read();
	for(int i=1;i<=n;i++)c[i]=read(),d[i]=read();
	if(n<=100)Subtask1::work();
	else if(k==1)Subtask2::work();
	else if(k==2)Subtask1::work();
	else puts("-1");
	return 0;
}

