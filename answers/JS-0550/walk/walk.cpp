#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p=1e9+7,N=5e5+5,K=10+2;
const ll W1=1e5+5,W2=1e6+5,W3=1e9+5;
//k 维, 每天的路线由 n 步移动构成
ll n,k;
ll w[K];
ll c[N],d[N];
ll pres[K];

ll mx[K],mn[K];//mx>0,mn<0;
ll fxst[K][N],fnst[K][N];
ll nst[K][W1];
ll ans=0;

int main(){
	memset(nst,0x3f3f3f3f,sizeof(nst));
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&c[i],&d[i]);
		pres[c[i]]+=d[i];
		ll weidu=c[i];
		if(pres[weidu]>mx[weidu]){
			mx[weidu]=pres[weidu];
			fxst[weidu][mx[weidu]]=i;
		}
		if(pres[weidu]<mn[weidu]){
			mn[weidu]=pres[weidu];
			fnst[weidu][-mn[weidu]]=i;
		}
	}
	bool Tep=true;
	for(int i=1;i<=k;i++){
		if(pres[i]!=0){
			Tep=false;
			break;
		}
		if(w[i]<mx[i]-mn[i]+1){
			Tep=false;
			break;
		}
	}
	if(Tep){
		printf("-1");
		return 0;
	}
	
	for(int i=1;i<=k;i++){
		if(pres[i]==0){
			for(int j=mn[i];j<0 && (-j)<=w[i];j++){
				ll nw=-j;
				nst[i][-j]=min(nst[i][-j],fnst[i][-j]);
			}
			for(int j=mx[i];j>0 && (1+w[i]-j)>0;j--){
				ll nw=w[i]-j+1;
				nst[i][nw]=min(nst[i][nw],fxst[i][j]);
			}
			continue;
		}
		if(pres[i]>0){
			for(int j=mn[i];j<0 && (-j)<=w[i];j++){
				ll nw=-j;
				nst[i][-j]=min(nst[i][-j],fnst[i][-j]);
			}
			for(int j=-mn[i]+1;j<=w[i];j++){
			 	ll lftst=w[i]-j+1;
			 	ll numxh=lftst/pres[i];
			 	if(numxh*pres[i]+(mx[i]-pres[i])>=w[i]){
			 		numxh--;
				 }
			 	lftst-=numxh*pres[i];
			 	ll rec=numxh*n%p;
			 	nst[i][j]=min(nst[i][j],rec+fxst[i][lftst]);
			 	//ans=(ans+rec+fxst[i][lftst])%p;
			}
			continue;
		}
		if(pres[i]<0){
			for(int j=mx[i];j>0&&(w[i]-j)>0;j--){
				ll nw=1+w[i]-j;
				nst[i][nw]=min(nst[i][nw],fxst[i][j]);
			}
			for(int j=1;j<=w[i]-mx[i];j++){
			 	ll lftst=j;
			 	
				 ll numxh=lftst/(-pres[i]);
			 	if(-numxh*pres[i]-mn[i]+pres[i]>=j){
			 		numxh--;
				 }
			 	ll rec=numxh*n%p;
			 	lftst-=abs(numxh*pres[i]);
			 	nst[i][j]=min(nst[i][j],rec+fnst[i][-lftst]);
			 	//ans=(ans+rec+fnst[i][lftst])%p;
			}
			continue;
		}
	}
	
	if(k==1){
		for(int i=1;i<=w[1];i++)
			ans=(ans+nst[1][i])%p;
	}
	if(k==2){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				ll rec=min(nst[1][i],nst[2][j]);
				ans=(ans+rec)%p;
			}
		}
	}
	if(k==3){
		for(int s=1;s<=w[3];s++)
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				ll rec=min(nst[1][i],nst[2][j]);
				rec=min(rec,nst[3][s]);
				ans=(ans+rec)%p;
			}
		}
	}
	if(k==4){
		for(int l=1;l<=w[4];l++)
		for(int s=1;s<=w[3];s++)
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				ll rec=min(nst[1][i],nst[2][j]);
				rec=min(rec,nst[3][s]);
				rec=min(rec,nst[4][l]);
				ans=(ans+rec)%p;
			}
		}
	}
	if(k==5){
		for(int r=1;r<=w[5];r++)
		for(int l=1;l<=w[4];l++)
		for(int s=1;s<=w[3];s++)
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				ll rec=min(nst[1][i],nst[2][j]);
				rec=min(rec,nst[3][s]);
				rec=min(rec,nst[4][l]);
				rec=min(rec,nst[5][r]);
				ans=(ans+rec)%p;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

