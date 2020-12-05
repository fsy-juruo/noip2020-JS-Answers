#include<bits/stdc++.h>
using namespace std;
const int p=1000000007;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-48,ch=getchar();
	return s*f;
}int w[66],e[66],c[5*100000+1],d[5*100000+1],g[66];
long long inv[10000001];
bool ha[11][24000001];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k,maxx=0;
	long long ans=0,h=1;
	n=read(),k=read();
	for(int i=1;i<=k;++i){
		e[i]=w[i]=read();
		maxx=max(maxx,w[i]);
		h=(h*w[i])%p;
	}inv[1]=1;
	int b=min(maxx,10000000);
	for(int i=2;i<=b;++i)inv[i]=(inv[p%i]*(p-p/i))%p;
	for(int i=1;i<=n;++i){
		c[i]=read(),d[i]=read();
		g[c[i]]+=d[i];
	}int f=1;
	for(int i=1;i<=k;++i){
		if(g[i]!=0)f=0;
		g[i]=0;
	}int cnt=1;
	while(h){
		if(f&&cnt>n){
			printf("-1");
			return 0;
		}int t=(cnt-1)%n+1;
		g[c[t]]+=d[t];
		if(g[c[t]]==0){
			++cnt;continue;
		}int l;
		if(g[c[t]]>0)l=e[c[t]]-g[c[t]]+1;
		else l=-g[c[t]];
		if(!ha[c[t]][l]){
			ha[c[t]][l]=1;
			//ans=(ans+(((h/w[c[t]])%p)*cnt)%p)%p;
			//h=(((h/w[c[t]])%p)*(--w[c[t]]))%p;
			ans=(ans+(((h*inv[w[c[t]]])%p)*cnt)%p)%p;
			h=(((h*inv[w[c[t]]])%p)*(--w[c[t]]))%p;
		}++cnt;
	}printf("%lld",ans);
	return 0;
}
