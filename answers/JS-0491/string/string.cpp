#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, a, b) for(int (i) = (a); (i) <= (b); i++)

int read() {
	char ch = getchar();
	int s = 1, w = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') s = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {w = w * 10 + ch - '0'; ch = getchar();}
	return s * w;
}

int ans, slen;
string s;
map<string, bool> m;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int q = read();
	while(q--) {
		ans = 0;
		cin >> s;
		slen = s.length();
		for(int i = slen - 1; i > 0; i--) {
			int cnta[maxn], cntc[maxn], cnt1 = 0, cnt2 = 0;
			memset(cnta, 0, sizeof(cnta));
			memset(cntc, 0, sizeof(cntc));
			string tmp1, tmp2;
			for(int j = i; j < slen; j++) {// choose C
				tmp1 = tmp1 + s[j];
				cntc[s[j]]++;
			}
			//cout << tmp1 << " ";
			for(int j = 0; j < i; j++) tmp2 = tmp2 + s[j];// choose A+B
			int lentmp = tmp2.length();
			if(lentmp <= 1) continue;
			for(int j = 0; j < lentmp - 1; j++) {
				string fro, bac;
				for(int k = 0; k <=j; k++) {// choose A
					fro = fro + tmp2[k];
					cnta[tmp2[k]]++;
				}
				//cout << fro << " ";
				for(int k = 'a'; k <= 'z'; k++) {
					if(cnta[k] % 2 == 1) cnt1++;
					if(cntc[k] % 2 == 1) cnt2++;
				}
				for(int k = j + 1; k < lentmp; k++) bac = bac + tmp2[k];// choose B
				//cout << bac << endl;
				if(cnt1 > cnt2) continue;
				if(fro.compare(bac) == 0) {
					if(fro.length() > 1) ans += fro.length() - 1;
				}
				if(tmp1.compare(fro) == 0 || tmp1.compare(bac) == 0) continue;
				bool ch = true;
				if(fro.length() > bac.length()) {
					for(int k = 0; k < fro.length(); k += bac.length()) {
						string tmp = fro.substr(k, bac.length());
						if(tmp != bac) ch = false;
					}
				}
				else {
					for(int k = 0; k < bac.length(); k += fro.length()) {
						string tmp = bac.substr(k, fro.length());
						if(tmp != fro) ch = false;
					}
				}
				if(ch) continue;
				ans++;
			}
 		}
 		cout << ans << endl;
	}
}
