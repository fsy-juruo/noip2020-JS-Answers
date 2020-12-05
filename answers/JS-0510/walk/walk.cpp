#include<bits/stdc++.h>
#define re register
#define mod 1000000007
using namespace std;
template<typename T> void fr(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-48;
	x*=f;
}
template<typename T> void fw(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) fw(x/10);
	putchar(x%10+48);
}
template<typename T> void fwk(T x){fw(x);putchar(' ');}
template<typename T> void fwl(T x){fw(x);puts("");}
int loc[11],ans=0,temp[11],n,k,w[11],maxn[11],minn[11],c[50100],d[50100];
int lo[11][1010000];
inline void work(int cir){
	if(cir!=k){
		for(re int i=1;i<=w[cir];i++){
					loc[cir]=i;
				work(cir++);
		}
		return;
	}	
	else{
		int least=10100000,time=10100000;
		for(re int i=1;i<=k;i++){
			if(temp[i]>0)time=min((w[i]-maxn[i]-loc[i])/temp[i],time);
			if(temp[i]<0)time=min((w[i]+minn[i])/abs(temp[i]),time);
		}
		if(time<0)time=0;
		for(re int i=1;i<=k;i++){
			if((minn[i]+loc[i]+temp[i]*time<1)||(maxn[i]+loc[i]+temp[i]*time>w[i])){
				least=min(least,min(lo[i][-loc[i]-temp[i]*time],lo[i][w[i]-loc[i]-temp[i]*time+1]));
			}
		}
		if(least!=10100000){
			time=(time*n)%mod;
			ans=(ans+least+time)%mod;
			return;
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	fr(n);fr(k);
//	for(re int i=1;i<=k;i++)minn[i]=10100000;
	for(re int i=1;i<=k;i++)fr(w[i]);
	for(re int i=1;i<=n;i++){
		fr(c[i]);fr(d[i]);
		temp[c[i]]+=d[i];
		if(lo[i][c[i]]!=0)lo[c[i]][temp[c[i]]]=max(i,lo[c[i]][temp[c[i]]]);
		else lo[c[i]][temp[c[i]]]=i;
		minn[c[i]]=min(minn[c[i]],temp[c[i]]);
		maxn[c[i]]=max(maxn[c[i]],temp[c[i]]);
	}
	cout<<1<<endl;
	for(re int i=1;i<=k;i++)if(temp[i]!=0||(maxn[i]-minn[i])>=w[i])judge=1;
	if(judge==0){
		printf("-1\n");
		return 0;
	}
	else{
		work(1);
		fwl(ans);
	}
	return 0;
}

