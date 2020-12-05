#include <bits/stdc++.h>

using namespace std;

int main(){
	//freopen(".in", "r", stdin);freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int q = s.size();
		cout << rand() % 10 * q << endl;
	}
	return 0;
}

