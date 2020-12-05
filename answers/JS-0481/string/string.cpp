#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)

const int N = 1100000 + 10;

template <typename Tp> void read(Tp &x){
	x = 0; int op = 1; char ch = getchar();
	while(!isdigit(ch)){ if(ch == '-') op = -1; ch = getchar(); }
	while(isdigit(ch)){ x = x*10+ch-'0'; ch = getchar(); } x *= op;
}
template <typename Tp> void CMax(Tp &x, Tp y){ if(y > x) x = y; }
template <typename Tp> void CMin(Tp &x, Tp y){ if(y < x) x = y; }

int T;

char s[N];
int n;

int cnt[30], res, pre[N], suf[N];
int fail[N];

void add(int x){
	cnt[s[x] - 'a'] ++;
	if(cnt[s[x] - 'a'] & 1) res ++;
	else res --;
}

long long ans;

struct Node{ int ls, rs, dat; } t[N * 6];
int rt[N], node;

#define mid ((l + r) >> 1)

void modify(int &x, int l, int r, int pos){
	t[++ node] = t[x]; x = node; t[x].dat ++;
	if(l == r) return;
	if(pos <= mid) modify(t[x].ls, l, mid, pos);
	else modify(t[x].rs, mid + 1, r, pos);
}
int Query(int x, int l, int r, int pos){
	if(l == r) return t[x].dat;
	if(pos <= mid) return Query(t[x].ls, l, mid, pos);
	else return t[t[x].ls].dat + Query(t[x].rs, mid + 1, r, pos);
}
#undef mid

void Work(){
	scanf("%s", s + 1); n = strlen(s + 1);
	
	memset(cnt, 0, sizeof(cnt)); res = 0;
	node = 0; rt[0] = 0;
	for(int i = 1; i <= n; ++ i){
		add(i), pre[i] = res;
		rt[i] = rt[i - 1];
		modify(rt[i], 0, 26, pre[i]);
	}
	memset(cnt, 0, sizeof(cnt)); res = 0;
	for(int i = n; i >= 1; -- i) add(i), suf[i] = res;
	
	fail[1] = 0;
	for(int i = 2, j = 0; i <= n; ++ i){
		while(j && s[j + 1] != s[i]) j = fail[j];
		if(s[j + 1] == s[i]) j ++;
		fail[i] = j;
	}
	
	ans = 0;
	
	for(int len = 2; len < n; ++ len){
		ans += Query(rt[len - 1], 0, 26, suf[len + 1]);
		for(int l = len + len; l < n; l += len){
			int z = l - fail[l];
			if(len % z == 0){
				ans += Query(rt[len - 1], 0, 26, suf[l + 1]);
			}
		}
	}
	
	printf("%lld\n", ans);
}


int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	read(T);
	while(T -- ) Work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

