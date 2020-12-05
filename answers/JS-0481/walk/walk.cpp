#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)

const int N = 100 + 5, MAXS = 1000 + 5;

template <typename Tp> void read(Tp &x){
	x = 0; int op = 1; char ch = getchar();
	while(!isdigit(ch)){ if(ch == '-') op = -1; ch = getchar(); }
	while(isdigit(ch)){ x = x*10+ch-'0'; ch = getchar(); } x *= op;
}
template <typename Tp> void CMax(Tp &x, Tp y){ if(y > x) x = y; }
template <typename Tp> void CMin(Tp &x, Tp y){ if(y < x) x = y; }

int n, k, w[N], c[N], d[N];
bool f[MAXS][N];

int id(int *tmp){
	int ret = 0;
	for(int i = 1; i <= k; ++ i){
		ret = ret * (w[i] - 1) + tmp[i];
	}
	return ret;
}

bool check(int *tmp){
	for(int i = 1; i <= k; ++ i){
		if(tmp[i] < 1 || tmp[i] > w[i])
			return false;
	}
	return true;
}

int ans, tt[N];

bool flag;

int calc(int *tmp){
	for(int i = 1; i <= k; ++ i) tt[i] = tmp[i];
	memset(f, 0, sizeof(f));
	int step = 0, now = 0, s1, s2;
	while(!f[id(tmp)][now]){
		s1 = id(tmp);
		tmp[c[now]] += d[now];
		f[s1][now] = 1;
		step ++; now ++; if(now == n) now = 0;
		if(!check(tmp)) break;
	}
	if(check(tmp)){
		flag = true;
		return 0;
	}
	else {
		for(int i = 1; i <= k; ++ i) tmp[i] = tt[i];
		return step;
	}
}

int tmp[N];

void chose(int step){
	if(flag) return;
	if(step == k + 1){
		ans += calc(tmp);
		return;
	}
	for(int i = 1; i <= w[step]; ++ i){
		tmp[step] = i;
		chose(step + 1);
	}
}

void solve0()
{
	chose(1);
	if(flag) printf("-1");
	else printf("%d", ans);
}


int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(n); read(k);
	for(int i = 1; i <= k; ++ i) read(w[i]);
	for(int i = 0; i < n; ++ i){
		read(c[i]); read(d[i]);
	}
	solve0();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

