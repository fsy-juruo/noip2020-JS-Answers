#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

const int RAD = 1e9;
struct bigint
{
	int dat[4];
	bigint(int x = 0)
	{
		rep(i, 4) dat[i] = 0;
		dat[0] = x;
	}
	bigint(const bigint& oth)
	{
		rep(i, 4) dat[i] = oth.dat[i];
	}
};
bigint operator+(const bigint& A, const bigint& B)
{
	bigint ret;
	int car = 0;
	rep(i, 4) {
		int cd = A.dat[i] + B.dat[i] + car;
		car = cd >= RAD;
		ret.dat[i] = cd - car * RAD;
	}
	return ret;
}
bigint operator*(const bigint& A, int B)
{
	bigint ret;
	int car = 0;
	rep(i, 4) {
		LL cd = 1LL * A.dat[i] * B + car;
		car = cd / RAD;
		ret.dat[i] = cd - 1LL * car * RAD;
	}
	return ret;
}
int operator%(const bigint& A, int B)
{
	int ret = 0;
	for(int i = 3; i >= 0; i --)
	ret = (1LL * RAD * ret + A.dat[i]) % B;
	return ret;
}
bigint operator/(const bigint& A, int B)
{
	bigint ret;
	int car = 0;
	for(int i = 3; i >= 0; i --) {
		LL cd = 1LL * car * RAD + A.dat[i];
		ret.dat[i] = cd / B;
		car = cd % B;
	}
	return ret;
}

bigint LCM;
int n, m, d[100005], to[100005][6];
int ind[100005], ord[100005], cnt;
bigint dp[100005];

void outp(const bigint& A)
{
	int pos = 3;
	for(; pos > 0 && A.dat[pos] == 0; pos --) ;
	printf("%d", A.dat[pos]);
	for(pos --; pos >= 0; pos --) printf("%09d", A.dat[pos]);
}

void pfrac(bigint A)
{
	bigint B = LCM;
	for(int i = 65536; i >= 2; i = sqrt(i + 0.5))
	while(A % i == 0 && B % i == 0) {
		A = A / i; B = B / i;
	}
	for(int i = 43046721; i >= 3; i = sqrt(i + 0.5))
	while(A % i == 0 && B % i == 0) {
		A = A / i; B = B / i;
	}
	for(int i = 390625; i >= 5; i = sqrt(i + 0.5))
	while(A % i == 0 && B % i == 0) {
		A = A / i; B = B / i;
	}
	
	outp(A); putchar(' ');
	outp(B); putchar('\n');
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	LCM = 1;
	rep(i, 12) LCM = LCM * 60;
	
	scanf("%d%d", &n, &m);
	rep1(i, n) {
		scanf("%d", &d[i]);
		rep(j, d[i]) {
			scanf("%d", &to[i][j]);
			ind[to[i][j]] ++;
		}
	}
	
	rep1(i, n) if(ind[i] == 0) ord[cnt ++] = i;
	rep(i, cnt) {
		int v = ord[i];
		if(v <= m) dp[v] = LCM;
		rep(j, d[v]) {
			int u = to[v][j];
			ind[u] --;
			if(ind[u] == 0) ord[cnt ++] = u;
			dp[u] = dp[u] + dp[v] / d[v];
		}
	}
	
	rep1(i, n) if(d[i] == 0) pfrac(dp[i]);
	return 0;
}
