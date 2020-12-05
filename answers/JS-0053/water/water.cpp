#include<bits/stdc++.h>
#define LL long long
#define MAXM 1001000
#define MAXN 1001000
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
LL gcd(LL cn, LL cm) {return cm ? gcd(cm,cn%cm) : cn; }
struct qwe{
	int a,b,ne;
	void mk(int cn, int cm, int cx) {a = cn; b = cm; ne = cx; }
};
struct Fenshu{
	LL a, b;
	void mk(LL cn, LL cm) {a = cn; b = cm; }
	void set(int cn) {a = cn; b = 1; }
	void pro() {LL lin = gcd(a,b); a/=lin; b/=lin; }
	inline friend Fenshu operator +(Fenshu A, Fenshu B) {Fenshu guo; guo.mk(A.a*B.b + A.b*B.a, A.b*B.b); guo.pro(); return guo; }
	void chu(LL cn) {b = b*cn; pro(); }
	void outit() {WriteS(a); WriteL(b); }
};
qwe a[MAXM*2+1];
int alen;
int head[MAXN+1];
int n,m;
int du[MAXN+1], chu[MAXN+1];
int dui[MAXN+1], l, r;
Fenshu zhi[MAXN+1];
void lian(int cn, int cm) {a[++alen].mk(cn,cm,head[cn]); head[cn] = alen; du[cm]++; chu[cn]++; }
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	Read(n); Read(m);
	alen = 0; memset(head,0,sizeof(head));
	memset(du,0,sizeof(du)); memset(chu,0,sizeof(chu));
	for(int i = 1;i<=n;i++)
	{
		int bx; Read(bx);
		for(int j = 1;j<=bx;j++) {int by; Read(by); lian(i,by); }
	}
	for(int i = 1;i<=m;i++) lian(n+1, i);
	zhi[n+1].set(m);
	for(int i = 1;i<=n;i++) zhi[i].set(0);
	l = r = 0;
	for(int i = 1;i<=n+1;i++) if(!du[i]) dui[++r] = i;
	while(l < r)
	{
		int dang = dui[++l];
		Fenshu lin = zhi[dang]; if(chu[dang]) lin.chu(chu[dang]);
		for(int i = head[dang];i;i = a[i].ne)
		{
			int y = a[i].b;
			du[y]--; zhi[y] = zhi[y]+lin;
			if(!du[y]) dui[++r] = y;
		}
	}
	for(int i = 1;i<=n;i++) if(!chu[i]) zhi[i].outit();
	return 0;
}

