#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define rep(i,j,k) for(int (i) = (j);(i) <= (k);(i)++)
#define rap(i,j,k) for(int (i) = (j);(i) < (k) ;(i)++)
#define per(i,j,k) for(int (i) = (j);(i) >= (k);(i)--)
#define sit set<int>::iterator
#define mit map<int,int>::iterator
#define itrm(it,g) for(it = g.begin(); it != g.end(); it++)
#define mpr make_pair
#define pii pair<int,int>
int T,n,cnt;
int mod1 = 1000000009, mod2 = 1000000021, base = 157;
char s[1049000];
int hsh1[1049000],hsh2[1049000],pw1[1049000],pw2[1049000],pre[1049000],suf[1049000],cnt1[33],cnt2[33],tmp[33];
int get_hash_1(int l,int r) {
	return (hsh1[r] - hsh1[l - 1] * (ll)pw1[r - l + 1] % mod1 + mod1) % mod1;
}
int get_hash_2(int l,int r) {
	return (hsh2[r] - hsh2[l - 1] * (ll)pw2[r - l + 1] % mod2 + mod2) % mod2;
}
void solve(){
	ll ans = 0;
	scanf("%s",s+1);
	n = strlen(s + 1);
	rep(i,0,26) cnt1[i] = 0;
	rep(i,1,26) tmp[i] = 0;
	rep(i,1,n) {
		int p = s[i] - 'a' + 1;
		if(tmp[p] & 1) pre[i] = pre[i - 1] - 1;
		else pre[i] = pre[i - 1] + 1;
		tmp[p]++;
	}
	rep(i,1,26) tmp[i] = 0;
	per(i,n,1) {
		int p = s[i] - 'a' + 1;
		if(tmp[p] & 1) suf[i] = suf[i + 1] - 1;
		else suf[i] = suf[i + 1] + 1;
		tmp[p]++;
	}
	rep(i,1,n) {
		hsh1[i] = ((ll)hsh1[i - 1] * base % mod1 + s[i]) % mod1;
		hsh2[i] = ((ll)hsh2[i - 1] * base % mod2 + s[i]) % mod2;
	}
	//rep(i,1,n) rep(j,i,n) {
	//	printf("%d %d %d\n",i,j,get_hash_1(i,j));
	//}
	//printf("%d %d\n",get_hash_1(1,8),get_hash_1(10,17));
	rep(len,2,n-1) {
		rep(i,0,26) cnt2[i] = 0;
		int j = 1;cnt2[suf[len + 1]]++;
		cnt1[pre[len - 1]]++;
		while(1) {
			if((j + 1) * len >= n) break;
			int s = j * len + 1, t = (j + 1) * len;
			if(get_hash_1(s,t) == get_hash_1(s - len, s - 1) && get_hash_2(s,t) == get_hash_2(s - len, s - 1)) {j++;cnt2[suf[j * len + 1]]++;}
			else break;
		}
		int sum = 0;
		rep(i,0,26) {
			sum += cnt1[i];
			ans += (ll)cnt2[i] * sum;
		}
		//printf("%d %d\n",len,j);
		//ans += (len - 1) * (ll)j;
	}
	printf("%lld\n",ans);
}
int main(){
	pw1[0] = pw2[0] = 1;
	rep(i,1,1048577) pw1[i] = (ll)pw1[i - 1] * base % mod1, pw2[i] = (ll)pw2[i - 1] * base % mod2;
	//rep(i,0,5) printf("%d %d\n",pw1[i],pw2[i]);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	/*scanf("%d",&n);
	rep(i,1,n-1) {
		rep(j,1,i) if(i % j == 0) cnt += i / j - 1;
	}
	printf("%d\n",cnt);
	cnt = 0;
	rep(len,1,n) {
		int j = (n - 1) / len;
		//ans += (len - 1) * j;
		cnt += j;
	}
	printf("%d\n",cnt);*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}

