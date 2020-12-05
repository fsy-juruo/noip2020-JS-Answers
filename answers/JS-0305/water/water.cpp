#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m, s, ind[MAXN];
vector <int> to[MAXN];
int q[MAXN], ft, bk;
int fuck[MAXN], bbkk;
struct node{
    long long fz, fm;
}dp[MAXN];

long long gcd(long long x, long long y)
{
    if (x == 0) return y;
    return gcd(y % x, x);
}

long long lcm(long long x, long long y)
{
    return x * y / gcd(x, y);
}

int main()
{
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++) {
	int t;
	scanf("%d", &t);
	if (!t) {
	    fuck[++bbkk] = i;
	    continue;
	}
	for (int j = 1; j <= t; j++) {
	    int x;
	    scanf("%d", &x);
	    to[i].push_back(x);
	    ind[x]++;
	}
    }
    for (int i = 1; i <= s; i++) q[++bk] = i, dp[i].fz = 1, dp[i].fm = 1;
    for (int i = s + 1; i <= n; i++) dp[i].fm = 1;
    while (ft < bk) {
	int x = q[++ft];
	long long up = dp[x].fz, down = dp[x].fm * to[x].size();
	long long tmp = gcd(up, down);
	up /= tmp; down /= tmp;
	//cout << "//" << x << ' ' << up << ' ' << down << to[x].size() << endl; 
	for (unsigned int i = 0; i < to[x].size(); i++) {
	    int v = to[x][i];
	    long long fm = dp[v].fm, fz = dp[v].fz;
	    long long ccf = lcm(down, fm);
	    long long n1 = ccf / down * up + ccf / fm * fz;
	    long long tmp1 = gcd(n1, ccf);
	    dp[v].fz = n1 / tmp1, dp[v].fm = ccf / tmp1;
	    ind[v]--;
	    if (!ind[v]) q[++bk] = v;
	    //cout << v << ' ' << dp[v].fz <<' ' << dp[v].fm << endl;
	}
    }
    for (int i = 1; i <= bbkk; i++) {
	printf("%lld %lld\n", dp[fuck[i]].fz, dp[fuck[i]].fm);
    }
    return 0;
}
