//#   # #####  #### #   # ####  #####
// # #    #   #     ##  # #   #   #
//  #     #    ###  # # # ####    #
//  #   # #       # #  ## #       #
//  #    ##   ####  #   # #     #####
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

ll qpow(ll a,ll n){
	ll res=1;
	while(n){
		if(n&1)res=res*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res;
}

int n,k,w[15],ow[15],cw[15],a[15];
pair<int,int> op[100005];
ll ans;

inline bool adv(){
	a[1]++;
	for(int i=1;i<=k;i++){
		if(a[i]>w[i]){
			a[i]=1;
			a[i+1]++;
		}else break;
	}
	if(a[k+1])return false;
	return true;
}

int main(){

	ios_base::sync_with_stdio(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>w[i],a[i]=1;
	for(int i=1;i<=n;i++){
		cin>>op[i].first>>op[i].second;
		ow[op[i].first]+=op[i].second;
	}
	a[1]=0;
	while(adv()){
		ll cur=1e18;
		memcpy(cw,a,sizeof(cw));
		for(int i=1;i<=n;i++){
			const int& c=op[i].first;
			const int& d=op[i].second;
			cw[c]+=d;
			if(cw[c]<1||cw[c]>w[c]){
				cur=i;
				break;
			}
			else{
				if(ow[c]>0)cur=min(cur,((w[c]-cw[c])/ow[c]+1)*(ll)n+i);
				if(ow[c]<0)cur=min(cur,((cw[c]-1)/-ow[c]+1)*(ll)n+i);
			}
		}
		ans+=cur;
	}
	cout<<ans<<'\n';

	return 0;
}
