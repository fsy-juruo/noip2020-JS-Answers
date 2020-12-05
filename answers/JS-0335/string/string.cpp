#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#define MaxN 100010

int n, f[50][MaxN], ans;
std::string s;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	//std::ios::sync_with_stdio(false);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s;
		//std::cerr << s[1] << std::endl;
		//std::cerr << s.size() << std::endl;
		//return 0;
		memset(f, 0, sizeof f);
		f[s[0] - 'a'][0] = 1; ans = 0;
		for (int i = 1; i < s.size(); ++i) 
			for (int j = 0; j < 26; ++j)
				if (s[i] != j + 'a') f[j][i] = f[j][i - 1];
				else f[j][i] = f[j][i - 1] + 1;
		for (int lenc = 1; lenc < s.size() - 1; ++lenc) {
			int left = s.size() - lenc, cntC = 0;
			std::string C = s.substr(s.size() - lenc, lenc);
			//printf("%d\n", left);
			for (int j = 0; j < 26; ++j)
				if ((f[j][s.size() - 1] - f[j][s.size() - lenc - 1]) & 1) ++cntC;
			for (int lenab = 2; lenab <= left; ++lenab) {
				if (left % lenab != 0) continue;
				bool flag = 1;
				std::string ab = s.substr(0, lenab);
				//std::cout << "-------" << ab << '\n';
				for (int _i = 2; _i <= left / lenab; ++_i) {
					int begin = (_i - 1) * lenab;
					std::string sub = s.substr(begin, lenab);
					if (sub != ab) {flag = 0; break;}
				}	
				if (!flag) continue;
				//printf("------------------------%s %s %d\n", ab.c_str(), C.c_str(), lenab);
				for (int j = 0; j < lenab - 1; ++j) { //a:0 - j 
					//printf("j : %d\n", j);
					int cnta = 0;
					for (int k = 0; k < 26; ++k) {
						if (f[k][j] & 1) ++cnta;
					}
					//if (j == 2 && lenab == 4) std::cout << s.substr(0, j + 1) << ' ' << C << ' ' << cnta << ' ' << cntC << std::endl;
					//std::cout << j << ' ' << cnta << std::endl;
					if (cnta <= cntC) ++ans; //std::cout << lenab << ' ' << lenc << std::endl;
				}
			}
		}
		printf("%d\n", ans);
	}	  
	return 0;
}
