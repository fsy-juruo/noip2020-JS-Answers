#include <bits/stdc++.h>
using namespace std;

//when using pbds
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

#define pii pair<int,int>
#define ll long long
#define qi ios::sync_with_stdio(0)

template<typename T1,typename T2> ostream& operator<<(ostream& os,pair<T1,T2> p) {
	os<<"["<<p.first<<","<<p.second<<"]";
	return os;
}

template<typename T> ostream& operator<<(ostream& os,vector<T> v) {
	os<<"{";
	for(int i=0; i<v.size(); i++) {
		os<<v[i]<<" ";
	}
	os<<"}";
	return os;
}

int nextInt() {
	int ans=0;
	int neg=1;
	while(true) {
		char c=getchar();
		if(c=='-') {
			neg=-1;
			break;
		} else if(isdigit(c)) {
			ans=c-'0';
			break;
		}
	}

	while(true) {
		char c=getchar();
		if(isdigit(c)) {
			ans=ans*10+c-'0';
		} else {
			break;
		}
	}

	return ans*neg;
}

/**
NOIP TG 2020
By XGN from HHS

1. LL plz
2. array size plz
3. tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> plz
4. clear array for each test plz
5. DON'T SET UPPER BOUND FOR LAST ALGO PLZ

"If you should fail, I would f**k you"
--Hikari White
*/


//Absolute value "safely" =aSs
inline int ass(int x) {
	if(x<0) {
		return -x;
	} else {
		return x;
	}
}
const ll mod=1e9+7;

//Absolute safe modadd
inline void ADD(ll& x,ll y) {
	x+=y;
	if(x>=mod) {
		x-=mod;
	}
}

int n,m;
int w[15];

pii walk[500005];

struct Formula {
	ll coef[15];
	ll c;

	Formula() {
		memset(coef,0,sizeof(coef));
		c=0;
	}

	ll solve(int* now) {
		ll ans=c;
		for(int i=0; i<m; i++) {
			ADD(ans,1ll*now[i]*coef[i]%mod);
		}
		return ans;
	}

};



Formula theta;

int base[15];
int now[15];

inline bool in(int x,pii y) {
	return x>=y.first && x<=y.second;
}

void calcBase() {
	pii peak[15];
	int wked[15];
	memset(base,0,sizeof(base));
	memset(wked,0,sizeof(wked));
	for(int i=0; i<m; i++) {
		peak[i]=make_pair(0,0);
	}

	for(int i=0; i<n; i++) {
		int dim=walk[i].first;
		int dir=walk[i].second;
		wked[dim]+=dir;
		if(!in(wked[dim],peak[dim])) {

			//for (w_dim-base_dim)*step
			for(int j=0; j<m; j++) {
				if(j!=dim) {
//					cout<<i<<" "<<j<<" "<<i+1<<" "<<1ll*base[j]*(i+1)<<endl;
					ADD(theta.coef[j],i+1);
					ADD(theta.c,mod-1ll*base[j]*(i+1)%mod);
				}
			}
			base[dim]++;
			peak[dim]=make_pair(min(peak[dim].first,wked[dim]),max(peak[dim].second,wked[dim]));
//			assert(peak[dim].second-peak[dim].first==base[dim]);
		}
	}

}

ll manualCheck() {

//	cout<<"mc:";
//	for(int i=0;i<m;i++){
//		cout<<now[i]<<" ";
//	}
//	cout<<endl;

	pii peak[15];
	int wked[15];

	memset(wked,0,sizeof(wked));
	for(int i=0; i<m; i++) {
		peak[i]=make_pair(0,0);
	}

	ll ans=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(now[j]==0) {
				return ans;
			}
		}
		int dim=walk[i].first;
		int dir=walk[i].second;

		wked[dim]+=dir;
		if(!in(wked[dim],peak[dim])) {
			peak[dim]=make_pair(min(peak[dim].first,wked[dim]),max(peak[dim].second,wked[dim]));
			now[dim]--;
			for(int j=0; j<m; j++) {
				if(j!=dim) {
					ADD(ans,1ll*(i+1)*now[j]%mod);
				}
			}
		}
	}

	//???????
	assert(false);
	return -1;
}

namespace BL {
	void solve() {
		ll step=0;
		while(true) {

//		for(int i=0;i<m;i++){
//			cout<<now[i]<<" ";
//		}
//		cout<<endl;

			int cur[15];
			for(int i=0; i<m; i++) {
				cur[i]=now[i];
			}

			while(true) {

//			cout<<"R"<<endl;

				bool bad=false;
				for(int i=0; i<n; i++) {
//				cout<<"W"<<endl;
					int dim=walk[i].first;
					int dir=walk[i].second;
					cur[dim]+=dir;
//				cout<<"STOP:"<<cur[dim]<<endl;
					if(cur[dim]>=w[dim] || cur[dim]<0) {
						step++;
						bad=true;
						break;
					} else {
						step++;
//					cout<<"A"<<endl;
					}
				}
				
				if(step>=200000000){
					cout<<-1;
					exit(0);
				}
				if(bad) {
					break;
				}
			}

			int i;
			for(i=m-1; i>=0; i--) {
				if(now[i]==w[i]-1) {
					now[i]=0;
				} else {
					now[i]++;
					break;
				}
			}


			if(i==-1) {
				break;
			}
		}

		cout<<step<<endl;
	}
}

int main() {
	freopen("walk.in","r",stdin);
#ifndef XGN
	freopen("walk.out","w",stdout);
#endif

	n=nextInt();
	m=nextInt();
	for(int i=0; i<m; i++) {
		w[i]=nextInt();
	}
	for(int i=0; i<n; i++) {
		walk[i].first=nextInt()-1;
		walk[i].second=nextInt();
	}

//	if(n<=1000000) {
		BL::solve();
		return 0;
//	}

	calcBase();

//	printf("Formula:\n");
//	for(int i=0;i<m;i++){
//		printf("%I64d*w[%d]+",theta.coef[i],i);
//	}
//	printf("%I64d\n",theta.c);
//
//	printf("Restriction:");
//	for(int i=0;i<m;i++){
//		printf("%d*",base[i]);
//	}
//	cout<<endl;

	memcpy(now,w,sizeof(w));
	ll ans=0;
	while(true) {
		//base check
		bool baseOK=true;
		for(int i=0; i<m; i++) {
			if(now[i]<base[i]) {
				baseOK=false;
				break;
			}
		}

		if(!baseOK) {
			//oh no :(
			//manual check
			ans+=manualCheck();
			break;
		}

//		for(int i=0;i<m;i++){
//			cout<<now[i]<<" ";
//		}
//		cout<<"="<<theta.solve(now)<<endl;

		ADD(ans,theta.solve(now));

		ll tv=n;
		for(int i=0; i<m; i++) {
			now[i]-=base[i];
			tv=tv*now[i]%mod;
		}

		ADD(ans,tv);
	}

	cout<<ans<<endl;
	return 0;
}

