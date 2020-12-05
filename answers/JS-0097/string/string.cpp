#include <bits/stdc++.h>

using namespace std;

int t;
string s;
int h[100];

long long solve_pf(int k) {
	long long ans = 0;
	for(int i=2;i<=k;i+=2) {
		if((k - i) % 2 == 0 && i % 2 == 1) {
			continue;
		}
		ans += (i - 1);
	}
	return ans;
}
int check(string s ,string t) {
	int pos = s.find(t , 0) , ans = 0 , mt = 0;
	while(pos != string::npos) {
		++ ans;
		if(pos != mt) {
			break;
		}	
		mt += t.size();
		pos = s.find(t , pos + 1);
	}
	return ans;
}
int solve(string s) {
	long long ans = 0;
	string t = "";
	for(int i=0; i<s.size(); ++i) {
		t += s[i];
		int ck = check(s , t);
		for(int j=1;j<=ck;++j)
		ans += j * (t.size() - 1);
		cerr << ck << ' ' << i << ' ' << ans << '\n';
	}
	return ans;
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//kkkkkkkkkkkkkkkkkkkk

	cin >> t >> s;
	t --;
	memset(h,0,sizeof(h));
	for(int i='a'; i<='z'; ++i) {
		h[i] = 0;
	}
	for(int i=0; i<s.size(); ++i) {
		++ h[s[i]];
	}
	int maxn = 0;
	for(int i='a'; i<='z'; ++i) {
		maxn = max(maxn , h[i]);
	}
	if(maxn == s.size()) {
		cout << solve_pf(s.size());
		while(t --) {
			cin >> s;
			cout << solve_pf(s.size());
		}
		return 0;
	} else {
		cout << solve(s);
		while(t --) {
			cin >> s;
			cout << solve(s);
		}
	}
	return 0;
}

