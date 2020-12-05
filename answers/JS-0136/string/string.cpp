#include <bits/stdc++.h>
#include <windows.h>
#define LL long long
#define ULL unsigned LL
#define Fre(name) freopen(#name".in", "r", stdin),\
				  freopen(#name".out", "w", stdout)
using namespace std;

const int N = 5e7 + 55;

int S[2][N], c[26], c2[26];
string str;

map < int, int > rptn;

string sub(string s, int i) {
	string result = "";
	for (int j = 0; j <= i; ++j) {
		result += s[j];
	}
	return result;
}

void init () {
	int total;
	memset(c, 0, sizeof(c));
	total = 1;
	++c[str[0] - 'a'];
	S[0][0] = 1;
	for (int i = 1, len = str.size() - 1; i <= len; ++i) {
		++c[str[i] - 'a'];
		if ((c[str[i] - 'a'] & 1) == 1)
			total = total + 1;
		else total = total - 1;
		S[0][i] = total;
	//	Sleep(1000);
	}

//	for (int i = 0; i < 26; ++i) {
//		cout << char(i + 'a') << " " << c[i] << endl;
//	}
	
	
	
}

void init2() {
	memset(c2, 0, sizeof(c2));
	int total = 1;
	++c2[str[str.size() - 1] - 'a'];
	S[1][str.size() - 1] = 1;
	for (int i = str.size() - 2; i >= 0; --i) {
		++c2[str[i] - 'a'];
		if ((c2[str[i] - 'a'] & 1) == 1)
			total = total + 1;
		else total = total - 1;
		S[1][i] = total;
	}
}

void init3() {
	
	int n = str.size();
	for (int i = 0; i <= n / 2 + 1; ++i) {
		int j = i + 1, p = i + 1;
		rptn[i] = 1;
		while(j <= n) {
			for (int k = 0; k < p; ++k)
				if (str[k] != str[k + j])
					goto Break;
			++rptn[i];
			j += p;
		}
		Break:;
	}
}

int DivNum(int n) {
	int t = sqrt(n + 1), result = 0;
	for (int i = 1; i <= t; ++i) {
		if (!(n % i)) {
			if (i != n / i) result += 2;
			else result += 1;
		}
	}
	return result;
}

int main() {
	Fre(string);
	int T;
	cin >> T;
	while(T --) {
		memset(S, 0, sizeof(S));
		rptn.clear();
		int Ans = 0;
		cin >> str;
		init();
		init2();
		init3();
		for (map < int, int > :: iterator it = rptn.begin(); it != rptn.end(); ++it) {
		//	cout << (it -> first) << " " << (it -> second) << endl;
		}
		for (int i = str.size() - 1; i >= 2; --i) { //C 
			for (int j = 0; j <= i - 2; ++j) { // A,B·Ö½çÏß 
				if (S[0][j] <= S[1][i]) {
					bool p = true;
					for (map < int, int > :: iterator it = rptn.begin(); it != rptn.end(); ++it) {
						if ((it -> second) > 1 && ((it -> first + 1) * (it -> second)) == i && (it -> first) > j) {
							Ans += DivNum(i / (it -> second));
						//	cout << it -> second << " " << it -> first << " " << i << " " << j << endl;
							p = false;
						}
					}
					Ans += p;
				//	cout << "["<< j << "] : " << S[0][j] << " | [" << i << "] : " << S[1][i] << endl;
				}
				
			}
		}
		cout << Ans << endl;
	}
	return 0;
}

