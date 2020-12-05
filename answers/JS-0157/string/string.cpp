#include<bits/stdc++.h>
using namespace std;
int T, ans;
string s;
int a[27];
int b[27];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> T;
	while(T--){
	ans = 0;
	cin >> s;
	int len = s.size(), fa = 0, fb = 0;
	memset(a, 0, sizeof(a));
	for(int i = 0; i < len - 2; ++i){
		++a[s[i]- 'a'];
		if(a[s[i]- 'a'] % 2 == 1) ++ fa;
		else --fa;
		memset(b, 0, sizeof(b));
		for(int c = 2; c < len; ++c){
			++b[s[c] - 'a'];
			if(b[s[c] - 'a'] % 2 == 1) ++fb;
			else --fb;
		}	
		for(int j = i + 1; j < len - 1; ++j){
			--b[s[j] - 'a'];
			if(b[s[j] - 'a'] % 2 == 0) --fb;
			else ++fb;
			if(fb >= fa)++ans;
		}
	}
	cout << ans << endl;
	}
	fclose(stdin);fclose(stdout);
}
//	for(int k = 0; k <= i; ++k){
//				cout << s[k];
//			}cout << " ";
//			for(int k = i + 1; k <= j; ++k){
//				cout << s[k];
//			}cout << " ";
//			for(int k = j + 1; k < len; ++k){
//				cout << s[k];
//			}cout << endl;
