#include <bits/stdc++.h>
#define LL long long
#define forn(i,n) for(LL i=0;i<n;i++)
#define fori(i,a,b) for(LL i=a;i<=b;i++)
#define ff first
#define ss second
#define mp make_pair
#define MO 1000000007LL
using namespace std;

int main() {
	freopen("walk.in", "r", stdin); freopen("walk.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL n,k; cin>>n>>k;
	vector<LL> w(k);
	forn(i,k) cin>>w[i];
	vector<pair<LL, LL> > S(n);
	vector<LL> tot(k);
	forn(i,n) cin>>S[i].ff>>S[i].ss, S[i].ff--, tot[S[i].ff]+=S[i].ss;
	LL N=1;
	forn(i,k) N*=w[i];
	LL ans=0;
	bool flag=true;
	forn(i,k) if(tot[i]!=0) flag=false;
	if(flag) return cout<<-1, 0;
	forn(z2,N) {
		vector<LL> pos(k);
		LL z=z2;
		forn(i,k) {
			pos[i]=z%w[i];
			z/=w[i];
		}
//		forn(i,k) cout<<pos[i]<<" "; cout<<endl;
//		LL run=1e10;
//		forn(i,k) {
//			if(tot[i]==0) continue;
//			if(tot[i]<0) {
//				run=min(run, pos[i]/(-tot[i]));
//			}
//			else {
//				run=min(run, (w[i]-pos[i]-1)/tot[i]);
//			}
//		}
//		if(run==1e10) {
//			return cout<<-1<<endl, 0;
//		}
//		ans+=run*n%MO; ans%=MO;
//		forn(i,k) pos[i]+=tot[i]*run;
		ans++;
		forn(ii,1e10) {
			LL i=ii%n;
			pos[S[i].ff]+=S[i].ss;
			if(pos[S[i].ff]>=0 && pos[S[i].ff]<w[S[i].ff]) ans++;
			else break;
		}
		ans%=MO;
//		cout<<ans<<endl;
	}
	cout<<(ans%MO)<<endl;
	return 0;
}
