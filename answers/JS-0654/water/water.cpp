#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
const int mod=1000000007;
const int inf=1000000000;
const ll infll=1000000000000000000ll;
const ll modll=1000000007ll;

const int maxn=100005;
int m,n;
queue<int> q;
vector<int> v[maxn];
ll P[maxn],Q[maxn];
int in[maxn],IS[maxn];

ll GCD(ll X,ll Y) {
	if(Y==0) return X;
	return GCD(Y,X%Y);
}

void myfacAdd(int pos1,int pos2) {
	P[pos2]=P[pos2]*Q[pos1]+P[pos1]*Q[pos2];
	Q[pos2]*=Q[pos1];	
	ll tmp=GCD(P[pos2],Q[pos2]);
	P[pos2]/=tmp;
	Q[pos2]/=tmp;
	return;
}

void bfs() {
	for(int i=1;i<=n;i++)
		Q[i]=1ll;
	for(int i=1;i<=n;i++)
		if(in[i]==0) {
			q.push(i);
			P[i]=1ll;
		}
	while(!q.empty()) {
		int pos=q.front();
		q.pop();
		if(sz(v[pos])==0) {
			IS[pos]=1;
			continue;
		}
		Q[pos]*=sz(v[pos]);
		ll tmp=GCD(P[pos],Q[pos]);
		P[pos]/=tmp;
		Q[pos]/=tmp;		
		for(int i=0;i<sz(v[pos]);i++) {
			int j=v[pos][i];			
			myfacAdd(pos,j);
			in[j]--;
			if(in[j]==0) q.push(j);
		}
	}
	return;
}

int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		int cnt;
		scanf("%d",&cnt);
		for(int j=1;j<=cnt;j++) {
			int k;
			scanf("%d",&k);
			v[i].pb(k);
			in[k]++;
		}
	}
	bfs();
	for(int i=1;i<=n;i++)
		if(IS[i]) printf("%lld %lld\n",P[i],Q[i]);
	return 0;
}
