// I thought I needed BigFraction................
// I'm Idiot
//                   --- Zzzyt

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pll;

int n;
int m;
pll ans[100005];
vector<int> nei[100005];
int in[100005];
queue<int> Q;

ll Gcd(ll a,ll b){
	if(b==0)return a;
	return Gcd(b,a%b);
}

inline pll Sim(pll a){
	ll cd=Gcd(a.first,a.second);
	return mp(a.first/cd,a.second/cd);
}

inline pll Add(pll a,pll b){
	return Sim(mp(a.first*b.second+a.second*b.first,a.second*b.second));
}

void solver1(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		ans[i]=mp(0ll,1ll);
		int d,tmp;
		scanf("%d",&d);
		for(int j=0;j<d;j++){
			scanf("%d",&tmp);
			tmp--;
			nei[i].push_back(tmp);
			in[tmp]++;
		}
	}
	for(int i=0;i<m;i++){
		if(in[i]==0){
			Q.push(i);
		}
	}
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		if(x<m){
			ans[x]=Add(ans[x],mp(1ll,1ll));
		}
		pll cur=Sim(mp(ans[x].first,ans[x].second*nei[x].size()));
		for(int i=0;i<nei[x].size();i++){
			int nx=nei[x][i];
			in[nx]--;
			ans[nx]=Add(ans[nx],cur);
			if(in[nx]==0){
				Q.push(nx);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(nei[i].size()==0){
//			cerr<<i<<' '<<ans[i].first<<'/'<<ans[i].second<<endl;
			pll as=Sim(ans[i]);
			printf("%lld %lld\n",as.first,as.second);
		}
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	solver1();
	
	return 0;
}

