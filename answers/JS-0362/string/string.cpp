#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {if (ch=='-') neg=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*neg;
}
const int MAXN=150000;
int n;
char s[MAXN+5];
int num[MAXN+5],num2[MAXN+5];
int tot[MAXN+5],tot2[MAXN+5];
vector<int> g[MAXN+5];
vector<int> fac[MAXN+5];
vector<int> ok[MAXN+5];
inline int Task1() {
	int cnt=0,ans=0ll;
	for (int i=n;i>=3;--i) {
		if ((n-i+1)%2==0) cnt=0;
		else cnt=1;
		for (int j=0;j<fac[i-1].size();++j) {
			int q=fac[i-1][j];
			if (cnt==1) ans+=(q-1);
			else {
				if (q%2==1) ans+=(q/2);
				else ans+=((q-1)/2);
			}
		}
	}
	printf("%lld\n",ans);
}
inline void Task2() {
	int ans=0ll;
	for (int i=1;i<=n;++i) for (int j=n;j>i+1;--j) if (tot[i]<=tot2[j]) g[j].pb(i);
	for (int i=2;i<=n;++i) {
		for (int j=0;j<fac[i].size();++j) {
			int v=fac[i][j];
			int flag=1;
			for (int k=v+1;k<=i;++k) {
				if (s[k]!=s[k-v]) {
					flag=0;
					break;
				}
			}
			if (flag) ok[i].pb(v);
		}
	}
	for (int i=n;i>=3;--i) {
		for (int j=0;j<g[i].size();++j) {
			int v=g[i][j];
			for (int k=0;k<ok[i-1].size();++k) {
				int q=ok[i-1][k];
				if (q>v) ++ans;
			}
		}
	} 
	printf("%lld\n",ans);
}
inline void Init() {
	for (int i=1;i<=n;++i) {
		for (int j=2;j<=sqrt(i);++j) {
			if (i%j==0) {
				fac[i].pb(j);
				if (i/j!=j) fac[i].pb(i/j);
			}
		}
		fac[i].pb(i);
	}
	for (int i=1;i<=n;++i) {
		int ii=s[i]-'a'+1;
		if (num[ii]%2==0) tot[i]=tot[i-1]+1;
		else tot[i]=tot[i-1]-1;
		++num[ii];
	}
	for (int i=n;i>=1;--i) {
		int ii=s[i]-'a'+1;
		if (num2[ii]%2==0) tot2[i]=tot2[i+1]+1;
		else tot2[i]=tot2[i+1]-1;
		++num2[ii];
	}
}
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		Init();
		int flag=1;char c=s[1];
		for (int i=2;i<=n;++i) {
			if (s[i]!=c) {
				flag=0;
				break;
			}
		}
		if (flag==1) Task1();
		else Task2();
		for (int i=1;i<=n;++i) {
			int ii=s[i]-'a'+1;
			num[ii]=num2[ii]=0; 
			tot[i]=tot2[i]=0;
			fac[i].clear(),g[i].clear(),ok[i].clear();
		}
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
