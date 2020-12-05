#include<bits/stdc++.h>
using namespace std;
#define re register
#define Re register
#define ll long long
#define ull unsigned long long
#define MAXN 1100005
int t,len,cnt[MAXN][30],odd[MAXN];
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
//	cout << sizeof cnt / 1024 / 1024 << endl;
	cin >> t;
	while(t--){
		int ans = 0;
		cin >> s;
		s = " " + s;
		len = s.length() - 1;
		memset(cnt,0,sizeof cnt);
		memset(odd,0,sizeof odd);
		for(re int i = len;i >= 1;i--){
			cnt[i][s[i] - 'a' + 1]++;
			for(re int j = 1;j <= 26;j++){
				cnt[i][j] += cnt[i + 1][j];
				if(cnt[i][j] & 1)odd[i]++;
			}
			//cout << odd[i] << ' ';
		}
		for(re int i = 2;i <= len - 1;i++){
			string si = s.substr(1,i);
			int c1 = odd[i + 1],c2 = 0,t1 = 1,t2 = 0;
			for(re int j = i + 1;j <= len - 1;j += i){
				if(s.substr(j,i) != si || j + i - 1 >= len)break;
				else if((j / i) % 2 == 1){
					c2 = odd[j + i];
					t2++;
				}
				else t1++;
			}
			int tmp[30],cont = 0;
			memset(tmp,0,sizeof tmp);
			for(re int j = 1;j <= i - 1;j++){
				tmp[s[j] - 'a' + 1]++;
				if(tmp[s[j] - 'a' + 1] & 1)cont++;
				else cont--;
				if(cont <= c1)ans += t1;
				if(cont <= c2)ans += t2;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
