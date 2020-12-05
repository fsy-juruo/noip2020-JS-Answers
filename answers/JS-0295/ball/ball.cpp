#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define Forn(i, n) for(int i=1; i<=(n); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define foreach(it, a) for((__typeof)(a.begin()) it=a.begin(); it!=a.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;

const int MAX=55;

int N, M, stk[MAX][405], cnt[MAX];
map<pair<vi, vi>,int> MP;
pi modif[820005];

int q_pow(int a, int b, int md)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=(1LL*ret*a)%md;
		a=1LL*a*a%md;
		b>>=1;
	}
	return ret;
}

class Hash
{
	public:
		int dat, md, pw, npw;
		Hash(int _M=1e9+7, int _b=623):md(_M), pw(_b)
		{ dat=0; npw=q_pow(pw, md-2, md);}
		void update1(int n)
		{
			dat=(1LL*dat*pw+n)%md;
		}
		void update2(int n)
		{
			dat=(dat-n+md)%md;
			dat=1LL*dat*npw%md;
		}
}H1[MAX], H2[MAX];

void rem(int ida, int idb)
{
	int bp=stk[ida][cnt[ida]--];
	stk[idb][++cnt[idb]]=bp;
	H1[ida].update2(bp);
	H2[ida].update2(bp);
	H1[idb].update1(bp);
	H2[idb].update1(bp);//add
}

int crem(int ida, int idb)
{
	if(cnt[ida]<=0) return 0;
	if(cnt[idb]>=M) return 0;
	return 1;
}

void print(int step)
{
	printf("%d\n", step);
	Forn(i, step)
		printf("%d %d\n", modif[i].f, modif[i].s);
}

void print2()
{
	puts("");
	Forn(i, N+1)
	{
		cout<<i<<";\n";
		Forn(j, cnt[i])
			cout<<stk[i][j]<<" ";
		puts("");
	}
	puts("");
}

void dfs(int step)// 820000
{
	if(step>820000) return;
	int chk=1;
	Forn(i, N)
	{
		if(cnt[i]!=M)
			chk=0;
		Forn(j, M-1) if(stk[i][j]!=stk[i][j+1])
		{
			chk=0;
			break;
		}
		if(!chk) break;
	}
//	print2();
	if(chk) print(step), exit(0);
	Forn(i, N+1) Forn(j, N+1) if(i!=j&&crem(i, j))
	{
		rem(i, j);
		vi fna, fnb;
		Forn(tt, N+1) fna.pb(H1[tt].dat), fnb.pb(H2[tt].dat);
		if(MP.find(mp(fna, fnb))==MP.end()||
		MP[mp(fna, fnb)]>step)
		{
			map<pair<vi,vi>, int> tmp=MP;
			MP[mp(fna, fnb)]=step;
			modif[step+1]=mp(i, j);
			dfs(step+1);
			MP=tmp;
			rem(j, i);
		}
	}
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &N, &M);
	Forn(i, N) 
	{
		H1[i]=Hash(1e9+7, 623);
		H2[i]=Hash(1e9+9, 59);
		Forn(j, M)
		{
			scanf("%d", &stk[i][j]);
			H1[i].update1(stk[i][j]);
			H2[i].update1(stk[i][j]);
		}
		cnt[i]=M;
	}
	dfs(0);
	return 0;
}
