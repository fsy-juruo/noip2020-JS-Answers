#include<bits/stdc++.h>
using namespace std;
char s[33000];
inline long long g(int x)
{
	int i;
	long long re = 0;
	for(i = 1; i*i < x; ++i)
		if(x%i == 0)
			re += (i-1) + (x/i-1);
	if(i*i == x) re += i-1;
	return re;
}
inline long long ph(int x)
{
	int i;
	long long re = 0;
	for(i = 1; i*i < x; ++i)
		if(x%i == 0)
			re += (i-1)/2 + (x/i-1)/2;
	if(i*i == x) re += (i-1)/2;
	return re;
}
long long sgm(int l)
{
	long long re = 0;
	for(int i = 2; i <= l -1; ++i)
	#define f(i) (((l-i)&1)? g(i):ph(i))
		re += f(i);
	return re;
}
int hsh[33000][26], ctt[33000];
const int bas = 233;
unsigned long long H[33000], B[33000];
inline void add(long long &re, int l, int all, int cnt)
{
	int L = l;
	unsigned long long chec , ml = B[l-1], pl;
	chec = pl = H[l-1];
	while(L <= all)
	{
		if(H[L-1] != chec) return;
		chec = chec*ml+pl;
		L += l;
	}
	for(int A = 0; A < l-1; ++A)
		if(ctt[A] <= cnt) ++re;
}
int main(void)
{
	B[0] = bas;
	for(int i = 1; i < 33000; ++i)
		B[i] = B[i-1]*bas;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		int len = strlen(s);
		bool flg = true;
		for(int i = 1; i < len; ++i)
			flg &= (s[i] == s[i-1]);
		if(flg)
		{
			printf("%lld\n", sgm(len));
			continue;
		}
		memset(ctt, 0, sizeof ctt);
		memset(hsh, 0, sizeof hsh);
		++hsh[0][s[0]-'a'];
		for(int i = 1; i < len; ++i)
		{
			for(int c = 0; c < 26; ++c)
				hsh[i][c] = hsh[i-1][c];
			++hsh[i][s[i]-'a'];
		}
		for(int i = 0; i < len; ++i)
			for(int c = 0; c < 26; ++c)
				ctt[i] += (hsh[i][c]&1);
		H[0] = s[0];
		for(int i = 1; i < len; ++i)
			H[i] = H[i-1]*bas + s[i];
		
		long long ans = 0;
		for(int bgn = 2; bgn <= len-1; ++bgn)
		{
			int cnt = 0;
			for(int i = 0; i < 26; ++i)
				if((hsh[len-1][i] - hsh[bgn-1][i]) & 1) ++cnt;
			int s;
			for(s = 1; s*s < bgn; ++s)
				if(bgn%s == 0)
					add(ans, s, bgn, cnt), add(ans, bgn/s, bgn, cnt);
			if(s*s == bgn) add(ans, s, bgn, cnt);
//			cout << "bgn = " << bgn << "; ans = "<< ans << endl;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
