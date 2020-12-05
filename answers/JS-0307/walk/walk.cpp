#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair < int , int > pii;
#define mpr make_pair
#define FS first
#define SC second
template < typename T > void UMIN(T &a,T b){a=(b<a?b:a);}
template < typename T > void UMAX(T &a,T b){a=(b>a?b:a);}
char readch(){
	char c=getchar();
	while(c==' '||c=='\n'||c=='\t'||c=='\r') c=getchar();
	return c;
}
LL readint(){
	char c=getchar();
	bool neg=0;
	while(c<'0' || c>'9'){
		if(c=='-') neg=1;
		c=getchar();
	}
	LL ret=0;
	while(c>='0' && c<='9'){
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return neg?-ret:ret;
}
const int I1e6=1000000,MOD=1000000007;
int powM(int V,int T=MOD-2){
	int R=1;
	while(T){
		if(T&1) R=(LL)R*V%MOD;
		V=(LL)V*V%MOD;
		T>>=1;
	}
	return R;
}
int n,m,w[11],c[500005],d[500005];
namespace brute{
	int pres[I1e6+5][11];
	void prec(){
		int i,j;
		for(i=0;i<=I1e6;++i){
			pres[i][0]=1;
			for(j=1;j<=10;++j){
				pres[i][j]=(LL)pres[i][j-1]*i%MOD;
			}
			if(i) for(j=0;j<=10;++j){
				pres[i][j]+=pres[i-1][j];
				if(pres[i][j]>=MOD) pres[i][j]-=MOD;
			}
		}
	}
}
namespace downpow{
	int stir[15][15],inv[15];
	void prec(){
		int i,j;
		stir[0][0]=1;
		for(i=1;i<=m;++i){
			for(j=1;j<=m;++j){
				stir[i][j]=((LL)j*stir[i-1][j]+stir[i-1][j-1])%MOD;
			}
		}
		for(i=1;i<=m+1;++i) inv[i]=powM(i);
	}
	int downpow(int x,int n){
		int ret=1;
		while(n--){
			ret=(LL)ret*(x--)%MOD;
		}
		return ret;
	}
	int dpoly[15];
	int getsum(int *npoly,int bnd){
		int i,j;
		memset(dpoly,0,sizeof(dpoly));
		for(i=0;i<=m;++i){
			for(j=0;j<=i;++j){
				dpoly[j]=(dpoly[j]+(LL)stir[i][j]*npoly[i])%MOD;
			}
		}
		int ret=0;
		for(i=0;i<=m;++i){
			ret=(ret+(LL)dpoly[i]*downpow(bnd+1,i+1)%MOD*inv[i+1])%MOD;
		}
		return ret;
	}
}
int getsum(int *poly,int bnd){
	if(m<=3) return downpow::getsum(poly,bnd);
	int ret=0,i;
	for(i=0;i<=m;++i){
		ret=(ret+(LL)poly[i]*brute::pres[bnd][i])%MOD;
	}
	return ret;
}
int mxd[500005][11],mnd[500005][11],ttd[500005][11];
int main(){
	// CHECK CORNER CASES !!!
	// CHECK INITIALIZATION !!!
	// djq txdy !!!
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int i,j,k;
	n=readint();m=readint();
	if(m<=3) downpow::prec(); else brute::prec();
	for(i=0;i<m;++i) w[i]=readint()-1;
	for(i=0;i<n;++i) c[i]=readint()-1,d[i]=readint();
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			if(j){
				mxd[j][i]=mxd[j-1][i];
				mnd[j][i]=mnd[j-1][i];
				ttd[j][i]=ttd[j-1][i];
			}
			if(c[j]==i){
				ttd[j][i]+=d[j];
				UMAX(mxd[j][i],ttd[j][i]);
				UMIN(mnd[j][i],ttd[j][i]);
			}
		}
	}
	int res=0;
	for(i=0;i<n;++i){
		int k0v=1,bnd=(int)2e9;
		int pl[11];
		memset(pl,0,sizeof(pl));
		pl[0]=1;
		for(j=0;j<m;++j){
//			printf("i=%d j=%d\n",i,j);
			int tot=w[j]+1;
			int allmx=mxd[n-1][j],allmn=mnd[n-1][j],alltt=ttd[n-1][j];
			int curmx=mxd[i][j],curmn=mnd[i][j],curtt=ttd[i][j];
			k0v=(LL)k0v*max(0,tot-(curmx-curmn))%MOD;
			if(bnd==-1) continue;
			if(alltt<0){
				alltt=-alltt;
				allmx=-allmx;
				allmn=-allmn;
				swap(allmx,allmn);
				curtt=-curtt;
				curmx=-curmx;
				curmn=-curmn;
				swap(curmx,curmn);
			}
			int inidif=max(allmx,alltt+curmx)-alltt-allmn;
			if(inidif>=tot){
				bnd=-1;
				continue;
			}
			// y=k*-alltt+(tot-inidif)
			int coe1=(MOD-alltt)%MOD,coe0=(tot-inidif+MOD)%MOD;
			if(alltt) UMIN(bnd,(tot-inidif)/alltt);
//			printf("alltt=%d coe0=%d\n",alltt,coe0);
			for(k=j;k>=0;--k){
				pl[k+1]=(pl[k+1]+(LL)pl[k]*coe1)%MOD;
				pl[k]=(LL)pl[k]*coe0%MOD;
			}
		}
		if(bnd==-1){
			res+=k0v;
			res%=MOD;
			continue;
		}
		if(bnd>1.5e9){
			printf("-1\n");
			return 0;
		}
//		printf("k0v=%d bnd=%d pl=",k0v,bnd);
//		for(j=0;j<=m;++j) printf("%d ",pl[j]);printf("\n");
		res+=((LL)getsum(pl,bnd)+(LL)MOD-(LL)pl[0]+(LL)k0v)%MOD;
		res%=MOD;
	}
	int prd=1;
	for(i=0;i<m;++i) prd=(LL)prd*(w[i]+1)%MOD;
	printf("%d\n",(res+prd)%MOD);
	return 0;
}
/*
code structure
0. 0!!!!!
1. enumerate index, record min delta & max delta & total delta for each dimension
2. if multiply k:
		suppose total delta>=0
		-mindelta<=sx<=H-(k-1)*totdelta-max(maxdelta,totdelta+curmaxdelta)
		thus we get the range of k and the coefficient
	calculate with brute force k=0
3. implement polynomial structure, support multiplying by kx+b
4. prec stirling, implement transfering to downpow polynomial
5. 
*/
