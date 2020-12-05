#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define rep(i,n) for (int i=0;i<(n);++i)
#define REP(i,n) for (int i=1;i<=(n);++i)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
int T;
int n;
char s[1100000];
int fail[1100000];
inline void KMP(){
	fail[1]=0;
	int j=0;
	for (int i=2;i<=n;++i){
		while(j&&s[1+j]!=s[i]) j=fail[j];
		if (s[1+j]==s[i]) ++j;
		fail[i]=j;
	}
}

int cnt[1100000][27];// <130MB so far
int cntOdd[26];
inline void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if (n<3){
		printf("0\n");return;
	}
	KMP();
	rep(ch,26) cntOdd[ch]=0;
	for (int i=1,sum=0;i<=n;++i){
		cntOdd[s[i]-'a']++;
		if (cntOdd[s[i]-'a']&1) ++sum;
		else --sum;
		rep(ch,27) cnt[i][ch]=cnt[i-1][ch];
		for (int ch=sum;ch<=26;++ch) cnt[i][ch]++;
	}
	ll ans=0;
	rep(ch,26) cntOdd[ch]=0;
	for (int i=n-1,sum=0;i>=2;--i){// string C: [i+1,n]
		cntOdd[s[i+1]-'a']++;
		if (cntOdd[s[i+1]-'a']&1) ++sum;
		else --sum;
		int jie=i-fail[i];
		if (i%jie){// no xun-huan-jie
			ans+=cnt[i-1][sum];
		}
		else{// minimum xun-huan-jie length: jie
			int num=i/jie;
			for (int j=1;j*j<=num;++j) if (!(num%j)){// how many multiple
				if (j*j==num){// count once
					ans+=cnt[jie*j-1][sum];
				}
				else{
					ans+=cnt[jie*j-1][sum];
					ans+=cnt[jie*(num/j)-1][sum];
				}
			}
		}
	}
	printf("%lld\n",ans);
}


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	RI(T);
	while(T--) solve();
	return 0;
}
