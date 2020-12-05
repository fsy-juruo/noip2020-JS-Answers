#include<bits/stdc++.h>
#define int long long
#define N ((1<<20)+5)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=b;i>=a;--i)
#define all(x) x.begin(),x.end()
#define VI vector<int>
#define pii pair<int,int>
#define fi first
#define SZ(x) ((int)x.size())
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int T,n,hs[N],pd[N],pre[N][26],P[N],S[N];
const int base = 26,mod = 998244353;
char s[N];
void Hash(){
	rep(i,1,n) hs[i] = (hs[i-1]*base+s[i]-'a')%mod;
	pd[0] = 1;
	rep(i,1,n) pd[i] = (pd[i-1]*base)%mod;
}
bool sta[26];
void getf(){
	int cur = 0;
	rep(i,1,n) rep(j,0,25) pre[i][j] = 0;
	rep(i,0,25) sta[i] = 0;
	rep(i,1,n){
		if(sta[s[i]-'a'] == 1) cur--;
		else cur++;
		sta[s[i]-'a'] ^= 1;
		P[i] = cur;	pre[i][cur] = 1;
	}
	cur = 0;
	rep(i,0,25) sta[i] = 0;
	per(i,1,n){
		if(sta[s[i]-'a'] == 1) cur--;
		else cur++;
		sta[s[i]-'a'] ^= 1;
		S[i] = cur;
	}
	rep(i,2,n){
		rep(j,0,25) pre[i][j] += pre[i-1][j];
	}
	rep(i,1,n) rep(j,1,25) pre[i][j] += pre[i][j-1];
}
void solve(){
	int ans = 0;
	rep(i,1,n){ // AB: 1~i
		int u = hs[i];
		for(int j = 1;i*j+1 <= n;++j){
			if(u == hs[i*j]) ans += pre[i-1][S[i*j+1]];//,printf("find! %lld %lld %lld\n",i,i*j+1,pre[i-1][S[i*j+1]]);
			u = (u*pd[i]+hs[i])%mod;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%s",s+1); n = strlen(s+1);
		Hash(); getf();
		solve();
	}
	return 0;
}

