#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch!='-' and (ch>'9' or ch<'0')) ch=getchar();
	if(ch=='-') f=-f,ch=getchar();
	while(ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define nn 500008
#define wn 10
int n,k;
int c[nn],d[nn];
int wi[wn];
int cx[nn][wn],addx[nn][wn],subx[nn][wn];
int lb[nn][wn],rb[nn][wn];
#define ll long long 
#define mod 1000000007
void _max(int&x,int y){
	x=max(x,y);
}
void _min(int&x,int y){
	x=min(x,y);
}
void _max(ll&x,ll y){
	x=max(x,y);
}
void _min(ll&x,ll y){
	x=min(x,y);
}
ll ans=0;
ll haruhi(ll x,ll y){
	return (x+y-1)/y;
}
ll s2(ll x,ll k){
	return (1+k)*k/2*x%mod; 
}
ll solve(ll l[],ll r[],ll ex){
	ll res=0;ex%=mod;
	long long last=1;for(int i=0;i<k;i++) last=last*(r[i]-l[i]+1)%mod;
//	cout<<last<<"\n";
	for(int i=1;i<=n;i++){
		long long now=1;
		for(int j=0;j<k;j++) 
			now=now*max(0ll,min(r[j],(ll)rb[i][j])-max((ll)lb[i][j],l[j])+1)%mod;
		res+=(last-now)*(i+ex)%mod,res%=mod;
		last=now;
	}
//	cout<<last<<"\n";
	return res%mod;
}	
ll l[wn],r[wn];
void moody(int x=1){
	for(int i=0;i<k;i++) {
		if(l[i]<lb[n][i]) l[i]=lb[n][i];
		if(r[i]>rb[n][i]) r[i]=rb[n][i];
		l[i]+=1ll*x*cx[n][i],r[i]+=1ll*x*cx[n][i];
	}	
}
ll qpow(ll x,ll y){
	ll res=1;while(y){
		if(y&1) res=res*x%mod;x=x*x%mod;
		y=y/2;
	}
	return res;
}
int zkw=12;
ll solve(ll f[],ll x){
	ll res=0;
	for(int i=1;i<=zkw;i++){
		ll p=1;
		for(int j=1;j<=zkw;j++) if(i!=j) p=p*(x-j)%mod*qpow(i-j,mod-2)%mod;
		res=(res+p*f[i])%mod;
	}
	return res;
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();zkw=k+3;	
	for(int i=0;i<k;i++) wi[i]=read(),wi[i]--;
	for(int i=1;i<=n;i++) {
		c[i]=read()-1,d[i]=read();
		for(int j=0;j<k;j++) cx[i][j]=cx[i-1][j],
					addx[i][j]=addx[i-1][j],subx[i][j]=subx[i-1][j];
		cx[i][c[i]]+=d[i];
		_max(addx[i][c[i]],cx[i][c[i]]);
		_min(subx[i][c[i]],cx[i][c[i]]);
	}
	
	int flg=1;int nomove=1;
	for(int j=0;j<=n;j++) for(int i=0;i<k;i++) 
		lb[j][i]=-subx[j][i],rb[j][i]=wi[i]-addx[j][i];
	for(int i=0;i<k;i++) flg&=(lb[n][i]<=rb[n][i]),nomove&=(cx[n][i]==0);
	if(flg and nomove) return puts("-1")*0;
	
	long long last=1;for(int i=0;i<k;i++) last=last*(wi[i]+1)%mod;
	for(int i=1;i<=n;i++){
		long long now=1;
		for(int j=0;j<k;j++) now=now*max(0,rb[i][j]-lb[i][j]+1)%mod;
		ans+=(last-now)*i%mod,ans%=mod;
		last=now;
	}

	long long res=0,away=0;
	if(flg){
		long long tms=1e9;
		for(int i=0;i<k;i++){
			if(cx[n][i]>0) _min(tms,haruhi(wi[i]-lb[n][i]+1,cx[n][i]));
			if(cx[n][i]<0) _min(tms,haruhi(rb[n][i]+1,-cx[n][i]));
			l[i]=lb[n][i],r[i]=rb[n][i];
		}
		tms--;tms--;
		ll f[20];f[0]=0;
		for(int i=1;i<=zkw and i<=tms;i++) moody(),f[i]=f[i-1]+solve(l,r,i*n%mod);
		for(int i=0;i<k;i++)
			l[i]=lb[n][i],r[i]=rb[n][i];
		
		if(tms<=zkw) ans+=f[tms];
		else ans+=solve(f,tms);
		tms++;
		
		for(int i=0;i<k;i++){
			l[i]=l[i]+cx[n][i]*(tms-1);
			if(l[i]<lb[n][i]) l[i]=lb[n][i];
			r[i]=r[i]+cx[n][i]*(tms-1);
			if(r[i]>rb[n][i]) r[i]=rb[n][i];
			l[i]+=cx[n][i],r[i]+=cx[n][i];
		}
		ans+=solve(l,r,(tms)*n%mod);
	}
		
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}
