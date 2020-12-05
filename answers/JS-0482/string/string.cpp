#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> P;



int read() {
	int x=0,f=1,c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

char tmp[1111111];
int n;

namespace task48 {
	const int maxn=1005;
	const ll mod1=1000000007;
	const ll mod2=19260817;
	const int p=31;
	ll hsh1[maxn],hsh2[maxn];
	ll fact1[maxn],fact2[maxn];
	int cnt[maxn][26];
	int c[maxn];
	ll ans;
	void init(){
		fact1[0]=fact2[0]=1ll;
		for(int i=1; i<maxn; ++i)fact1[i]=(fact1[i-1]*p)%mod1;
		for(int i=1; i<maxn; ++i)fact2[i]=(fact2[i-1]*p)%mod2;
	}
	void solve() {
		ans=0;
		hsh1[0]=hsh2[0]=0;
		for(int i=0; i<=n; ++i)for(int j=0; j<26; ++j)cnt[i][j]=0;
		cnt[n][tmp[n]-'a']=1;
		c[n]=1;
		for(int i=n-1; i; --i) {
			for(int j=0; j<26; ++j)cnt[i][j]=cnt[i+1][j];
			cnt[i][tmp[i]-'a']++;
			c[i]=0;
			for(int j=0; j<26; ++j)if(cnt[i][j]&1)c[i]++;
		}
		for(int i=1; i<=n; ++i) {
			hsh1[i]=(hsh1[i-1]*p+tmp[i]-'a')%mod1;
			hsh2[i]=(hsh2[i-1]*p+tmp[i]-'a')%mod2;
		}
		for(int la=1; la<=n-2; ++la) {
			int num[26];
			fill(num,num+26,0);
			for(int i=1; i<=la; ++i)num[tmp[i]-'a']++;
			int ca=0;
			for(int i=0; i<26; ++i)if(num[i]&1)ca++;
			for(int lb=1; lb+la<=n-1; ++lb) {
				int totl=la+lb;
				P ab=make_pair(hsh1[la+lb],hsh2[la+lb]);
				if(ca<=c[la+lb+1])ans++;
				for(int i=totl*2; i<n; i+=totl) {
					ll h1=(hsh1[i]-hsh1[i-totl]*fact1[totl]%mod1+mod1)%mod1;
					ll h2=(hsh2[i]-hsh2[i-totl]*fact2[totl]%mod2+mod2)%mod2;
					if(h1==ab.first&&h2==ab.second) {
						if(ca<=c[i+1])ans++;
					} else break;
				}
			}
		}
		printf("%lld\n",ans);
	}
}

namespace task56{
	ll ans;
	void solve(){
		ans=0;
		for(int lc=1;lc<=n-2;lc++){
			int lft=n-lc;
			vector<int> v;
			for(int i=1;i*i<=lft;++i){
				if(lft%i==0){
					if(i*i==lft)v.push_back(i);
					else {
						v.push_back(i);
						v.push_back(lft/i);
					}
				}
			}
			if(lc&1){
				for(int i=0;i<v.size();++i){
					ans+=v[i]-1;
				}
			}
			else{
				for(int i=0;i<v.size();++i){
					ans+=(v[i]-1)/2;
				}
			}
		}
		printf("%lld\n",ans);
	}
}


void MAIN() {
	scanf("%s",tmp+1);
	n=strlen(tmp+1);
	if(n<=1000)task48::solve();
	else task56::solve();
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	task48::init();
	int T=read();
	while(T--)MAIN();
	return 0;
}

