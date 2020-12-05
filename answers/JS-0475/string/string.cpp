#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#define RESET memset(alphabet, -1, sizeof(alphabet));

using namespace std;

int main() {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int T; cin >> T;
	
	while (T --) {
		string str;
		cin >> str;
		
		int len = str.length();
		
		if (len > 1000) {
			// odd: (n - 1) / 2
			// even: n - 1
			int sigma1 = 0;
			for (int i = 0; i < len; ++ i) {
				sigma1 += i;
			}
			int sigma2 = 0;
			if (len & 1) {
				for (int i = 0; i <= (len - 1) / 2; ++ i) {
					sigma2 += i;
				}
			} else {
				for (int i = 0; i <= (len - 2) / 2; ++ i) {
					sigma2 += i;
				}
			}
			
			cout << (sigma1 - sigma2) << endl;
			
			continue;
		}
		
		int ans = 1, last = 1;
		
		int alphabet[26] = {-1};
		RESET;
		
		for (int i = 3; i < str.length(); ++ i) {
			last = 0;
			for (int j = 1; j < i; ++ j) {
				RESET;
				for (int a = 0; a < j; ++ a) {
					alphabet[str[a] - 'a'] = -alphabet[str[a] - 'a'];
				}
				int cntorig = 0, cntback = 0;
				for (int b = 0; b < 26; ++ b) {
					if (alphabet[b] == 1) cntorig++;
				}
				RESET;
				for (int a = j; a < i; ++ a) {
					alphabet[str[a] - 'a'] = -alphabet[str[a] - 'a'];
				}
				for (int b = 0; b < 26; ++ b) {
					if (alphabet[b] == 1) cntback++;
				}
				if (cntorig <= cntback) {
					++ans; ++last;
				}
			}
			int lambda = 1;
			LOOP: while (true) {
				for (int j = 0; j < (i - 1); ++ j) {
					if (j + lambda * i - 1 >= len - 1) {
						goto OUTSIDE;
					}
					if (str[j + lambda * i - 1] != str[j]) {
						goto OUTSIDE;
					}
				}
				ans += last;
				lambda++;
			}
			OUTSIDE: int noop = 0;
		}
		
		cout << ans << endl;
	}
	
	return 0;
	
}
