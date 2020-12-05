#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define N (int) 1500000

using namespace std;
int input () {
	int x = 0, f = 0;
	char c = getchar ();
	while (c < '0' || c > '9') f = c == '-', c = getchar ();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar ();
	return f ? - x : x;
}

int T;

int n;
char c[N];

int fc[N];

struct Bit {
	ll val[30];
	int lowbit (int x) {
		return x & (- x);
	}
	void update (int pos, ll delta) {
		while (pos <= 27) val[pos] += delta, pos += lowbit (pos);
	}
	ll query (int pos) {
		ll ret = 0;
		while (pos) ret += val[pos], pos -= lowbit (pos);
		return ret;
	}
	void init () {
		memset (val, 0, sizeof (val));
	}
}bit;

const ull hash1 = 19260817, hash2 = 1000000007;
ull h1[N], h2[N];
ull w1[N], w2[N];

bool check (int x, int y) {
	ull tmp1 = h1[y] - h1[y-x] * w1[x], tmp2 = h2[y] - h2[y-x] * w2[x];
	return h1[x] == tmp1 && h2[x] == tmp2;
}

void init () {
	bit.init ();
	n = 0;
	memset (fc, 0, sizeof (fc));
	memset (h1, 0, sizeof (h1));
	memset (h2, 0, sizeof (h2));
}

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	T = input ();
	
	w1[0] = w2[0] = 1;
	for (int i = 1; i <= (1<<20)+10; i ++) w1[i] = w1[i-1] * hash1, w2[i] = w2[i-1] * hash2;
	
	while (T --) {
		init ();
		
		scanf ("%s", c+1);
		n = strlen (c+1);
		
		int st = 0;
		for (int i = n; i >= 1; i --) {
			if (st & (1 << (c[i]-'a'))) fc[i] = fc[i+1] - 1;
			else fc[i] = fc[i+1] + 1;
			st ^= (1 << (c[i]-'a'));
		}
//		for (int i = 1; i <= n; i ++) cout << nxt[i] << endl;
		
		for (int i = 1; i <= n; i ++) h1[i] = h1[i-1] * hash1 + (c[i]-'a'), h2[i] = h2[i-1] * hash2 + (c[i]-'a');
		
		st = 0;
		int fa = 0;
		ll ans = 0;
		for (int i = 2; i < n; i ++) {
			if (st & (1 << (c[i-1]-'a'))) fa --;
			else fa ++;
			st ^= (1 << (c[i-1]-'a'));
			bit.update (fa+1, 1);
//			cout << fa << endl;
//			cout << i << ": ";
			for (int pos = i; pos < n; pos += i) {
				if (! check (i, pos)) break;
				ans += bit.query (fc[pos+1]+1);
//				cout << pos << " ";
			}
//			cout << endl;
		}
		
		printf ("%lld\n", ans);
	}
	
	return 0;	
}
