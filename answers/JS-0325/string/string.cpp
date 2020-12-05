#include<bits/stdc++.h>
using namespace std;

template<class T> inline void readNum(T& num) {
	num = 0; register char c = getchar(); bool neg = false;
	while (!isdigit(c)) { if (c == '-') neg = true; c = getchar(); }
	while (isdigit(c)) { num = num * 10 + c - '0'; c = getchar(); }
	if (neg) num = ~num + 1;
}

#define ll long long
#define ull unsigned long long
#define CLEAR_ARRAY(x) memset(x, 0, sizeof(x))

const ll N_MAX = (1 << 20) + 5;

int n;
ll len;
bool charTypes[26];
char str[N_MAX];
ll jmp[N_MAX];
ll oddCntPre[N_MAX];
ll oddCntSuf[N_MAX];
map<pair<ll, ll>, ull> mp;

bool input() {
	scanf("%s", &str);
	len = strlen(str);
	CLEAR_ARRAY(charTypes);
	int typeCnt = 0;
	for (int i = 0; i < len; ++i) {
		if (!charTypes[str[i] - 'a']) {
			charTypes[str[i] - 'a'] = true;
			++typeCnt;
		}
	}
	if (typeCnt == 1)
		return true;
	CLEAR_ARRAY(charTypes);
	mp.clear();
	oddCntPre[0] = 1; charTypes[str[0] - 'a'] = true;
	for (register ll i = 1; i < len; ++i) {
		charTypes[str[i] - 'a'] ^= 1;
		if (charTypes[str[i] - 'a'])
			oddCntPre[i] = oddCntPre[i - 1] + 1;
		else
			oddCntPre[i] = oddCntPre[i - 1] - 1;
	}
	CLEAR_ARRAY(charTypes);
	oddCntSuf[len - 1] = 1; charTypes[str[len - 1] - 'a'] = true;
	for (register ll i = len - 2; i >= 0; --i) {
		charTypes[str[i] - 'a'] ^= 1;
		if (charTypes[str[i] - 'a'])
			oddCntSuf[i] = oddCntSuf[i + 1] + 1;
		else
			oddCntSuf[i] = oddCntSuf[i + 1] - 1;
	}
	return false;
}

void run1() {
	ull ans = 0;
	for (ll i = 2; i < len; ++i) {
		for (ll j = 2; j <= i; ++j) {
			if (i % j == 0) {
				if ((len - i) & 1)
					ans += j - 1;
				else
					ans += (j - 1) / 2;
			}
		}
	}
	printf("%llu\n", ans);
}

void prepKMP() {
	CLEAR_ARRAY(jmp);
	for (ll i = 1, j = 0; i < len; ++i) {
		while (j && str[i] != str[j])
			j = jmp[j];
		if (str[i] == str[j])
			++j;
		jmp[i + 1] = j;
	}
}

inline bool isRepeatSub(int pos, int c) {
	if (pos % c) return false;
	return pos <= jmp[pos] + pos / c;
}

inline ull cntPre(int pos, int suf) {
	if (mp.find(make_pair(pos, suf)) != mp.end())
		return mp[make_pair(pos, suf)];
	ull ans = 0;
	for (ll i = 0; i < pos; ++i)
		if (oddCntPre[i] <= suf)
			++ans;
	mp.insert(make_pair(make_pair(pos, suf), ans));
	return ans;
}

void run() {
	ull ans = 0;
	for (ll i = 2; i < len; ++i) {
		for (ll j = 2; j < i; ++j)
			if (isRepeatSub(i, j))
				ans += cntPre(i / j - 1, oddCntSuf[i]);
		ans += cntPre(i - 1, oddCntSuf[i]);
	}
	printf("%llu\n", ans);
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	readNum(n);
	while (n--) {
		if (input())
			run1();
		else {
			prepKMP();
			run();
		}
	}
	return 0;
}
