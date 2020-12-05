#include <bits/stdc++.h>
using namespace std;

long long p1 = 927434891;
long long p2 = 817829437;
long long p3 = 793468211;

long long qz1[1100010], qz2[1100010]/*, qz3[3000010]*/;
int num[1100010];
int pr[1100010][27], cnt[27], sf[1100010][27], PR[1100010][27];

long long qpow(long long a, long long b, long long p){
	long long ans = 1;
	while (b){
		if (b & 1){
			ans *= a;
			ans %= p;
		}
		a *= a;
		a %= p;
		b >>= 1;
	}
	return ans;
}

long long get_HASH1(int l, int r){
	long long qvq;
	if (l == 0) qvq = qz1[r];
	else qvq = qz1[r] + p1 - qz1[l - 1];
	qvq *= qpow(qpow(27, l, p1), p1 - 2, p1);
	return qvq % p1;
}

long long get_HASH2(int l, int r){
	long long qvq;
	if (l == 0) qvq = qz2[r];
	else qvq = qz2[r] + p2 - qz2[l - 1];
	qvq *= qpow(qpow(27, l, p2), p2 - 2, p2);
	return qvq % p2;
}

long long count(long long x){
	int num = 0;
	while (x){
		if (x & 1) num++;
		x >>= 1;
	}
	return 0;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		qz1[0] = s[0] - 'a';
		qz2[0] = s[0] - 'a';
//		qz3[0] = s[0] - 'a';
		long long now1 = 27, now2 = 27/*, now3 = 27*/;
		memset(pr, 0, sizeof(pr));
		memset(sf, 0, sizeof(sf));
		memset(PR, 0, sizeof(PR));
		for (int i = 1; i < s.size(); i++){
			qz1[i] = (qz1[i - 1] + (s[i] - 'a') * now1) % p1;
			qz2[i] = (qz2[i - 1] + (s[i] - 'a') * now2) % p2;
//			qz3[i] = (qz3[i - 1] + (s[i] - 'a') * now3) % p3;
			now1 *= 27;
			now1 %= p1;
			now2 *= 27;
			now2 %= p2;
//			now3 *= 27;
//			now3 %= p3;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.size() - 1; i++){
			cnt[s[i] - 'a']++;
			int num = 0;
			for (int j = 0; j < 26; j++){
				if (cnt[j] % 2){
					pr[i][j]++;
					num++;
				}
			}
			for (int j = 0; j < 26; j++){
				if (j == num) PR[i][j] = 1;
				if (i > 0) PR[i][j] += PR[i - 1][j] - PR[i - 1][j - 1];
				else PR[i][j] += PR[i - 1][j];
				if (j > 0) PR[i][j] += PR[i][j - 1];
			}
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = s.size() - 1; i >= 2; i--){
			cnt[s[i] - 'a']++;
			for (int j = 0; j < 26; j++){
				if (cnt[j] % 2) sf[i][j]++;
			}
		}
		long long ans = 0;
		for (int i = 1; i < s.size() - 1; i++){
			long long hs1 = get_HASH1(0, i);
			long long hs2 = get_HASH2(0, i);
			int awa = 1;
			for (int j = i + 1; j < s.size() - 1; j += i + 1){
				if (!(j + i < s.size() - 1)) break;
				long long nw_hs1 = get_HASH1(j, j + i);
				if (nw_hs1 != hs1) break;
				long long nw_hs2 = get_HASH2(j, j + i);
				if (nw_hs2 != hs2) break;
				awa++;
			}
			int B = 0;
			int C = 0;
			for (int m = 0; m < 26; m++){
				if (sf[awa * (i + 1)][m]) B++;
				if (sf[awa * (i + 1)][m] ^ pr[i][m]) C++;
			}
			ans += (long long)PR[i - 1][B] * ((awa + 1) / 2) + (long long)PR[i - 1][C] * (awa / 2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
