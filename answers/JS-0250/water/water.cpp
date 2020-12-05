#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
const int MAXN=100007;
int n,m;
inline ll gcd(ll x,ll y){
	while(y){
		ll t=x%y;
		x=y;
		y=t;
	}
	return x;
}
pa sum[MAXN];
vector<pa> ans[MAXN];
inline void work(int now){
	ll t=1;
	for(register vector<pa>::iterator it=ans[now].begin();it!=ans[now].end();++it){
		t=t/gcd(t,it->second)*it->second;
	}
	sum[now].second=t;
	for(register vector<pa>::iterator it=ans[now].begin();it!=ans[now].end();++it){
		sum[now].first+=t/it->second*it->first;
	}
	t=gcd(sum[now].first,sum[now].second);
	sum[now].first/=t,sum[now].second/=t;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i){
		ll d;
		scanf("%lld",&d);
		if(i<=m){
			for(register int j=1;j<=d;++j){
				int a;
				scanf("%d",&a);
				ans[a].push_back(pa(1,d));
			}
		}
		else if(d){
			if(ans[i].empty()){
				for(register int j=1;j<=d;++j){
					int a;
					scanf("%d",&a);
				}
				continue;
			}
			work(i);
			sum[i].second*=d;
			ll t=gcd(sum[i].first,sum[i].second);
			sum[i].first/=t,sum[i].second/=t;
//			cout<<sum[i].first<<" "<<sum[i].second<<endl;
			for(register int j=1;j<=d;++j){
				int a;
				scanf("%d",&a);
				ans[a].push_back(sum[i]);
			}
		}
		else{
			work(i);
//			for(register vector<pa>::iterator it=ans[i].begin();it!=ans[i].end();++it){
//				cout<<it->first<<" "<<it->second<<endl;
//			}
			printf("%lld %lld\n",sum[i].first,sum[i].second);
		}
	}
	fclose(stdin);
	fclose(stdout);
}

