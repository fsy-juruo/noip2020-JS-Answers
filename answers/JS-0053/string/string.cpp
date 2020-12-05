#include<bits/stdc++.h>
#define LL long long
#define MAXN 1501000
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
int t, n;
char c[MAXN+1];
int ne[MAXN+1];
int ge[30];
int pre[MAXN+1], suf[MAXN+1], num[30];
void getit(char c[], int &clen)
{
	while(!isalpha(c[1] = getchar())); clen = 1;
	while(isalpha(c[++clen] = getchar())); clen--;
}
void get_ne()
{
	ne[0] = 0; ne[1] = 0; int yuan = 0, wei = 0;
	for(int i = 2;i<=n;i++)
	{
		ne[i] = max(min(yuan-i+1, ne[i-wei+1]), 0);
		while(i+ne[i] <= n && c[i+ne[i]] == c[ne[i]+1]) ne[i]++;
		if(i+ne[i]-1 > yuan) yuan = i+ne[i]-1, wei = i;
	}
	ne[1] = n;
}
void zuo()
{
	getit(c, n);
	get_ne();
	memset(num,0,sizeof(num));
	int zong = 0;
	for(int i = 1;i<=n;i++)
	{
		num[c[i]-'a']++; 
		if(num[c[i]-'a']&1) zong++;
		else zong--;
		pre[i] = zong;
	}
	memset(num,0,sizeof(num)); zong = 0;
	for(int i = n;i>=1;i--) 
	{
		num[c[i]-'a']++;
		if(num[c[i]-'a']&1) zong++;
		else zong--;
		suf[i] = zong;
	}
	memset(ge,0,sizeof(ge));
	LL ans = 0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j+1<=n;j+=i)
		{
			if(i > ne[j-i+1]) break;
			ans += ge[suf[j+1]];
		}
		for(int j = pre[i];j<=26;j++) ge[j]++;
	}
	WriteL(ans);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	Read(t); while(t--) zuo();
	return 0;
}

