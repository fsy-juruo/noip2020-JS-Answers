#include<bits/stdc++.h>
#define LL long long
#define MAXN 501000
#define MAXK 11
#define MOD 1000000007
using namespace std;
template<typename T> void Read(T &cn)
{
	int c, sig = 1;
	while(!isdigit(c = getchar())) if(c == '-') sig = 0;
	if(sig) {cn = c-48; while(isdigit(c = getchar())) cn = cn*10-48+c; }
	else    {cn = 48-c; while(isdigit(c = getchar())) cn = cn*10+48-c; }
}
template<typename T> void Write(T cn)
{
	T cm = 0; int wei = 0, cx = cn%10; cn/=10;
	if(cn < 0 || cx < 0) {putchar('-'); cn = 0-cn; cx = 0-cx; }
	while(cn) wei++, cm = cm*10+cn%10, cn/=10;
	while(wei--) putchar(cm%10+48), cm/=10;
	putchar(cx+48);
}
template<typename T> void WriteL(T cn) {Write(cn); puts(""); }
template<typename T> void WriteS(T cn) {Write(cn); putchar(' '); }
template<typename T> void Max(T &cn, T cm) {cn = cn < cm ? cm : cn; }
template<typename T> void Min(T &cn, T cm) {cn = cn < cm ? cn : cm; }
int n,k;
int w[MAXK+1];
int c[MAXN+1], d[MAXN+1];
int zhan[MAXN+1], shi[MAXN+1], zlen;
int zhan1[MAXN+1], shi1[MAXN+1], zlen1;
int zhan2[MAXN+1], shi2[MAXN+1], zlen2;
namespace Sub2{
	int pan() 
	{
		for(int i = 1;i<=k;i++) if(w[i] > 1000000) return 0;
		return 1;
	}
	LL f[1001000];
	LL g[11][1001000];
	int glen;
	int dang[11];
	LL suan(int cn)
	{
		LL ans = 1;
		for(int i = 1;i<cn;i++) ans = 1ll*ans*(w[i]-dang[i]+1)%MOD;
		for(int i = cn+1;i<=k;i++) ans = 1ll*ans*(w[i]-dang[i]+1)%MOD;
		return ans;
	}
	int main()
	{
		LL INF = 1000000000;
		INF = INF*10000000;
		for(int i = 1;i<=k;i++)
		{
			zlen = 0;
			for(int j = 1;j<=n;j++) if(c[j] == i)
			{
				++zlen; zhan[zlen] = zhan[zlen-1] + d[j]; shi[zlen] = j;
			}
			zlen1 = zlen2 = 0;
			for(int j = 1;j<=zlen;j++) 
			{
				if(zhan[j] < 0) {
					if((-zhan[j]) > zhan1[zlen1]) ++zlen1, zhan1[zlen1] = -zhan[j], shi1[zlen1] = shi[j];
				}
				if(zhan[j] > 0) {
					if(zhan[j] > zhan2[zlen2]) ++zlen2, zhan2[zlen2] = zhan[j], shi2[zlen2] = shi[j];
				}
			}
			shi1[0] = shi2[0] = 0;
			for(int j = 1;j<=zlen1;j++) f[zhan1[j]] = shi1[j];
			for(int j = 1;j<=zlen2;j++) f[w[i]-zhan2[j]+1] = shi2[j];
			if(zhan[zlen] == 0) {
				for(int j = zhan1[zlen1]+1;j<=w[i]-zhan2[zlen2];j++) f[j] = INF;
			}
			else {
				int lin = zhan[zlen];
				if(lin < 0) {
					for(int j = zhan1[zlen1]+1;j<=w[i]-zhan2[zlen2];j++) f[j] = (f[j+lin]+n)%MOD;
				}
				else {
					for(int j = w[i]-zhan2[zlen2];j>=zhan1[zlen1]+1;j--) f[j] = (f[j+lin]+n)%MOD;
				}
			}
//			for(int j = 1;j<=w[i];j++) printf("f[%d] = %lld\n",j,f[j]);
			int xian1 = 1, xian2 = w[i];
			for(int j = 1;j<=w[i];j++)
			{
				if(f[xian1] < f[xian2]) g[i][j] = f[xian1++];
				else g[i][j] = f[xian2--];
			}
			if(g[i][w[i]] == INF) g[i][0] = 1;
			else g[i][0] = 0;
//			for(int j = 1;j<=w[i];j++) printf("f[%d] = %lld\n",j,g[i][j]);
		}
		int lin = 1;
		for(int i = 1;i<=k;i++) if(g[i][0] == 0) lin = 0;
		if(lin) {
			WriteL(-1); return 0;
		}
		LL ans = 0;
		for(int i = 1;i<=k;i++) dang[i] = 1, g[i][w[i]+1] = INF;
		while(1)
		{
			int xiao = 1;
			for(int j = 2;j<=k;j++) if(g[j][dang[j]] < g[xiao][dang[xiao]]) xiao = j;
			LL lin = suan(xiao); 
			if(lin == 0) break;
			ans = (ans + 1ll*g[xiao][dang[xiao]]*lin)%MOD;
			dang[xiao]++;
		}
		WriteL(ans); return 0;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	Read(n); Read(k);
	for(int i = 1;i<=k;i++) Read(w[i]);
	for(int i = 1;i<=n;i++) Read(c[i]), Read(d[i]);
	return Sub2::main();
	return 0;
}

