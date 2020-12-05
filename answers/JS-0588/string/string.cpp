#include<bits/stdc++.h>
using namespace std;
int cnt[1005][200];
int T,n,tmp,k;
string s;
long long ans;
int count(int l,int r) {
	register int ret = 0;
	for(register int i = 'a'; i <= 'z'; ++i)
		if((cnt[r][i] - cnt[l - 1][i]) & 1)
			++ret;
	return ret;
}
bool check(int lt,int t) {
	register int l = lt / t;
	for(register int i = l,j = 0; i < lt; ++i,++j) {
		if(s[i] != s[j])
			return false;
		if(j == l - 1)
			j = -1;
	}
	return true;
}
int main() {
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> s;
		n = s.size();
		ans = 0;
		if(n > 1000) {
			for(int i = 1; i <= n - 2; ++i) {
				register int k = n - i,j = 2;
				if(i & 1) {
					if(k <= i + 1)
						ans += k - 1;
					else ans += i + (k - i) / 2;
					for(; j * j < k; ++j)
						if(!(k % j)) {
							if(k / j <= i + 1)
								ans += k / j - 1;
							else ans += i + (k / j - i) / 2;
							if(j <= i + 1)
								ans += j - 1;
							else ans += i + (j - i) / 2;
						}
					if(j * j == k)
						if(j <= i + 1)
							ans += j - 1;
						else ans += i + (j - i) / 2;

				} else {
					ans += (k - 1) / 2;
					for(; j * j < k; ++j)
						if(!(k % j))
							ans += (j - 1) / 2 + (k / j - 1) / 2;
					if(j * j == k)
						ans += (j - 1) / 2;
				}
			}
			cout << ans << endl;
			continue;
		}
		for(int i = 'a'; i <= 'z'; ++i)
			cnt[0][i] = 0;
		++cnt[0][int(s[0])];
		for(int i = 1; i < n; ++i) {
			for(int j = 'a'; j <= 'z'; ++j)
				cnt[i][j] = cnt[i - 1][j];
			++cnt[i][int(s[i])];
		}
		for(int i = n - 1; i > 1; --i) {
			tmp = count(i,n - 1);
			for(register int j = 1; j * j <= i; ++j)
				if(!(i % j)) {
					if(check(i,j))
						for(int k = 1; k < i / j; ++k)
							if(count(0,k - 1) <= tmp)
								++ans;
					if(j != 1 && j != i / j && check(i,i / j))
						for(int k = 1; k < j; ++k)
							if(count(0,k - 1) <= tmp)
								++ans;
				}

		}
		cout << ans << endl;
	}
	return 0;
}
