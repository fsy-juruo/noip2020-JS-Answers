#include <bits/stdc++.h>

using namespace std;
int n,m;
bool b[10003];
long long fz[10003],fm[10003];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; ++i)
	{
		fm[i]=1;
	}
	for (int i = 1; i <= m; ++i)
	{
		fz[i]=1;
	}
	for (int i = 1; i <= n; ++i)
	{
		int d;
		scanf("%d",&d);
		if (d == 0) {
		    b[i] = 1;
		    continue;
		}
		fm[i] *= d;
		while (d--)
		{
			int cnt;
			scanf("%d",&cnt);
			long long tmp2 = fm[cnt] * fm[i] / __gcd(fm[cnt],fm[i]);
			fz[cnt] = tmp2 / fm[cnt] * fz[cnt] + tmp2 / fm[i] * fz[i];
			fm[cnt] = tmp2;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!b[i])continue;
		long long tmp = __gcd(fz[i],fm[i]);
		cout << fz[i]/tmp << ' ' << fm[i]/tmp << endl;
	}
	return 0;
}
