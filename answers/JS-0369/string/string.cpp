#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD1 = 1e9 + 7, MOD2 = 9999991;
const int maxn = 5e5 + 10, A = 26, SIZE = maxn * 20;

struct node {
	ll a, b;
} sh[maxn];

ll pow261[maxn], pow262[maxn];

node gethash(int l, int r){
	node re;
	re.a = (sh[r].a - sh[l - 1].a * pow261[r - l + 1] % MOD1 + MOD1) % MOD1;
	re.b = (sh[r].b - sh[l - 1].b * pow262[r - l + 1] % MOD2 + MOD2) % MOD2;
	return re;
}

bool check(node a, node b){
	return a.a == b.a && a.b == b.b;
}

int n;
int s[A];
char ch[maxn];
int as[maxn], cs[maxn];
bool f[maxn];

int sum[SIZE], lc[SIZE], rc[SIZE], root[maxn], tot;
int frm[maxn], nxt[maxn], val[maxn], Head, Tail;

inline void pushin(int c){
	if (Tail) nxt[Tail] = ++Tail; else ++Tail;
	frm[Tail] = Tail - 1;
	nxt[Tail] = 0;
	val[Tail] = c;
}

inline void remove(int x){
	if (x == Head){
		Head = nxt[Head];
		frm[Head] = 0;
		return;
	}
	if (x == Tail){
		Tail = frm[Tail];
		nxt[Tail] = 0;
		return;
	}
	nxt[frm[x]] = nxt[x];
	frm[nxt[x]] = frm[x];
}

void build(int &f1, int f2, int l, int r, int x){
	if (!f1) f1 = ++tot;
	if (l == r){
		sum[f1] = sum[f2] + 1;
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid){
		build(lc[f1], lc[f2], l, mid, x);
		rc[f1] = rc[f2];
	} else {
		build(rc[f1], rc[f2], mid + 1, r, x);
		lc[f1] = lc[f2];
	}
	sum[f1] = sum[lc[f1]] + sum[rc[f1]];
}

int query(int f, int l, int r, int x){
	if (r <= x) return sum[f];
	int mid = l + r >> 1, re = 0;
	if (x > mid) re = query(rc[f], mid + 1, r, x);
	return re + query(lc[f], l, mid, x);
}

void Init(){
	memset(root, 0, sizeof root);
	memset(as, 0, sizeof as);
	memset(cs, 0, sizeof cs);
	memset(sum, 0, sizeof sum);
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	pow261[0] = pow262[0] = 1;
	for (int i = 1; i < maxn; i++){
		pow261[i] = pow261[i - 1] * 26 % MOD1;
		pow262[i] = pow262[i - 1] * 26 % MOD2;
	}
	int T;
	scanf("%d", &T);
	while (T--){
		Init();
		scanf("%s", ch + 1);
		n = strlen(ch + 1);
		for (int i = 1, idx; i <= n; i++){
			idx = ch[i] - 'a';
			sh[i].a = (sh[i - 1].a * 26 + idx) % MOD1;
			sh[i].b = (sh[i - 1].b * 26 + idx) % MOD2;
		}
		for (int i = 0; i < A; i++) s[i] = 0;
		for (int i = n, idx; i >= 1; i--){
			idx = ch[i] - 'a';
			s[idx]++;
			if (s[idx] & 1) cs[i] = cs[i + 1] + 1; else cs[i] = cs[i + 1] - 1;
		}
		for (int i = 0; i < A; i++) s[i] = 0;
		for (int i = 1, idx; i <= n; i++){
			idx = ch[i] - 'a';
			s[idx]++;
			if (s[idx] & 1) as[i] = as[i - 1] + 1; else as[i] = as[i - 1] - 1;
			build(root[i], root[i - 1], 0, n, as[i]);
		}
		int ans = 0;
		memset(f, 0, sizeof f);
		Head = 1; Tail = 0;
		for (int i = 2; i < n; i++){
			pushin(i);
			for (int j = Head, len; j; j = nxt[j]){
				len = val[j];
				if (f[val[j]]){
					remove(j);
					continue;
				}
				//if (len * len > i) break;
				if (i % len) continue;
				if (check(gethash(i - len + 1, i), sh[len]))
					ans += query(root[len - 1], 0, n, cs[i + 1]);
				else remove(j);
				/*
				if (len * len == i) continue;
				len = i / len;
				if (check(gethash(i - len + 1, i), sh[len]))
					ans += query(root[len - 1], 0, n, cs[i + 1]);
				else f[len] = 1;
				*/
			}
//			printf("%d %d\n", i, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
