#include<bits/stdc++.h>
using namespace std;
#define hashic (s[begc] - 'a' + 1)
#define hashn 26
int n, ans; string s;
int main() {
	freopen("string.in",  "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	while(n--) {
		ans = 0;
		cin >> s;
		int pc[256], cntc = 0; memset(pc, 0, sizeof(pc));
		//枚举C长度 
		for(int begc = s.size() - 1; begc >= 2; begc--) {
			pc[s[begc]]++;
			if(pc[s[begc]] & 1) cntc++;
			else cntc--;
			//cout << cntc << endl;
			//panduanjishucigeshu
			int cnt[256], avil[1010];memset(cnt, 0, sizeof(cnt)), memset(avil, 0, sizeof(avil));
			for(int i = 0; i < begc; i++) {
				avil[i] = avil[i - 1];
				cnt[s[i]]++;
				if(cnt[s[i]] & 1) cnt[0]++;
				else cnt[0]--;
				//cout << cnt[0] << endl;
				if(i && cnt[0] <= cntc) avil[i] += 1;
			}
			//for(int i = 0; i < begc; i++) printf("%d ", avil[i]); putchar('\n');
			//枚举循环节长度 
			for(int lenl = 2; lenl <= begc; lenl++) {
				//判断是否循环 
				if(begc % lenl == 0) {
					for(int i = 0; i < lenl; i++){
						char c = s[i];
						for(int j = 1; j < begc / lenl; j++)
							if(s[i] != s[i + j * lenl]) goto NextL;
					}
					//是循环
					ans += avil[lenl - 1];
					//cout << lenl << avil[lenl - 1] << endl;
					
				}
				NextL:;
			}
		}
		printf("%d\n", ans);
	}
}
