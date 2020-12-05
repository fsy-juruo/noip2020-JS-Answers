#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+100;
typedef long long ll;
#define fr(i,a,b) for(int i = a;i <= b; ++i)
#define nfr(i,a,b) for(int i = a;i >= b; --i)

ll ans;
int n;
char s[N];
int t;
int pre[N],suf[N];
int cnt[26];

int z[N];
void z_func(){
//	memset(z,0,sizeof z);
	z[1] = n;
	int pos,R;
	pos = R = 0;
	fr(i,2,n){
		z[i] = i > R ? 0 : min(z[i-pos+1],R-i+1);
		while(i+z[i] <= n && s[z[i]+1] == s[i+z[i]])++z[i];
		if(i+z[i]-1 > R){
			R = i+z[i]-1; pos = i;
		}
	}
}

int sum[N][26];
void solve(){
	scanf("%s",s+1);
	n = strlen(s+1);
//	cerr << n << endl;
	z_func();
//	fr(i,2,n)cerr << z[i] << ' ';
//	cerr << endl;
	memset(cnt,0,sizeof cnt);
	fr(i,1,n){
		++cnt[s[i]-'a'];pre[i] = 0;
		fr(j,0,25)pre[i] += cnt[j]%2;
	}
	
//	memset(sum,0,sizeof sum);
	fr(i,1,n){
		fr(j,0,25)sum[i][j] = sum[i-1][j]+(pre[i] <= j);
	}
	
	memset(cnt,0,sizeof cnt);
	nfr(i,n,1){
		++cnt[s[i]-'a'];suf[i] = 0;
		fr(j,0,25)suf[i] += cnt[j]%2;
	//	cerr << i <<' ' << suf[i] << endl;
	}
	
	ans = 0;
	fr(i,2,n-1){
		for(int j = 1;j*i < n; ++j){
			if(z[(j-1)*i+1] < i)break;
			ans += sum[i-1][suf[j*i+1]];
		}
//		cerr << i <<' ' << ans << endl;
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--)solve();
	return 0;
}
