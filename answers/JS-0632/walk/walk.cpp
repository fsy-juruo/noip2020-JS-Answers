//Please! Just lemme pass!
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
int n,k,w[15],op[15],p[15],p1,p2,ans;
bool m1;
vector <pair<int,int> > ve;
void RLG_solve(){
	for (int i=1;i<=k;i++) p[i]=op[i];
	bool ok=true;
	bool ft=true;
	do{
		for (int i=0;i<n;i++){
			p[ve[i].first]+=ve[i].second;
			ans++;
			for (int j=1;j<=k;j++){
				if (p[j]<1 || p[j]>w[j]){
					ok=false;
					break;
				}
			}
			if (!ok) break;
		}
		if (ft){
			bool sm=true;
			for (int i=1;i<=k;i++){
				if (p[i]!=op[i]){
					sm=false;
					break;
				}
			}
			if (sm && ok) m1=true;
		}
		ft=false;
		if (m1) break;
	}while (ok);
}
void RLG_dfs(int dn){
	if (dn==k+1){
		RLG_solve();
		return;
	}
	if (m1) return;
	for (int i=1;i<=w[dn];i++){
		op[dn]=i;
		RLG_dfs(dn+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=1;i<=k;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>p1>>p2;
		ve.pb(mp(p1,p2));
	}
	if (n<=1000){
		RLG_dfs(1);
		if (m1) cout<<-1; else cout<<ans;
	}
	return 0;
}
