#include<bits/stdc++.h>
#define LL long long
#define MAXNUM 10001000
#define MAXN 60
#define MAXM 600
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
map<int, int> M;
int n,m,Mlen;
namespace Daan{
	struct Ans{
		int x, y;
		void mk(int cn, int cm) {x = cn; y = cm; }
		void outit() {WriteS(x); WriteL(y); }
	};
	Ans ans[MAXNUM+1];
	int anslen;
	int shu[MAXN+1];
	void zeng(int cn, int cm) {ans[++anslen].mk(cn,cm); }
	void outit()
	{
//		memset(shu,0,sizeof(shu));
//		for(int i = 1;i<=n;i++) shu[i] = m;
//		for(int i = 1;i<=anslen;i++) 
//		{
//			if(shu[ans[i].x] <= 0 || shu[ans[i].y] >= m) {cerr<<"error"<<i<<endl; while(1); }
//			shu[ans[i].x]--; shu[ans[i].y]++;
//		}
		WriteL(anslen);
		for(int i = 1;i<=anslen;i++) ans[i].outit();
	}
	void qing() {anslen = 0; }
}
int col[MAXN+1][MAXM+1];
int shu[MAXN+1][MAXN+1];
int bu[MAXN+1];
int guo[MAXN+1], mu[MAXN+1];
int tmp_shu[MAXN+1];
int zhan[MAXN+1], zhi[MAXN+1];
int Cmp(int cn, int cm) {return zhi[cn] > zhi[cm]; }
void yidong(int cn, int cm) 
{
//	if(col[cn][0] <= 0 || col[cm][0] >= m) {cerr<<"e"<<endl; while(1); }
	Daan::zeng(cn, cm); int lin = col[cn][col[cn][0]]; shu[cm][lin]++; shu[cn][lin]--; 
	col[cm][col[cm][0]+1] = col[cn][col[cn][0]]; 
	col[cm][0]++; col[cn][0]--;
}
int get_bu(int cn) {for(int i = 1;i<=m;i++) if(col[cn][i] != guo[cn]) return i; return m+1; }
void yuchu()
{
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++) shu[i][j] = 0;
		for(int j = 1;j<=m;j++) shu[i][col[i][j]]++;
	}
	for(int i = 1;i<=n;i++) mu[i] = 0, guo[i] = 0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++) zhan[j] = j, zhi[j] = shu[j][i];
		sort(zhan+1, zhan+n+1, Cmp);
		for(int j = 1;j<=n;j++) if(!guo[zhan[j]])
		{
			guo[zhan[j]] = i; mu[i] = zhan[j]; break;
		}
	}
	Daan::qing();
	for(int i = 1;i<=n;i++) bu[i] = get_bu(i);
//	for(int i = 1;i<=n;i++)
//	{
//		printf("bu[%d] = %d\n",i,bu[i]);
//		printf("guo[%d] = %d\n",i,guo[i]);
//	}
}
void zheng(int cn, int cm)
{
	int lin1 = bu[cn];
	for(int i = m;i>=lin1;i--) yidong(cn, n+1);
//	printf("in zheng : cn = %d cm = %d lin1 = %d %d\n",cn,cm,lin1,Daan::anslen);
	int zhuan = 0;
//	printf("col[n+1][0] = %d %d %d %d\n",col[n+1][0],col[n+1][col[n+1][0]],guo[cn],m);
	for(int i = m;i>=1;i--)
	{
//		int chu = Daan::anslen >= 600 && Daan::anslen <= 620;
//		if(chu) printf("i = %d %d\n",i,Daan::anslen);
		if(col[cm][i] == guo[cn]) {
			zhuan++;
			if(col[n+1][0] == m) {
				if(col[n+1][m] == guo[cn]) break;
				if(col[cn][0] == m) break;
				yidong(n+1, cn); yidong(cm, n+1);
//				break;
			}
			else yidong(cm, n+1);
		}
		else {
			if(zhuan >= lin1) break;
//			if(chu) printf("in case2 %d %d\n",col[cn][0],col[cm][0]);
			if(col[cn][0] == m) break;
//			printf("1\n");
			if(!shu[cm][guo[cn]]) break;
//			printf("2\n");
			yidong(cm, cn);
		}
	}
//	printf("col[n+1][0] = %d %d %d\n",col[n+1][0],col[n+1][col[n+1][0]],guo[cn]);
	while(col[cn][0] >= lin1) yidong(cn, cm);
	while(col[n+1][0]) 
	{
		if(col[n+1][col[n+1][0]] == guo[cn]) {
			if(col[cn][0] != m) yidong(n+1, cn);
			else yidong(n+1, cm);
		}
		else {
			if(col[cm][0] != m) yidong(n+1, cm);
			else yidong(n+1, cn);
		}
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	Read(n); Read(m); 
	M.clear();
	for(int i = 1;i<=n;i++) {for(int j = 1;j<=m;j++) Read(col[i][j]); col[i][0] = m; }
	col[n+1][0] = 0;
	Mlen = 0;
	for(int i = 1;i<=n;i++) for(int j = 1;j<=m;j++)
	{
		if(M.find(col[i][j]) == M.end()) M[col[i][j]] = ++Mlen;
		col[i][j] = M[col[i][j]];
//		printf("col[%d][%d] = %d\n",i,j,col[i][j]);
	}
	yuchu();
	while(1)
	{
		int answ = 1, ansz = bu[1];
		for(int i = 2;i<=n;i++) 
		{
			int lin = bu[i];
			if(lin < ansz) ansz = lin, answ = i;
		}
		if(ansz > m) break;
		int answ2 = 1, ansz2 = shu[1][guo[answ]];
		if(answ == 1) answ2 = 2, ansz2 = shu[2][guo[answ]];
		for(int i = 2;i<=n;i++) if(i != answ)
		{
			int lin = shu[i][guo[answ]];
			if((lin && lin > ansz2) || !ansz2) ansz2 = lin, answ2 = i;
		}
//		printf("ansz = %d ansz2 = %d\n",ansz,ansz2);
		zheng(answ, answ2);
		tmp_shu[answ]++;
//		printf("%d %d\n",bu[answ],bu[answ2]);
		bu[answ] = get_bu(answ); bu[answ2] = get_bu(answ2);
//		printf("%d %d\n",bu[answ],bu[answ2]);
//		printf("zheng : answ = %d answ2 = %d\n",answ,answ2);
//		for(int i = 1;i<=n;i++) {for(int j = 1;j<=m;j++) printf("%d ",col[i][j]); puts(""); }
//		while(!isalpha(getchar()));
	}
//	for(int i = 1;i<=n;i++) cerr<<i<<' '<<tmp_shu[i]<<endl;
	Daan::outit();
//	cerr<<Daan::anslen<<endl;
	return 0;
}

