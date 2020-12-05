#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>


#define ll long long
using namespace std;
const int N=8e5,K=20,mo=1e9+7;
int n,k;
vector<pair<int,int> >acti;
ll w[K],lsq[N][K],mam[N][K],mim[N][K],state[K],ans;
inline bool valid(int step){
	for(int i=1;i<=k;i++)
		if(state[i]+mam[step][i]>w[i]||state[i]+mim[step][i]<1)
			return false;
	return true;		
}
inline ll bser(){
	ll l=0,r=3*n,mid;
	while(l<r){
		mid=l+r>>1;
		if(valid(mid))
			l=mid+1;
		else
			r=mid;
	}
	return (l-1)%mo;
}
void dfs(int step){
	if(step==k){
		ans+=bser();
		ans%=mo;
		return;
	}
	for(int i=1;i<=w[step+1];i++){
		state[step+1]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	int c,d;
	for(int i=1;i<=k;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=k;i++)
		mim[0][i]=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c,&d);
		acti.push_back(make_pair(c,d));
	}
	for(int tim=1;tim<=5;tim++)
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			lsq[tim*i][j]=lsq[tim*i-1][j];
			if(j==acti[i-1].first)
				lsq[tim*i][j]+=acti[i-1].second;
			mam[tim*i][j]=max(mam[tim*i-1][j],lsq[tim*i][j]);
			mim[tim*i][j]=min(mim[tim*i-1][j],lsq[tim*i][j]);
		}
	}
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
