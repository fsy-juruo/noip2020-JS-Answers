#include<bits/stdc++.h>
using namespace std;

namespace io{
	const int size=1<<22|1;
	char iBuf[size],*iS,*iT,c;
	char getc(){
		if(iS==iT){
			iS=iBuf;
			iT=iBuf+fread(iBuf,1,size,stdin);
		}
		if(iS==iT)return EOF;
		return *iS++;
	}
	template<class T>void qread(T &x){
		int f=1;
		for(c=getc();c<'0'||c>'9';c=getc())
			if(c=='-')f=-1;
		for(x=0;c>='0'&&c<='9';c=getc())
			x=(x<<3)+(x<<1)+(c&15);
		x*=f;
	}
}

const int maxn=500005;
const int mod=1e9+7;
const int maxm=11;
const int INF=0x3f3f3f3f;
const int inv4=250000002;
const int inv6=166666668;
const int L=1000000;
int n,k,deg,ans;
int w[maxn],c[maxn],d[maxn];
int pw[maxn<<1][maxm],poly[maxm],cl[maxm],cr[maxm],cs[maxm],l[maxm],r[maxm],s[maxm];

int calc(int x,int y){
	if(!x)return 0;
	if(x<=L)return pw[x][y];
	if(y==0)return x;
	else if(y==1)return 1LL*x*(x+1)/2%mod;
	else if(y==2)return 1LL*x*(x+1)%mod*(2*x+1)%mod*inv6%mod;
	else return 1LL*x*x%mod*(x+1)%mod*(x+1)%mod*inv4%mod;
}

void clr(){
	for(int i=0;i<=k;i++)poly[i]=0;
	deg=0;
}
void mul(int a,int b){
	deg++;
	for(int i=deg;i>=0;i--)
		poly[i]=(1LL*(i?poly[i-1]:0)*a+1LL*b*poly[i])%mod;
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	io::qread(n);io::qread(k);
	for(int i=1;i<=L;i++){
		pw[i][0]=1;
		for(int j=1;j<=k;j++)pw[i][j]=1LL*pw[i][j-1]*i%mod;
	}
	for(int j=0;j<=k;j++)for(int i=1;i<=L;i++)
		pw[i][j]=(pw[i-1][j]+pw[i][j])%mod;
	ans=1;
	for(int i=0;i<k;i++){
		io::qread(w[i]);
		ans=1LL*ans*w[i]%mod;
		l[i]=1;
		r[i]=w[i];
	}
	for(int i=0;i<n;i++){
		io::qread(c[i]);io::qread(d[i]);
		c[i]--;
		s[c[i]]+=d[i];
		if(s[c[i]]>0)r[c[i]]=min(r[c[i]],w[c[i]]-s[c[i]]);
		else l[c[i]]=max(l[c[i]],1-s[c[i]]);
	}
	for(int i=0;i<k;i++)
		cl[i]=l[i],cr[i]=r[i],cs[i]=s[i],l[i]=1,r[i]=w[i],s[i]=0;
	for(int i=0;i<n;i++){
		s[c[i]]+=d[i];
		if(s[c[i]]>0)r[c[i]]=min(r[c[i]],w[c[i]]-s[c[i]]);
		else l[c[i]]=max(l[c[i]],1-s[c[i]]);
		clr();
		poly[0]=1;
		int mn=INF,prod=1;
		for(int j=0;j<k;j++){
			int L=l[j],R=r[j];
			if(L>R){
				mn=-1;
				break;
			}
			prod=1LL*prod*(R-L+1)%mod;
			L-=cs[j];R-=cs[j];
			L=max(L,cl[j]);R=min(R,cr[j]);
			if(L>R){
				mn=0;
				continue;
			}
			if(cs[j]==0)mul(0,R-L+1);
			else{
				int S=abs(cs[j]);
				mn=min(mn,(R-L)/S+1);
				mul(mod-S,(R-L+S+1)%mod);
			}
		}
		if(mn<0)continue;
		if(mn==INF){
			puts("-1");
			return 0;
		}
		ans=(ans+prod)%mod;
		for(int j=0;j<=deg;j++)
			ans=(ans+1LL*poly[j]*calc(mn,j))%mod;
	}
	printf("%d\n",ans);
	return 0;
}
