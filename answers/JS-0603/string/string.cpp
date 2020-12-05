#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
char s[2000200];
int z[2000200];
int cnt;
int preres[2000200], sufres[2000200];
int suf[2000020];
int bit[30];
void update(int pos, int val){
	while(pos <= 26){
		bit[pos] += val;
		pos += (pos & -pos);
	}
}
int query(int pos){
	int ans = 0;
	while(pos > 0){
		ans += bit[pos];
		pos -= (pos & -pos);
	}
	return ans;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &T);
	gets(s);
	while(T--){
		gets(s);
		n = strlen(s);
//		puts(s);
		memset(z, 0, sizeof(z));
		memset(bit, 0, sizeof(bit));
		int l = 0, r = 0;
		for(int i = 1; i < n; i++){
			if(r >= i) z[i] = min(z[i - l], r - i + 1);
			while(i + z[i] < n && s[i + z[i]] == s[z[i]]){
				z[i]++;
			}
			if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
		}
//rep(i, n) cout << z[i] << " ";
//cout << endl;
		int res;
		cnt = 0; res = 0;
		suf[n] = 0;
		for(int r = 0; r < n; r++){
			cnt ^= 1 << (s[r] - 'a');
			if(cnt & (1 << (s[r] - 'a'))) res++;
			else res--;
			preres[r] = res;
		}
		cnt = 0; res = 0;
		for(int r = n-1; r >= 0; r--){
			cnt ^= 1 << (s[r] - 'a');
			suf[r] = cnt;
			if(cnt & (1 << (s[r] - 'a'))) res++;
			else res--;
			sufres[r] = res;
		}
		cnt = 0;
		ll ans = 0;
		for(int r = 0; r < n-1; r++){
			cnt ^= 1 << (s[r] - 'a');
			int nowpos = r + 1;
			while(1){
				if(z[nowpos] >= nowpos) nowpos += nowpos;
				else {
					nowpos += z[nowpos];
					break;
				}
			}
			nowpos = (nowpos / (r + 1)) * (r + 1);
			if(nowpos == n) nowpos -= (r + 1);
			int nowmx = nowpos / (r + 1);
			int target = suf[nowpos];
//cout << r << ": " << nowpos << " " << nowmx << endl;
			ans += 1LL * ((nowmx - 1) / 2 + 1) * query(__builtin_popcount(target) + 1);
//cout << ans << endl;
			if(nowmx != 1){
				target ^= cnt;
				ans += 1LL * (nowmx / 2) * query(__builtin_popcount(target) + 1);
//cout << ans << endl;
			}
			update(preres[r] + 1, 1);
		}
		cout << ans << endl;
	}
	return 0;
}
